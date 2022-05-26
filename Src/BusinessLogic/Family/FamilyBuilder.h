#pragma once

#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonArray>
#include "Family.h"

namespace builder::family {

    static Family create(const QJsonObject &json)
    {
        Family output;
        output.id = json["id"].toInt();
        output.code = json["code"].toString();
        output.libelle = json["libelle"].toString();
        return output;
    };

    static QList<Family> create(const QByteArray &input)
    {
        QList<Family> result;
        QJsonParseError error;

        QJsonDocument jsonDoc = QJsonDocument::fromJson(input, &error);
        if (error.error == QJsonParseError::NoError) {
            QJsonArray jsonArray = jsonDoc.array();
            foreach (const  QJsonValue &value, jsonArray) {
                QJsonObject jsonObject = value.toObject();
                Family item = create(jsonObject);
                result.append(item);
            }
        }
        return result;
    };
}
