#pragma once

#include <QString>

struct Activity {
    int id;
    QString code;
    QString libelle;
    QString iconeImg;
    int nombreTable;
    bool isGestionServeur;
    bool isGestionTable;
    bool isGestionCouvert;
};
