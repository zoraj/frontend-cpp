#pragma once

#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonArray>
#include "Season.h"
//#include "SubSeasonModel.h"

namespace builder::season {
    static Season create(const QJsonObject &json)
    {
        Season season;
        season.id = json["id"].toInt();
        season.reference = json["reference"].toString();
        season.libelle = json["libelle"].toString();
        return season;
    };

    static QList<Season> create(const QByteArray &input)
    {
        QList<Season> result;
        QJsonParseError error;

        QJsonDocument jsonDoc = QJsonDocument::fromJson(input, &error);
        if (error.error == QJsonParseError::NoError) {
            QJsonArray jsonArray = jsonDoc.array();
            foreach (const  QJsonValue &value, jsonArray) {
                QJsonObject jsonObject = value.toObject();
                Season item = create(jsonObject);
                result.append(item);
            }
        }
        return result;
    };
}
