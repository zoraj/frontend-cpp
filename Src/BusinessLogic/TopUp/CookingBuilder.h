#pragma once

#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonArray>

#include "TopUp.h"

namespace builder::cooking {
    static Cooking create(const QJsonObject &json)
    {
        Cooking  output;
        output.id = json["id"].toInt();
        output.code = json["code"].toString();
        output.libelle = json["libelle"].toString();
        return output;
    }

    static QList<Cooking > create(const QByteArray &input)
    {
        QList<Cooking > result;
        QJsonParseError error;

        QJsonDocument jsonDoc = QJsonDocument::fromJson(input, &error);
        if (error.error == QJsonParseError::NoError) {
            QJsonArray jsonArray = jsonDoc.array();
            foreach (const  QJsonValue &value, jsonArray) {
                QJsonObject jsonObject = value.toObject();
                Cooking item = create(jsonObject);
                result.append(item);
            }
        }
        return result;
    }
}

