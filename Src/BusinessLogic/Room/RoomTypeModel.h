#pragma once

#include <QString>

struct RoomTypeModel {
    int id;
    QString libelle;
    QString reference;
    int persMax;
    int persMin;
    int nbEnfant;
    int pmsCategorieChambreId;
};
