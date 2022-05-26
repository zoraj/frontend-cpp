#pragma once

#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonArray>
#include "RoomType.h"

namespace builder::room_type {
    static RoomType create(const QJsonObject &json)
    {
        RoomType output;
        output.id = json["id"].toInt();
        output.libelle = json["libelle"].toString();
        output.reference = json["reference"].toString();
        output.persMax = json["persMax"].toInt();
        output.persMin = json["persMin"].toInt();
        output.nbEnfant = json["nbEnfant"].toInt();
        output.pmsCategorieChambreId = json["pmsCategorieChambreId"].toInt();
        return output;
    };

    static QList<RoomType> create(const QByteArray &input)
    {
        QList<RoomType> result;
        QJsonParseError error;

        QJsonDocument jsonDoc = QJsonDocument::fromJson(input, &error);
        if (error.error == QJsonParseError::NoError) {
            QJsonArray jsonArray = jsonDoc.array();
            foreach (const  QJsonValue &value, jsonArray) {
                QJsonObject jsonObject = value.toObject();
                RoomType item = create(jsonObject);
                result.append(item);
            }
        }
        return result;
    };
}
