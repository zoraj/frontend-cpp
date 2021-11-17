#pragma once
#include <QString>
#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonArray>

struct SettingModel {
    QString cle;
    QString valeur;

    SettingModel(){}
    SettingModel(const QString &key, const QString &value)
    {
        cle = key;
        valeur = value;
    }
};
