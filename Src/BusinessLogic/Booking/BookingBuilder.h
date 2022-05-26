#pragma once

#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonArray>
#include <QPointer>
#include "Booking.h"
#include "Src/Application/Util/Constant.h"

namespace builder::booking {
    static Booking *create(const QJsonObject &json)
    {
        QPointer<Booking> output = new Booking;
        output->id = json["id"].toInt();
        output->dateArrivee =  QDate::fromString(json["dateArrivee"].toString(), "yyyy-MM-dd");
        output->dateDepart = QDate::fromString(json["dateDepart"].toString(), "yyyy-MM-dd");
        output->nbChambre = json["nbChambre"].toInt();
        output->nbPax = json["nbPax"].toInt();
        output->nom = json["nom"].toString();
        output->nomReservation = json["nomReservation"].toString();
        output->numeroReservation = json["numeroReservation"].toString();
        output->reservationType = json["reservationType"].toString();
        return output;
    }

    static Booking *create(const QByteArray &input)
    {

        Booking *result = nullptr;
        QJsonParseError error;
        QJsonDocument jsonDoc = QJsonDocument::fromJson(input, &error);
        if (error.error == QJsonParseError::NoError) {
            QJsonObject jsonObject = jsonDoc.object();
            result = create(jsonObject);
        }
        return result;
    }

    static QList<Booking *> createList(const QByteArray &input)
    {
        QList<Booking *> result;
        QJsonParseError error;
        QJsonDocument jsonDoc = QJsonDocument::fromJson(input, &error);
        if (error.error == QJsonParseError::NoError) {
            QJsonArray jsonArray = jsonDoc.array();
            foreach (const  QJsonValue &value, jsonArray) {
                QJsonObject jsonObject = value.toObject();
                Booking *item = create(jsonObject);
                result.append(item);
            }
        }
        return result;
    }

    static QJsonObject serialize(const Booking &booking)
    {
        QJsonObject json;
        if (booking.id != constant::UNDEFINED_INT)
            json.insert("id", booking.id);
        json.insert("dateArrivee", booking.dateArrivee.toString("yyyy-MM-dd"));
        json.insert("dateDepart", booking.dateDepart.toString("yyyy-MM-dd"));
        json.insert("nomReservation", booking.nomReservation);
        json.insert("nbChambre", booking.nbChambre);
        json.insert("nbPax", booking.nbPax);
        json.insert("nbEnfant", booking.nbEnfant);
        json.insert("reservationType", booking.reservationType);
        if (booking.pmsTarifGrilleId != constant::UNDEFINED_INT)
            json.insert("pmsTarifGrilleId", booking.pmsTarifGrilleId);
        json.insert("nom", booking.nom);
        json.insert("prenom", booking.prenom);
        json.insert("origine", "PMS");
        json.insert("posteUuid","_BOOKING_");
        if (booking.mmcClientId != constant::UNDEFINED_INT)
            json.insert("mmcClientId", booking.mmcClientId);
        if (booking.pmsPrescripteurId != constant::UNDEFINED_INT)
            json.insert("pmsPrescripteurId", booking.pmsPrescripteurId);
        if (booking.mmcSegmentClientId != constant::UNDEFINED_INT)
            json.insert("mmcSegmentClientId", booking.mmcSegmentClientId);
        if (booking.mmcTypeClientId != constant::UNDEFINED_INT)
            json.insert("mmcTypeClientId", booking.mmcTypeClientId);
        if (!booking.nationalite.isEmpty())
            json.insert("nationalite", booking.nationalite);
        if (!booking.signature.isEmpty())
            json.insert("signature", booking.signature);
        if (!booking.observation.isEmpty())
            json.insert("observation", booking.observation);
        json.insert("numeroReservation", booking.numeroReservation);

        if (!booking.civilite.isEmpty())
            json.insert("civilite", booking.civilite);
        if (!booking.adresse1.isEmpty())
            json.insert("adresse1", booking.adresse1);
        if (!booking.adresse2.isEmpty())
            json.insert("adresse2", booking.adresse2);
        if (!booking.cp.isEmpty())
            json.insert("cp", booking.cp);
        if (!booking.ville.isEmpty())
            json.insert("ville", booking.ville);
        if (!booking.pays.isEmpty())
            json.insert("pays", booking.pays);
        if (!booking.tel.isEmpty())
            json.insert("tel", booking.tel);
        if (!booking.email.isEmpty())
            json.insert("email", booking.email);

        return json;
    }

    static QJsonObject serializeRoomRepartitions(const Booking &booking)
    {
        QJsonObject json;
        QJsonArray repartitionArray;
        json.insert("pmsReservationId", booking.id);
        for (BookingRoom * bookingRoom: booking.chambres) {
            QJsonObject repartitionJson;
            repartitionJson.insert("pmsTypeChambreId", bookingRoom->typeChambreId);
            repartitionJson.insert("pmsChambreId", bookingRoom->chambreId);
            repartitionArray.append(repartitionJson);
        }
        json.insert("ventilation", repartitionArray);

        return json;
    }

}
