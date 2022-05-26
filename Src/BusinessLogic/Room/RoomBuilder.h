#pragma once

#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonArray>
#include "Room.h"

namespace builder::room {

    static Room *create(const QJsonObject &json)
    {
        Room *output = new Room();
        output->id = json["id"].toInt();
        output->numeroChambre = json["numeroChambre"].toString();
        output->numeroEtage = json["numeroEtage"].toInt();
        output->typeChambreId = json["pmsTypeChambreId"].toInt();
        output->etatChambre = json["etatChambre"].toString();
        output->typeChambreLibelle = json["pmsTypeChambreLibelle"].toString();
        return output;
    };

    static QList<Room *> create(const QByteArray &input)
    {
        QList<Room *> result;
        QJsonParseError error;

        QJsonDocument jsonDoc = QJsonDocument::fromJson(input, &error);
        if (error.error == QJsonParseError::NoError) {
            QJsonArray jsonArray = jsonDoc.array();
            foreach (const  QJsonValue &value, jsonArray) {
                QJsonObject jsonObject = value.toObject();
                Room *item = create(jsonObject);
                result.append(item);
            }
        }
        return result;
    };
}
