#pragma once

#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonArray>
#include "Activity.h"

namespace builder::activity {
    static Activity create(const QJsonObject &json)
    {
        Activity output;
        output.id = json["id"].toInt();
        output.code = json["code"].toString();
        output.libelle = json["libelle"].toString();
        output.iconeImg = json["iconeImg"].toString();
        output.nombreTable = json["nombreTable"].toInt();
        output.isGestionServeur = (json["gestionServeur"] != QJsonValue::Undefined && json["gestionServeur"].toBool());
        output.isGestionTable = (json["gestionTable"] != QJsonValue::Undefined && json["gestionTable"].toBool());
        output.isGestionCouvert = (json["gestionCouvert"] != QJsonValue::Undefined && json["gestionCouvert"].toBool());
        return output;
    }

    static QList<Activity> create(const QByteArray &input)
    {
        QList<Activity> result;
        QJsonParseError error;

        QJsonDocument jsonDoc = QJsonDocument::fromJson(input, &error);
        if (error.error == QJsonParseError::NoError) {
            QJsonArray jsonArray = jsonDoc.array();
            foreach (const  QJsonValue &value, jsonArray) {
                QJsonObject jsonObject = value.toObject();
                Activity item = create(jsonObject);
                result.append(item);
            }
        }
        return result;
    }
}
