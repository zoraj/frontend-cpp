#pragma once

#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonArray>
#include "RoomTypeModel.h"

namespace Builder::RoomType {
    static RoomTypeModel create(const QJsonObject &json)
    {
        RoomTypeModel output;
        output.id = json["id"].toInt();
        output.libelle = json["libelle"].toString();
        output.reference = json["reference"].toString();
        output.persMax = json["persMax"].toInt();
        output.persMin = json["persMin"].toInt();
        output.nbEnfant = json["nbEnfant"].toInt();
        output.pmsCategorieChambreId = json["pmsCategorieChambreId"].toInt();
        return output;
    };

    static QList<RoomTypeModel> create(const QByteArray &input)
    {
        QList<RoomTypeModel> result;
        QJsonParseError error;

        QJsonDocument jsonDoc = QJsonDocument::fromJson(input, &error);
        if (error.error == QJsonParseError::NoError) {
            QJsonArray jsonArray = jsonDoc.array();
            foreach (const  QJsonValue &value, jsonArray) {
                QJsonObject jsonObject = value.toObject();
                RoomTypeModel item = create(jsonObject);
                result.append(item);
            }
        }
        return result;
    };
}
