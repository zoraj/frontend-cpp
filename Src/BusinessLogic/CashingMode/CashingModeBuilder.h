#pragma once
#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonArray>
#include "CashingModeModel.h"

namespace Builder::CashingMode {
    static CashingModeModel create(const QJsonObject &json)
    {
        CashingModeModel output;
        output.id = json["id"].toInt();
        output.code = json["code"].toString();
        output.libelle = json["libelle"].toString();
        output.nature = json["nature"].toString();
        return output;
    }

    static QList<CashingModeModel> create(const QByteArray &input)
    {
        QList<CashingModeModel> result;
        QJsonParseError error;

        QJsonDocument jsonDoc = QJsonDocument::fromJson(input, &error);
        if (error.error == QJsonParseError::NoError) {
            QJsonArray jsonArray = jsonDoc.array();
            foreach (const  QJsonValue &value, jsonArray) {
                QJsonObject jsonObject = value.toObject();
                CashingModeModel item = create(jsonObject);
                result.append(item);
            }
        }
        return result;
    }
}
