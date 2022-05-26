#pragma once

#include <QString>
#include <QDateTime>

struct OrderCheckout {
    int id;
    int noteEnteteId;
    int modeEncaissementId;
    QString modeEncaissementLibelle;
    float montantTtc;
    float montantTva;
    int userId;
    QDateTime dateEncaissement;
};
