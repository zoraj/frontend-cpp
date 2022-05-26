#pragma once
#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonArray>
#include "RateGrid.h"

namespace builder::rate_grid {
    static RateGrid create(const QJsonObject &json)
    {
        RateGrid output;
        output.id = json["id"].toInt();
        output.reference = json["reference"].toString();
        output.nom = json["nom"].toString();
        output.nbClient = json["nbClient"].toInt();
        output.saisonId = json["saisonId"].toInt();
        output.sousSaisonId = json["sousSaisonId"].toInt();
        return output;
    };

    static QList<RateGrid> create(const QByteArray &input)
    {
        QList<RateGrid> result;
        QJsonParseError error;

        QJsonDocument jsonDoc = QJsonDocument::fromJson(input, &error);
        if (error.error == QJsonParseError::NoError) {
            QJsonArray jsonArray = jsonDoc.array();
            foreach (const  QJsonValue &value, jsonArray) {
                QJsonObject jsonObject = value.toObject();
                RateGrid item = create(jsonObject);
                result.append(item);
            }
        }
        return result;
    };
}
