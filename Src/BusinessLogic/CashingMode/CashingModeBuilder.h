#pragma once
#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonArray>
#include "CashingMode.h"

namespace builder::cashing_mode {
    static CashingMode create(const QJsonObject &json)
    {
        CashingMode output;
        output.id = json["id"].toInt();
        output.code = json["code"].toString();
        output.libelle = json["libelle"].toString();
        output.nature = json["nature"].toString();
        return output;
    }

    static QList<CashingMode> create(const QByteArray &input)
    {
        QList<CashingMode> result;
        QJsonParseError error;

        QJsonDocument jsonDoc = QJsonDocument::fromJson(input, &error);
        if (error.error == QJsonParseError::NoError) {
            QJsonArray jsonArray = jsonDoc.array();
            foreach (const  QJsonValue &value, jsonArray) {
                QJsonObject jsonObject = value.toObject();
                CashingMode item = create(jsonObject);
                result.append(item);
            }
        }
        return result;
    }
}
