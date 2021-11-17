#pragma once

#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonArray>

#include "TopUpModel.h"

namespace Builder::Accompaniment {
    static AccompanimentModel create(const QJsonObject &json)
    {
        AccompanimentModel  output;
        output.id = json["id"].toInt();
        output.code = json["code"].toString();
        output.libelle = json["libelle"].toString();
        return output;
    }

    static QList<AccompanimentModel > create(const QByteArray &input)
    {
        QList<AccompanimentModel > result;
        QJsonParseError error;

        QJsonDocument jsonDoc = QJsonDocument::fromJson(input, &error);
        if (error.error == QJsonParseError::NoError) {
            QJsonArray jsonArray = jsonDoc.array();
            foreach (const  QJsonValue &value, jsonArray) {
                QJsonObject jsonObject = value.toObject();
                AccompanimentModel item = create(jsonObject);
                result.append(item);
            }
        }
        return result;
    }
}
