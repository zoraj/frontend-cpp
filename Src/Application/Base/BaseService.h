#pragma once

#include <QObject>
#include <QJsonDocument>
#include "Src/Application/Util/HttpUtil.h"
#include "Src/Application/Util/HttpRequest.h"


class BaseService : public QObject
{
    Q_OBJECT
    QTime timer;
protected:
    QString apiKey;
    QString bearerToken;
    constant::WSEndpoint endpoint = constant::WSEndpoint::UNKNOWN;
public:
    explicit BaseService(QObject *parent = nullptr);
    explicit BaseService(const QString &apiKey, const QString &token);

    QString fullPath(const QString &method) const;
    void executeRequest(const HttpRequest &request);
    void executeRequest(const HttpRequestForArray &request);

    virtual void callback(constant::WSEndpoint endpoint, const QByteArray &, int);

signals:

public slots:
    void handleResult(HttpUtil *httpUtil);
};
