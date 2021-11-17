#pragma once

#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonArray>
#include "SeasonModel.h"
//#include "SubSeasonModel.h"

namespace SeasonBuilder {
    static SeasonModel create(const QJsonObject &json)
    {
        SeasonModel season;
        season.id = json["id"].toInt();
        season.reference = json["reference"].toString();
        season.libelle = json["libelle"].toString();
        return season;
    };

    static QList<SeasonModel> create(const QByteArray &input)
    {
        QList<SeasonModel> result;
        QJsonParseError error;

        QJsonDocument jsonDoc = QJsonDocument::fromJson(input, &error);
        if (error.error == QJsonParseError::NoError) {
            QJsonArray jsonArray = jsonDoc.array();
            foreach (const  QJsonValue &value, jsonArray) {
                QJsonObject jsonObject = value.toObject();
                SeasonModel item = create(jsonObject);
                result.append(item);
            }
        }
        return result;
    };
}
