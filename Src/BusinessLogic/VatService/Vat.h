#pragma once

#include <QDate>
#include <QString>

struct Vat {
    int id;
    QDate dateEffective;
    float valeur;
};
