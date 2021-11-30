#pragma once

#include <QString>
#include <QDateTime>

struct OrderCheckoutModel {
    int id;
    int noteEnteteId;
    int modeEncaissementId;
    QString modeEncaissementLibelle;
    float montantTtc;
    float montantTva;
    int userId;
    QDateTime dateEncaissement;
};
