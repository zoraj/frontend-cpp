#pragma once

#include <QObject>
#include <QString>
#include <QMap>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QDateTime>
#include <QUrl>
#include <QFileInfo>
#include <QBuffer>
#include <QHttpPart>
#include <QTimer>

#include "Constant.h"

enum HttpRequestVarLayout {NOT_SET, ADDRESS, URL_ENCODED, MULTIPART};

class HttpRequestInputFileElement {

public:
    QString variableName;
    QString localFilename;
    QString requestFilename;
    QString mimeType;

};


class HttpRequestInput {
public:
    QString urlStr;
    QString httpMethod;
    HttpRequestVarLayout varLayout;
    QMap<QString, QString> vars;
    QList<HttpRequestInputFileElement> files;
    QString apiKey;
    QString bearerToken;

    HttpRequestInput();
    HttpRequestInput(QString v_url_str, QString v_http_method);
    void initialize();
    void addVar(QString key, QString value);
    void addFile(QString variable_name, QString local_filename, QString request_filename, QString mime_type);
    QByteArray payload;
};


class HttpUtil : public QObject {
    Q_OBJECT

public:
    QByteArray response;
    QString errorStr;
    int httpStatusCode;

    explicit HttpUtil(QObject *parent = nullptr);

    QString httpAttributeEncode(QString attribute_name, QString input);
    void execute(HttpRequestInput *input);

signals:
    void onExecutionFinished(HttpUtil *httpUtil);

private:
    QNetworkAccessManager *manager;
    QNetworkReply::NetworkError errorType;

private slots:
    void onManagerFinished(QNetworkReply *reply);

};


