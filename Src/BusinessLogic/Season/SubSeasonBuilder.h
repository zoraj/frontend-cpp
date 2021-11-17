#pragma once
#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonArray>
#include "SubSeasonModel.h"

namespace Builder::SubSeason {
    static SubSeasonModel create(const QJsonObject &json)
    {
        SubSeasonModel output;
        output.id = json["id"].toInt();
        output.reference = json["reference"].toString();
        output.libelle = json["libelle"].toString();
        output.pmsSaisonId = json["pmsSaisonId"].toInt();
        output.dateDebut = QDate::fromString(json["dateDebut"].toString(), "yyyy-MM-dd");
        output.dateFin = QDate::fromString(json["dateFin"].toString(), "yyyy-MM-dd");
        return output;
    };

    static QList<SubSeasonModel> create(const QByteArray &input)
    {
        QList<SubSeasonModel> result;
        QJsonParseError error;

        QJsonDocument jsonDoc = QJsonDocument::fromJson(input, &error);
        if (error.error == QJsonParseError::NoError) {
            QJsonArray jsonArray = jsonDoc.array();
            foreach (const  QJsonValue &value, jsonArray) {
                QJsonObject jsonObject = value.toObject();
                SubSeasonModel item = create(jsonObject);
                result.append(item);
            }
        }
        return result;
    };
}
