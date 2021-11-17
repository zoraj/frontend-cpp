#pragma once

#include <QString>

struct PosProductModel {
    int id;
    QString code;
    QString libelle;
    int posPrestationGroupeId;
    int positionCommande;
    QString type;
    float prix;
    QString couleur;
    int mmcSousFamilleCaId;
    QString gestionType;
};
