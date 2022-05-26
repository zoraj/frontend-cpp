#pragma once

#include <QObject>
#include <QString>
#include <QJsonObject>
#include "Src/Application/Util/Constant.h"

using namespace constant;

struct BookingRoom: public QObject
{
    int id = UNDEFINED_INT;
    int reservationId = UNDEFINED_INT;
    int qteChb = 1;
    int typeChambreId = UNDEFINED_INT;
    int chambreId = UNDEFINED_INT;
    QString typeChambreLibelle;
    QString numeroChambre;
};

struct Booking: public QObject
{
    int id = UNDEFINED_INT;
    QDate dateArrivee;
    QDate dateDepart;
    QString nomReservation;
    int nbChambre;
    int nbPax;
    int nbEnfant = 0;
    QString reservationType;
    int pmsTarifGrilleId = -1;
    QString nom;
    QString prenom;
    const QString origine = "PMS";
    QString posteUuid = "_BOOKING_";
    int mmcClientId = UNDEFINED_INT;
    int pmsPrescripteurId = UNDEFINED_INT;
    int mmcSegmentClientId = UNDEFINED_INT;
    int mmcTypeClientId = UNDEFINED_INT;
    QString nationalite;
    QString signature;
    QString observation;
    QString numeroReservation;
    QList<BookingRoom *> chambres;
    QString civilite;
    QString adresse1;
    QString adresse2;
    QString cp;
    QString ville;
    QString pays;
    QString tel;
    QString email;



    // To allow us to use the structure within qml
Q_OBJECT
    Q_PROPERTY(int id MEMBER id);
    Q_PROPERTY(QDate dateArrivee MEMBER dateArrivee);
    Q_PROPERTY(QDate dateDepart MEMBER dateDepart);
    Q_PROPERTY(QString nomReservation MEMBER nomReservation);
    Q_PROPERTY(int nbChambre MEMBER nbChambre);
    Q_PROPERTY(int nbPax MEMBER nbPax);
    Q_PROPERTY(int nbEnfant MEMBER nbEnfant);
    Q_PROPERTY(QString reservationType MEMBER reservationType);
    Q_PROPERTY(int pmsTarifGrilleId MEMBER pmsTarifGrilleId);
    Q_PROPERTY(QString nom MEMBER nom);
    Q_PROPERTY(QString prenom MEMBER prenom);
    Q_PROPERTY(int mmcClientId MEMBER mmcClientId);
    Q_PROPERTY(int pmsPrescripteurId MEMBER pmsPrescripteurId);
    Q_PROPERTY(int mmcSegmentClientId MEMBER mmcSegmentClientId);
    Q_PROPERTY(int mmcTypeClientId MEMBER mmcTypeClientId);
    Q_PROPERTY(QString nationalite MEMBER nationalite);
    Q_PROPERTY(QString signature MEMBER signature);
    Q_PROPERTY(QString observation MEMBER observation);
    Q_PROPERTY(QString numeroReservation MEMBER numeroReservation);
    Q_PROPERTY(QString civilite MEMBER civilite);
    Q_PROPERTY(QString adresse1 MEMBER adresse1);
    Q_PROPERTY(QString adresse2 MEMBER adresse2);
    Q_PROPERTY(QString cp MEMBER cp);
    Q_PROPERTY(QString ville MEMBER ville);
    Q_PROPERTY(QString pays MEMBER pays);
    Q_PROPERTY(QString tel MEMBER tel);
    Q_PROPERTY(QString email MEMBER email);
};
