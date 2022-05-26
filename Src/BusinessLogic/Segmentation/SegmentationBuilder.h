#pragma once
#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonArray>
#include "Segmentation.h"

namespace builder::segmentation {
    static Segmentation create(const QJsonObject &json)
    {
        Segmentation output;
        output.id = json["id"].toInt();
        output.code = json["code"].toString();
        output.libelle = json["libelle"].toString();
        return output;
    };

    static QList<Segmentation> create(const QByteArray &input)
    {
        QList<Segmentation> result;
        QJsonParseError error;

        QJsonDocument jsonDoc = QJsonDocument::fromJson(input, &error);
        if (error.error == QJsonParseError::NoError) {
            QJsonArray jsonArray = jsonDoc.array();
            foreach (const  QJsonValue &value, jsonArray) {
                QJsonObject jsonObject = value.toObject();
                Segmentation item = create(jsonObject);
                result.append(item);
            }
        }
        return result;
    };
}
