#pragma once
#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonArray>
#include "Prescripteur.h"

namespace builder::prescripteur {
    static Prescripteur create(const QJsonObject &json)
    {
        Prescripteur output;
        output.id = json["id"].toInt();
        output.code = json["code"].toString();
        output.libelle = json["libelle"].toString();
        return output;
    };

    static QList<Prescripteur> create(const QByteArray &input)
    {
        QList<Prescripteur> result;
        QJsonParseError error;

        QJsonDocument jsonDoc = QJsonDocument::fromJson(input, &error);
        if (error.error == QJsonParseError::NoError) {
            QJsonArray jsonArray = jsonDoc.array();
            foreach (const  QJsonValue &value, jsonArray) {
                QJsonObject jsonObject = value.toObject();
                Prescripteur item = create(jsonObject);
                result.append(item);
            }
        }
        return result;
    };
}
