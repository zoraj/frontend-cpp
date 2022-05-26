#pragma once

#include <QString>

struct Client {
    int id;
    QString code;
    QString nom;
    QString prenom;
    QString adresse;
    QString ville;
    QString pays;
    int pmsPrescripteurId;
    int mmcTypeClientId;
    int mmcSegmentClientId;
};
