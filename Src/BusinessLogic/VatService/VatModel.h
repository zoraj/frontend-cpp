#pragma once

#include <QDate>
#include <QString>

struct VatModel {
    int id;
    QDate dateEffective;
    float valeur;
};
