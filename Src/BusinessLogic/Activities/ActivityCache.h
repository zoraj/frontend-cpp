#pragma once

#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QtSql/QSqlRecord>
#include <QDebug>
#include "Activity.h"

namespace cache::activity {
    static QList<Activity> getAll()
    {
        QList<Activity> list;
        QSqlQuery q;
        q.prepare("SELECT * FROM t_pos_activite ORDER BY code");
        if (q.exec()) {
            int id = q.record().indexOf("id");
            int code = q.record().indexOf("code");
            int libelle = q.record().indexOf("libelle");
            int nombreTable = q.record().indexOf("nombre_table");
            int iconeImg = q.record().indexOf("icone_img");
            int gestionServeur = q.record().indexOf("gestion_serveur");
            int gestionTable = q.record().indexOf("gestion_table");
            int gestionCouvert = q.record().indexOf("gestion_couvert");
            while (q.next()) {
                Activity data;
                data.id = q.value(id).toInt();
                data.code = q.value(code).toString();
                data.libelle = q.value(libelle).toString();
                data.nombreTable = q.value(nombreTable).toInt();
                data.iconeImg = q.value(iconeImg).toString();
                data.isGestionServeur = q.value(gestionServeur).toBool();
                data.isGestionTable = q.value(gestionTable).toBool();
                data.isGestionCouvert = q.value(gestionCouvert).toBool();
                list.append(data);
             }
        }
        else {
            qDebug()<< "Error: " << q.lastQuery() << q.lastError();
        }
        return list;
    }
    static void persist(const Activity &data)
    {
        QSqlQuery q;
        q.prepare("INSERT INTO t_pos_activite(id, code, libelle, nombre_table, icone_img, gestion_serveur, gestion_table, gestion_couvert) "
                    "VALUES (:id, :code, :libelle, :nombre_table, :icone_img, :gestion_serveur, :gestion_table, :gestion_couvert)");

        q.bindValue(":id", data.id);
        q.bindValue(":code", data.code);
        q.bindValue(":libelle", data.libelle);
        q.bindValue(":nombre_table", data.nombreTable);
        q.bindValue(":icone_img", data.iconeImg);
        q.bindValue(":gestion_serveur", data.isGestionServeur);
        q.bindValue(":gestion_table", data.isGestionTable);
        q.bindValue(":gestion_couvert", data.isGestionCouvert);
        if (!q.exec()){
            qDebug()<< "Error: " << q.lastQuery() << q.lastError();
        }
    }

    static void persist(QList<Activity> data)
    {
        QSqlDatabase::database().transaction();
        QSqlQuery q;
        q.prepare("DELETE FROM t_pos_activite");
        if (q.exec()) {
            foreach(const Activity &item, data) {
                persist(item);
            }
        }
        else {
            qDebug()<< "Error: " << q.lastQuery() << q.lastError();
        }
        QSqlDatabase::database().commit();
    }
}
