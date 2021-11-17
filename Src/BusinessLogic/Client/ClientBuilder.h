#pragma once

#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonArray>
#include "ClientModel.h"

namespace Builder::Client {
    static ClientModel create(const QJsonObject &json)
    {
        ClientModel output;
        output.id = json["id"].toInt();
        output.code = json["code"].toString();
        output.nom = json["nom"].toString();
        output.prenom = json["prenom"].toString();
        output.adresse = json["adresse"].toString();
        output.ville = json["ville"].toString();
        output.pays = json["nationalite"].toString();
        output.pmsPrescripteurId = json["pmsPrescripteurId"].toInt();
        output.mmcTypeClientId = json["mmcTypeClientId"].toInt();
        output.mmcSegmentClientId = json["mmcSegmentClientId"].toInt();
        return output;
    };

    static QList<ClientModel> create(const QByteArray &input)
    {
        QList<ClientModel> result;
        QJsonParseError error;

        QJsonDocument jsonDoc = QJsonDocument::fromJson(input, &error);
        if (error.error == QJsonParseError::NoError) {
            QJsonArray jsonArray = jsonDoc.array();
            foreach (const  QJsonValue &value, jsonArray) {
                QJsonObject jsonObject = value.toObject();
                ClientModel item = create(jsonObject);
                result.append(item);
            }
        }
        return result;
    };
}
