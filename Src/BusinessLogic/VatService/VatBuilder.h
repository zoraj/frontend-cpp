#pragma once

#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonArray>
#include "VatModel.h"

namespace Builder::Vat {
    static VatModel create(const QJsonObject &json)
    {
        VatModel output;
        output.id = json["id"].toInt();
        output.dateEffective = QDate::fromString(json["dateEffective"].toString(), "yyyy-MM-dd");
        output.valeur = json["valeur"].toInt();
        return output;
    };

    static QList<VatModel> create(const QByteArray &input)
    {
        QList<VatModel> result;
        QJsonParseError error;

        QJsonDocument jsonDoc = QJsonDocument::fromJson(input, &error);
        if (error.error == QJsonParseError::NoError) {
            QJsonArray jsonArray = jsonDoc.array();
            foreach (const  QJsonValue &value, jsonArray) {
                QJsonObject jsonObject = value.toObject();
                VatModel item = create(jsonObject);
                result.append(item);
            }
        }
        return result;
    };
}
