#pragma once

#include <QObject>
#include <QString>
#include <QDateTime>
#include "Src/Application/Util/Constant.h"

struct OrderDetail : public QObject {
    int id = constant::UNDEFINED_INT;
    int prestationId;
    int noteEnteteId = constant::UNDEFINED_INT;
    QString prestationLibelle;
    float pu;
    int qte;
    bool isVAE;
    bool isOffert;
    float total;
    QDateTime dateNote;

    Q_OBJECT
    Q_PROPERTY(int id MEMBER id);
    Q_PROPERTY(int prestationId MEMBER prestationId);
    Q_PROPERTY(int noteEnteteId MEMBER noteEnteteId);
    Q_PROPERTY(QString prestationLibelle MEMBER prestationLibelle);
    Q_PROPERTY(int qte MEMBER qte);
    Q_PROPERTY(bool isVAE MEMBER isVAE);
    Q_PROPERTY(bool isOffert MEMBER isOffert);
    Q_PROPERTY(float total MEMBER total);
    Q_PROPERTY(float pu MEMBER pu);
    Q_PROPERTY(QDateTime dateNote MEMBER dateNote);
};

struct Order: public QObject {
    int id = constant::UNDEFINED_INT;
    int mmcClientId;
    int numTable;
    int nbCouvert;
    QString posteUuid;
    QDateTime dateNote;
    QString service;
    QList<OrderDetail *> orderDetail;
    int activiteId;
    int userId;
    QString etat;

    Q_OBJECT
    Q_PROPERTY(int id MEMBER id);
    Q_PROPERTY(int mmcClientId MEMBER mmcClientId);
    Q_PROPERTY(int numTable MEMBER numTable);
    Q_PROPERTY(int nbCouvert MEMBER nbCouvert);
    Q_PROPERTY(QString posteUuid MEMBER posteUuid);
    Q_PROPERTY(QDateTime dateNote MEMBER dateNote);
    Q_PROPERTY(QString service MEMBER service);
    Q_PROPERTY(QList<OrderDetail *> orderDetail MEMBER orderDetail);
    Q_PROPERTY(int activiteId MEMBER activiteId);
    Q_PROPERTY(int userId MEMBER userId);
};

