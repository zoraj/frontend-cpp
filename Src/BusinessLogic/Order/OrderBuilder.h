#pragma once

#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonArray>
#include "OrderModel.h"

namespace PosOrderBuilder {
    static OrderModel *create(const QJsonObject &json)
    {
        auto output = new OrderModel();
        output->id = json["id"].toInt();
        output->numTable = json["numTable"].toInt();
        output->nbCouvert = json["nbCouvert"].toInt();
        output->posteUuid = json["posteUuid"].toString();
        output->dateNote = QDateTime::fromString(json["dateNote"].toString(), "yyyy-MM-dd hh:mm:ss");
        output->service = json["service"].toString();

        return output;
    }

    /*
    static QList<OrderModel *> create(const QByteArray &input)
    {
        QList<OrderModel *> result;
        QJsonParseError error;

        QJsonDocument jsonDoc = QJsonDocument::fromJson(input, &error);
        if (error.error == QJsonParseError::NoError) {
            QJsonArray jsonArray = jsonDoc.array();
            foreach (const  QJsonValue &value, jsonArray) {
                QJsonObject jsonObject = value.toObject();
                OrderModel *item = create(jsonObject);
                result.append(item);
            }
        }
        return result;
    }*/

    static OrderModel *create(const QByteArray &input)
    {
        OrderModel *result = nullptr;
        QJsonParseError error;

        QJsonDocument jsonDoc = QJsonDocument::fromJson(input, &error);
        if (error.error == QJsonParseError::NoError) {
            QJsonObject jsonObject = jsonDoc.object();
            result = create(jsonObject);
        }
        return result;
    }
}
