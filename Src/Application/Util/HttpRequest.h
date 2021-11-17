#pragma once

#include <QString>
#include <QJsonObject>

struct HttpRequest {
    QString url;
    QString method;
    QJsonObject *payload = nullptr;
    QString apiKey;
    QString bearerToken;
};

struct HttpRequestForArray {
    QString url;
    QString method;
    QJsonArray *payload = nullptr;
    QString apiKey;
    QString bearerToken;
};

