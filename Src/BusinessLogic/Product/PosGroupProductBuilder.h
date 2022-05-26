#pragma once

#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonArray>
#include "PosGroupProduct.h"

namespace builder::pos_group_product {
    static PosGroupProduct create(const QJsonObject &json)
    {
        PosGroupProduct output;
        output.id = json["id"].toInt();
        output.code = json["code"].toString();
        output.libelle = json["libelle"].toString();
        output.iconeImg = json["iconeImg"].toString();
        return output;
    };

    static QList<PosGroupProduct> create(const QByteArray &input)
    {
        QList<PosGroupProduct> result;
        QJsonParseError error;

        QJsonDocument jsonDoc = QJsonDocument::fromJson(input, &error);
        if (error.error == QJsonParseError::NoError) {
            QJsonArray jsonArray = jsonDoc.array();
            foreach (const  QJsonValue &value, jsonArray) {
                QJsonObject jsonObject = value.toObject();
                PosGroupProduct item = create(jsonObject);
                result.append(item);
            }
        }
        return result;
    };
}
