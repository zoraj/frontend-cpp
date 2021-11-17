#pragma once

#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonArray>
#include "RoomModel.h"

namespace Builder::Room {

    static RoomModel create(const QJsonObject &json)
    {
        RoomModel output;
        output.id = json["id"].toInt();
        output.numeroChambre = json["numeroChambre"].toString();
        output.numeroEtage = json["numeroEtage"].toInt();
        output.pmsTypeChambreId = json["pmsTypeChambreId"].toInt();
        output.etatChambre = json["etatChambre"].toString();
        return output;
    };

    static QList<RoomModel> create(const QByteArray &input)
    {
        QList<RoomModel> result;
        QJsonParseError error;

        QJsonDocument jsonDoc = QJsonDocument::fromJson(input, &error);
        if (error.error == QJsonParseError::NoError) {
            QJsonArray jsonArray = jsonDoc.array();
            foreach (const  QJsonValue &value, jsonArray) {
                QJsonObject jsonObject = value.toObject();
                RoomModel item = create(jsonObject);
                result.append(item);
            }
        }
        return result;
    };
}
