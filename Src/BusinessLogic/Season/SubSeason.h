#pragma once

#include <QString>
#include <QDate>

struct SubSeason {
    int id;
    QString reference;
    QString libelle;
    int pmsSaisonId;
    QDate dateDebut;
    QDate dateFin;
};
