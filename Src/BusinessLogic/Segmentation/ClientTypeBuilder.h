#pragma once
#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonArray>
#include "ClientTypeModel.h"

namespace Builder::ClientType {
    static ClientTypeModel create(const QJsonObject &json)
    {
        ClientTypeModel output;
        output.id = json["id"].toInt();
        output.code = json["code"].toString();
        output.libelle = json["libelle"].toString();
        return output;
    };

    static QList<ClientTypeModel> create(const QByteArray &input)
    {
        QList<ClientTypeModel> result;
        QJsonParseError error;

        QJsonDocument jsonDoc = QJsonDocument::fromJson(input, &error);
        if (error.error == QJsonParseError::NoError) {
            QJsonArray jsonArray = jsonDoc.array();
            foreach (const  QJsonValue &value, jsonArray) {
                QJsonObject jsonObject = value.toObject();
                ClientTypeModel item = create(jsonObject);
                result.append(item);
            }
        }
        return result;
    };
}
