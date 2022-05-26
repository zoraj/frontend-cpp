#pragma once

#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonArray>
#include "RoomCategoryModel.h"

namespace builder::room_category {
    static RoomCategoryModel create(const QJsonObject &json)
    {
        RoomCategoryModel output;
        output.id = json["id"].toInt();
        output.libelle = json["libelle"].toString();
        output.reference = json["reference"].toString();
        return output;
    };

    static QList<RoomCategoryModel> create(const QByteArray &input)
    {
        QList<RoomCategoryModel> result;
        QJsonParseError error;

        QJsonDocument jsonDoc = QJsonDocument::fromJson(input, &error);
        if (error.error == QJsonParseError::NoError) {
            QJsonArray jsonArray = jsonDoc.array();
            foreach (const  QJsonValue &value, jsonArray) {
                QJsonObject jsonObject = value.toObject();
                RoomCategoryModel item = create(jsonObject);
                result.append(item);
            }
        }
        return result;
    };
}
