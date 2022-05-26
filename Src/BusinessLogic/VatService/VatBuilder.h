#pragma once

#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonArray>
#include "Vat.h"

namespace builder::vat {
    static Vat create(const QJsonObject &json)
    {
        Vat output;
        output.id = json["id"].toInt();
        output.dateEffective = QDate::fromString(json["dateEffective"].toString(), "yyyy-MM-dd");
        output.valeur = json["valeur"].toInt();
        return output;
    };

    static QList<Vat> create(const QByteArray &input)
    {
        QList<Vat> result;
        QJsonParseError error;

        QJsonDocument jsonDoc = QJsonDocument::fromJson(input, &error);
        if (error.error == QJsonParseError::NoError) {
            QJsonArray jsonArray = jsonDoc.array();
            foreach (const  QJsonValue &value, jsonArray) {
                QJsonObject jsonObject = value.toObject();
                Vat item = create(jsonObject);
                result.append(item);
            }
        }
        return result;
    };
}
