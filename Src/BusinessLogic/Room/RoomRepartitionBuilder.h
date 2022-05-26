#pragma once

#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonArray>
#include <QPointer>
#include "Src/BusinessLogic/Booking/Booking.h"

namespace builder::room_repartition {

    static BookingRoom *create(const QJsonObject &json)
    {
        QPointer<BookingRoom> output = new BookingRoom;
        output->id = json["id"].toInt();
        output->reservationId = json["pmsReservationId"].toInt();
        output->qteChb = json["qteChb"].toInt();
        output->typeChambreId = json["pmsTypeChambreId"].toInt();
        output->chambreId = json["pmsChambreId"].toInt();
        return output;
    };

    static QList<BookingRoom *> create(const QByteArray &input)
    {
        QList<BookingRoom *> result;
        QJsonParseError error;

        QJsonDocument jsonDoc = QJsonDocument::fromJson(input, &error);
        if (error.error == QJsonParseError::NoError) {
            QJsonArray jsonArray = jsonDoc.array();
            foreach (const  QJsonValue &value, jsonArray) {
                QJsonObject jsonObject = value.toObject();
                BookingRoom *item = create(jsonObject);
                result.append(item);
            }
        }
        return result;
    };
}
