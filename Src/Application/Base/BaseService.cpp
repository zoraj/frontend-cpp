#include "BaseService.h"


BaseService::BaseService(QObject *parent): QObject(parent)
{

}

BaseService::BaseService(const QString &apiKey, const QString &token): apiKey(apiKey), bearerToken(token)
{

}

QString BaseService::fullPath(const QString &method) const
{
    return Constant::WS_ROOT_URL + method;
}

void BaseService::executeRequest(const HttpRequest &request)
{
    if (endpoint == Constant::WSEndpoint::UNKNOWN) {
        qDebug() << "Looks like no endpoint set";
    }

    timer.start();
    qDebug() << "Http request: " << request.url;
    HttpRequestInput input(request.url, request.method);
    input.apiKey = request.apiKey;
    input.bearerToken = request.bearerToken;

    if (request.method == "POST" || request.method == "PUT") {
        QJsonDocument doc(*request.payload);
        QByteArray s = doc.toJson();
        input.payload = s;
        qDebug() << "With payload: " << qPrintable(s) ;
    }

    HttpUtil *worker = new HttpUtil(this); // TODO Memory leaks
    connect(worker, SIGNAL(onExecutionFinished(HttpUtil*)), this, SLOT(handleResult(HttpUtil*)));
    worker->execute(&input);
}

void BaseService::executeRequest(const HttpRequestForArray &request)
{
    if (endpoint == Constant::WSEndpoint::UNKNOWN) {
        qDebug() << "Looks like no endpoint set";
    }

    timer.start();
    qDebug() << "Http request: " << request.url;
    HttpRequestInput input(request.url, request.method);
    input.apiKey = request.apiKey;
    input.bearerToken = request.bearerToken;

    if (request.method == "POST" || request.method == "PUT") {
        QJsonDocument doc(*request.payload);
        QByteArray s = doc.toJson();
        input.payload = s;
        qDebug() << "With payload: " << qPrintable(s) ;
    }

    HttpUtil *worker = new HttpUtil(this); // TODO Memory leaks
    connect(worker, SIGNAL(onExecutionFinished(HttpUtil*)), this, SLOT(handleResult(HttpUtil*)));
    worker->execute(&input);
}


void BaseService::handleResult(HttpUtil *httpUtil)
{
    QByteArray payload;
    int status;
    int elapsedTime = timer.elapsed();
    QByteArray response = httpUtil->response;
     status = httpUtil->httpStatusCode;
#ifdef QT_DEBUG
    qDebug() << "Http request result: " << elapsedTime << " milliseconds - " << response.size() << " bytes" ;
    qDebug() << qPrintable(response);
#endif
    callback(endpoint, response, status);
}

void BaseService::callback(Constant::WSEndpoint endpoint, const QByteArray &response, int status)
{
    qDebug() << "Http status code : " << status;
    qDebug() <<  response;
}
