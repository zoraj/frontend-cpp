#pragma once
#include <QString>
#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonArray>

struct Setting {
    QString cle;
    QString valeur;

    Setting(){}
    Setting(const QString &key, const QString &value)
    {
        cle = key;
        valeur = value;
    }
};
