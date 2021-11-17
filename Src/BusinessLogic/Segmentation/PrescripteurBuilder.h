#pragma once
#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonArray>
#include "PrescripteurModel.h"

namespace Builder::Prescripteur {
    static PrescripteurModel create(const QJsonObject &json)
    {
        PrescripteurModel output;
        output.id = json["id"].toInt();
        output.code = json["code"].toString();
        output.libelle = json["libelle"].toString();
        return output;
    };

    static QList<PrescripteurModel> create(const QByteArray &input)
    {
        QList<PrescripteurModel> result;
        QJsonParseError error;

        QJsonDocument jsonDoc = QJsonDocument::fromJson(input, &error);
        if (error.error == QJsonParseError::NoError) {
            QJsonArray jsonArray = jsonDoc.array();
            foreach (const  QJsonValue &value, jsonArray) {
                QJsonObject jsonObject = value.toObject();
                PrescripteurModel item = create(jsonObject);
                result.append(item);
            }
        }
        return result;
    };
}
