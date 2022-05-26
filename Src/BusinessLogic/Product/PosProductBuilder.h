#pragma once

#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonArray>
#include "PosProduct.h"

namespace builder::pos_product {
    static PosProduct create(const QJsonObject &json)
    {
        PosProduct output;
        output.id = json["id"].toInt();
        output.code = json["code"].toString();
        output.libelle = json["libelle"].toString();
        output.posPrestationGroupeId = json["posPrestationGroupeId"].toInt();
        output.positionCommande = json["positionCommande"].toInt();
        output.type = json["type"].toString();
        output.prix = json["prix"].toDouble();
        output.couleur = json["couleur"].toString();
        output.mmcSousFamilleCaId = json["mmcSousFamilleCaId"].toInt();
        return output;
    };

    static QList<PosProduct> create(const QByteArray &input)
    {
        QList<PosProduct> result;
        QJsonParseError error;

        QJsonDocument jsonDoc = QJsonDocument::fromJson(input, &error);
        if (error.error == QJsonParseError::NoError) {
            QJsonArray jsonArray = jsonDoc.array();
            foreach (const  QJsonValue &value, jsonArray) {
                QJsonObject jsonObject = value.toObject();
                PosProduct item = create(jsonObject);
                result.append(item);
            }
        }
        return result;
    };
}
