#pragma once

#include <QString>

struct RoomType {
    int id;
    QString libelle;
    QString reference;
    int persMax;
    int persMin;
    int nbEnfant;
    int pmsCategorieChambreId;
};
