#pragma once

#include <QObject>
#include <QtSql/QSqlQuery>
#include <QSqlRecord>
#include <QtSql/QSqlError>
#include <QDebug>

#include "SettingModel.h"


namespace Cache::Setting {
    static SettingModel get(const QString &key)
    {
        SettingModel setting;
        QSqlQuery q;
        q.prepare("SELECT * FROM t_mmc_parametrage WHERE cle =:cle");
        q.bindValue(":cle", key);

        if (q.exec()) {
            int cle = q.record().indexOf("cle");
            int valeur = q.record().indexOf("valeur");

             if (q.next()) {
                setting.cle = q.value(cle).toString();
                setting.valeur = q.value(valeur).toString();
             }
             else {
                 setting.cle = key;
                 setting.valeur = nullptr;
             }
        }
        else {
            qDebug()<< "Error: " << q.lastQuery() << q.lastError();
        }
        return setting;
    }

    static void persist(const SettingModel &data)
    {
        QSqlQuery q;
        q.prepare("INSERT INTO t_mmc_parametrage(cle,valeur) VALUES (:cle, :valeur)");
        q.bindValue(":cle", data.cle);
        q.bindValue(":valeur", data.valeur);
        if (!q.exec()){
            qDebug()<< "Error: " << q.lastQuery() << q.lastError();
        }
    }

    static void persist(QList<SettingModel> settings, bool resetBefore)
    {
        QSqlDatabase::database().transaction();
        QSqlQuery q;
        if (resetBefore) {
            foreach(const SettingModel &setting, settings) {
                q.prepare("DELETE FROM t_mmc_parametrage WHERE cle=:cle");
                q.bindValue(":cle", setting.cle);
                if (!q.exec()) {
                    qDebug()<< "Error: " << q.lastQuery() << q.lastError();
                }
            }
        }
        foreach(const SettingModel &setting, settings) {
            persist(setting);
        }
        QSqlDatabase::database().commit();
    }
}
