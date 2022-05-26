#pragma once
#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonArray>
#include "SubSeason.h"

namespace builder::sub_season {
    static SubSeason create(const QJsonObject &json)
    {
        SubSeason output;
        output.id = json["id"].toInt();
        output.reference = json["reference"].toString();
        output.libelle = json["libelle"].toString();
        output.pmsSaisonId = json["pmsSaisonId"].toInt();
        output.dateDebut = QDate::fromString(json["dateDebut"].toString(), "yyyy-MM-dd");
        output.dateFin = QDate::fromString(json["dateFin"].toString(), "yyyy-MM-dd");
        return output;
    };

    static QList<SubSeason> create(const QByteArray &input)
    {
        QList<SubSeason> result;
        QJsonParseError error;

        QJsonDocument jsonDoc = QJsonDocument::fromJson(input, &error);
        if (error.error == QJsonParseError::NoError) {
            QJsonArray jsonArray = jsonDoc.array();
            foreach (const  QJsonValue &value, jsonArray) {
                QJsonObject jsonObject = value.toObject();
                SubSeason item = create(jsonObject);
                result.append(item);
            }
        }
        return result;
    };
}
