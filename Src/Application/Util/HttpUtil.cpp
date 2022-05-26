#include "HttpUtil.h"

HttpRequestInput::HttpRequestInput()
{
    initialize();
}

HttpRequestInput::HttpRequestInput(QString v_url_str, QString v_http_method)
{
    initialize();
    urlStr = v_url_str;
    httpMethod = v_http_method;
}

void HttpRequestInput::initialize()
{
    varLayout = NOT_SET;
    urlStr = "";
    payload = nullptr;
    apiKey = "";
}

void HttpRequestInput::addVar(QString key, QString value)
{
    vars[key] = value;
}

void HttpRequestInput::addFile(QString variable_name, QString local_filename, QString request_filename, QString mime_type)
{
    HttpRequestInputFileElement file;
    file.variableName = variable_name;
    file.localFilename = local_filename;
    file.requestFilename = request_filename;
    file.mimeType = mime_type;
    files.append(file);
}


HttpUtil::HttpUtil(QObject *parent)
    : QObject(parent), manager(nullptr)
{
    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(onManagerFinished(QNetworkReply*)));
}

QString HttpUtil::httpAttributeEncode(QString attribute_name, QString input)
{
    // result structure follows RFC 5987
    bool need_utf_encoding = false;
    QString result = "";
    QByteArray input_c = input.toLocal8Bit();
    char c;
    for (int i = 0; i < input_c.length(); i++) {
        c = input_c.at(i);
        if (c == '\\' || c == '/' || c == '\0' || c < ' ' || c > '~') {
            // ignore and request utf-8 version
            need_utf_encoding = true;
        }
        else if (c == '"') {
            result += "\\\"";
        }
        else {
            result += c;
        }
    }

    if (result.length() == 0) {
        need_utf_encoding = true;
    }

    if (!need_utf_encoding) {
        // return simple version
        return QString("%1=\"%2\"").arg(attribute_name, result);
    }

    QString result_utf8 = "";
    for (int i = 0; i < input_c.length(); i++) {
        c = input_c.at(i);
        if (
            (c >= '0' && c <= '9')
            || (c >= 'A' && c <= 'Z')
            || (c >= 'a' && c <= 'z')
        ) {
            result_utf8 += c;
        }
        else {
            result_utf8 += "%" + QString::number(static_cast<unsigned char>(input_c.at(i)), 16).toUpper();
        }
    }

    // return enhanced version with UTF-8 support
    return QString("%1=\"%2\"; %1*=utf-8''%3").arg(attribute_name, result, result_utf8);
}

void HttpUtil::execute(HttpRequestInput *input)
{

    QByteArray requestContent = "";
    response = "";
    errorType = QNetworkReply::NoError;
    errorStr = "";

    // decide on the variable layout
    if (input->files.length() > 0) {
        input->varLayout = MULTIPART;
    }
    if (input->varLayout == NOT_SET) {
        input->varLayout = input->httpMethod == "GET" || input->httpMethod == "HEAD" ? ADDRESS : URL_ENCODED;
    }

    // prepare request content

    QString boundary = "";

    if (input->varLayout == ADDRESS || input->varLayout == URL_ENCODED) {
        // variable layout is ADDRESS or URL_ENCODED
        if (input->vars.count() > 0) {
            bool first = true;
            foreach (QString key, input->vars.keys()) {
                if (!first) {
                    requestContent.append("&");
                }
                first = false;

                requestContent.append(QUrl::toPercentEncoding(key));
                requestContent.append("=");
                requestContent.append(QUrl::toPercentEncoding(input->vars.value(key)));
            }

            if (input->varLayout == ADDRESS) {
                input->urlStr += "?" + requestContent;
                requestContent = "";
            }
        }
    }
    else {
        // variable layout is MULTIPART
        boundary = "__-----------------------"
            + QString::number(QDateTime::currentDateTime().toTime_t())
            + QString::number(qrand());
        QString boundary_delimiter = "--";
        QString new_line = "\r\n";

        // add variables
        foreach (QString key, input->vars.keys()) {
            // add boundary
            requestContent.append(boundary_delimiter);
            requestContent.append(boundary);
            requestContent.append(new_line);

            // add header
            requestContent.append("Content-Disposition: form-data; ");
            requestContent.append(httpAttributeEncode("name", key));
            requestContent.append(new_line);
            requestContent.append("Content-Type: text/plain");
            requestContent.append(new_line);

            // add header to body splitter
            requestContent.append(new_line);

            // add variable content
            requestContent.append(input->vars.value(key));
            requestContent.append(new_line);
        }

        // add files
        for (QList<HttpRequestInputFileElement>::iterator file_info = input->files.begin(); file_info != input->files.end(); file_info++) {
            QFileInfo fi(file_info->localFilename);

            // ensure necessary variables are available
            if (
                file_info->localFilename == nullptr || file_info->localFilename.isEmpty()
                || file_info->variableName == nullptr || file_info->variableName.isEmpty()
                || !fi.exists() || !fi.isFile() || !fi.isReadable()
            ) {
                // silent abort for the current file
                continue;
            }

            QFile file(file_info->localFilename);
            if (!file.open(QIODevice::ReadOnly)) {
                // silent abort for the current file
                continue;
            }

            // ensure filename for the request
            if (file_info->requestFilename == nullptr || file_info->requestFilename.isEmpty()) {
                file_info->requestFilename = fi.fileName();
                if (file_info->requestFilename.isEmpty()) {
                    file_info->requestFilename = "file";
                }
            }

            // add boundary
            requestContent.append(boundary_delimiter);
            requestContent.append(boundary);
            requestContent.append(new_line);

            // add header
            requestContent.append(QString("Content-Disposition: form-data; %1; %2").arg(
                httpAttributeEncode("name", file_info->variableName),
                httpAttributeEncode("filename", file_info->requestFilename)
            ));
            requestContent.append(new_line);

            if (file_info->mimeType != nullptr && !file_info->mimeType.isEmpty()) {
                requestContent.append("Content-Type: ");
                requestContent.append(file_info->mimeType);
                requestContent.append(new_line);
            }

            requestContent.append("Content-Transfer-Encoding: binary");
            requestContent.append(new_line);

            // add header to body splitter
            requestContent.append(new_line);

            // add file content
            requestContent.append(file.readAll());
            requestContent.append(new_line);

            file.close();
        }

        // add end of body
        requestContent.append(boundary_delimiter);
        requestContent.append(boundary);
        requestContent.append(boundary_delimiter);
    }


    // prepare connection

    QNetworkRequest request = QNetworkRequest(QUrl(input->urlStr));
    request.setRawHeader("User-Agent", "MMC Client");
    if (input->bearerToken != nullptr) {
        QString headerData = "Bearer " + input->bearerToken.toUtf8();
        request.setRawHeader("Authorization", headerData.toUtf8());
    }

    if (input->varLayout == URL_ENCODED) {
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    }
    else if (input->varLayout == MULTIPART) {
        request.setHeader(QNetworkRequest::ContentTypeHeader, "multipart/form-data; boundary=" + boundary);
    }

    QByteArray postDataSize = QByteArray::number(input->payload.size());
    QByteArray tmp_byte;
    if (input->apiKey != "" && input->apiKey != nullptr) {
        tmp_byte.insert(0, input->apiKey);
        request.setRawHeader("x-api-key",tmp_byte);
    }

    request.setRawHeader("X-Custom-User-Agent", "MAT");
    request.setRawHeader("Content-Type", "application/json");
    request.setRawHeader("Content-Length", postDataSize);


    if (input->httpMethod == "GET") {
        manager->get(request);
    }
    else if (input->httpMethod == "POST" && input->payload != nullptr) {
        manager->post(request,input->payload);
    }
    else if (input->httpMethod == "PUT") {
        manager->put(request, input->payload);
    }
    else if (input->httpMethod == "PATCH") {
        manager->sendCustomRequest(request, "PATCH", input->payload);
        QNetworkReply *sendCustomRequest(const QNetworkRequest &request, const QByteArray &verb, const QByteArray &data);
    }
    else if (input->httpMethod == "HEAD") {
        manager->head(request);
    }
    else if (input->httpMethod == "DELETE") {
        manager->deleteResource(request);
    }
    else {
        QBuffer buff(&requestContent);
        manager->sendCustomRequest(request, input->httpMethod.toLatin1(), &buff);
    }

}

void HttpUtil::onManagerFinished(QNetworkReply *reply)
{
    errorType = reply->error();

    switch (errorType) {
    case QNetworkReply::NoError:
        httpStatusCode = constant::HttpStatusCode::OK;
        break;
    case QNetworkReply::ContentNotFoundError:
        httpStatusCode = constant::HttpStatusCode::NotFound;
        break;
    case QNetworkReply::HostNotFoundError:
        httpStatusCode = constant::HttpStatusCode::HostNotFound;
        break;
    default:
        httpStatusCode = constant::HttpStatusCode::InternalServerError;
        break;
    }

    //httpStatusCode = reply->NetworkError;
    //qDebug() << "HTTP RETURN :" + QString::number(reply->error());
    if (errorType == QNetworkReply::NoError) {
        response = reply->readAll();
    }
    else {
        errorStr = reply->errorString();
        qDebug() << "Something went wrong on HttpUtil - " << errorStr;
    }

    reply->deleteLater();

    emit onExecutionFinished(this);
}

