#pragma once

#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonArray>
#include "PosGroupProductModel.h"

namespace Builder::PosGroupProduct {
    static PosGroupProductModel create(const QJsonObject &json)
    {
        PosGroupProductModel output;
        output.id = json["id"].toInt();
        output.code = json["code"].toString();
        output.libelle = json["libelle"].toString();
        output.iconeImg = json["iconeImg"].toString();
        return output;
    };

    static QList<PosGroupProductModel> create(const QByteArray &input)
    {
        QList<PosGroupProductModel> result;
        QJsonParseError error;

        QJsonDocument jsonDoc = QJsonDocument::fromJson(input, &error);
        if (error.error == QJsonParseError::NoError) {
            QJsonArray jsonArray = jsonDoc.array();
            foreach (const  QJsonValue &value, jsonArray) {
                QJsonObject jsonObject = value.toObject();
                PosGroupProductModel item = create(jsonObject);
                result.append(item);
            }
        }
        return result;
    };
}
