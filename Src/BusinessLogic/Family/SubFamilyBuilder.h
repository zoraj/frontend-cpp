#pragma once

#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonArray>
#include "SubFamilyModel.h"

namespace builder::sub_family {
    static SubFamilyModel create(const QJsonObject &json)
    {
        SubFamilyModel output;
        output.id = json["id"].toInt();
        output.mmcFamilleCaId = json["mmcFamilleCaId"].toInt();
        output.code = json["code"].toString();
        output.libelle = json["libelle"].toString();
        output.mmcTvaId = json["mmcTvaId"].toInt();
        return output;
    };

    static QList<SubFamilyModel> create(const QByteArray &input)
    {
        QList<SubFamilyModel> result;
        QJsonParseError error;

        QJsonDocument jsonDoc = QJsonDocument::fromJson(input, &error);
        if (error.error == QJsonParseError::NoError) {
            QJsonArray jsonArray = jsonDoc.array();
            foreach (const  QJsonValue &value, jsonArray) {
                QJsonObject jsonObject = value.toObject();
                SubFamilyModel item = create(jsonObject);
                result.append(item);
            }
        }
        return result;
    };
}
