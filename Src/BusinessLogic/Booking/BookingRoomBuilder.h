#pragma once

#include "Booking.h"
#include <QJsonParseError>
#include <QJsonArray>
#include <QPointer>

namespace builder::booking_room {
    static BookingRoom *create(const QJsonObject &json)
    {
        QPointer<BookingRoom> output = new BookingRoom;
        output->id = json["id"].toInt();
        output->reservationId = json["pmsReservationId"].toInt();
        output->typeChambreId = json["pmsTypeChambreId"].toInt();
        output->chambreId = json["pmsChambreId"].toInt();
        return output;
    }
    static QList<BookingRoom *> createList(const QByteArray &input)
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
    }
}
