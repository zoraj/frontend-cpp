#pragma once

#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonArray>

#include "TopUpModel.h"

namespace Builder::Cooking {
    static CookingModel create(const QJsonObject &json)
    {
        CookingModel  output;
        output.id = json["id"].toInt();
        output.code = json["code"].toString();
        output.libelle = json["libelle"].toString();
        return output;
    }

    static QList<CookingModel > create(const QByteArray &input)
    {
        QList<CookingModel > result;
        QJsonParseError error;

        QJsonDocument jsonDoc = QJsonDocument::fromJson(input, &error);
        if (error.error == QJsonParseError::NoError) {
            QJsonArray jsonArray = jsonDoc.array();
            foreach (const  QJsonValue &value, jsonArray) {
                QJsonObject jsonObject = value.toObject();
                CookingModel item = create(jsonObject);
                result.append(item);
            }
        }
        return result;
    }
}

