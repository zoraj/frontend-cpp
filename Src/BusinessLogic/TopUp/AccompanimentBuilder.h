#pragma once

#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonArray>

#include "TopUp.h"

namespace builder::accompaniment {
    static Accompaniment create(const QJsonObject &json)
    {
        Accompaniment  output;
        output.id = json["id"].toInt();
        output.code = json["code"].toString();
        output.libelle = json["libelle"].toString();
        return output;
    }

    static QList<Accompaniment > create(const QByteArray &input)
    {
        QList<Accompaniment > result;
        QJsonParseError error;

        QJsonDocument jsonDoc = QJsonDocument::fromJson(input, &error);
        if (error.error == QJsonParseError::NoError) {
            QJsonArray jsonArray = jsonDoc.array();
            foreach (const  QJsonValue &value, jsonArray) {
                QJsonObject jsonObject = value.toObject();
                Accompaniment item = create(jsonObject);
                result.append(item);
            }
        }
        return result;
    }
}
