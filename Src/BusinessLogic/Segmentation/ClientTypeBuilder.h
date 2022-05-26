#pragma once
#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonArray>
#include "ClientType.h"

namespace builder::client_type {
    static ClientType create(const QJsonObject &json)
    {
        ClientType output;
        output.id = json["id"].toInt();
        output.code = json["code"].toString();
        output.libelle = json["libelle"].toString();
        return output;
    };

    static QList<ClientType> create(const QByteArray &input)
    {
        QList<ClientType> result;
        QJsonParseError error;

        QJsonDocument jsonDoc = QJsonDocument::fromJson(input, &error);
        if (error.error == QJsonParseError::NoError) {
            QJsonArray jsonArray = jsonDoc.array();
            foreach (const  QJsonValue &value, jsonArray) {
                QJsonObject jsonObject = value.toObject();
                ClientType item = create(jsonObject);
                result.append(item);
            }
        }
        return result;
    };
}
