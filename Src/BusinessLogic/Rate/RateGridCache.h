#pragma once

#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QtSql/QSqlRecord>
#include <QDebug>
#include "RateGrid.h"


namespace cache::rate_grid {
    static QList<RateGrid> getAll()
    {
        QList<RateGrid> list;
        QSqlQuery q;
        q.prepare("SELECT * FROM t_pms_tarif_grille ORDER BY nom");
        if (q.exec()) {
            int id = q.record().indexOf("id");
            int nom = q.record().indexOf("nom");
            int reference = q.record().indexOf("reference");
            while (q.next()) {
                RateGrid data;
                data.id = q.value(id).toInt();
                data.nom = q.value(nom).toString();
                data.reference = q.value(reference).toString();
                list.append(data);
             }
        }
        else {
            qDebug()<< "Error: " << q.lastQuery() << q.lastError();
        }
        return list;
    }

    static void persist(const RateGrid &data)
    {
        QSqlQuery q;
        q.prepare("INSERT INTO t_pms_tarif_grille(id, nom, reference, pms_saison_id, pms_sous_saison_id) "
                    "VALUES (:id, :nom, :reference, :saisonId, :sousSaisonId)");

        q.bindValue(":id", data.id);
        q.bindValue(":nom", data.nom);
        q.bindValue(":reference", data.reference);
        q.bindValue(":saisonId", data.saisonId);
        q.bindValue(":sousSaisonId", data.sousSaisonId);
        if (!q.exec()){
            qDebug()<< "Error: " << q.lastQuery() << q.lastError();
        }
    }

    static void persist(QList<RateGrid> data)
    {
        QSqlDatabase::database().transaction();
        QSqlQuery q;
        q.prepare("DELETE FROM t_pms_tarif_grille");
        if (q.exec()) {
            foreach(const RateGrid &item, data) {
                persist(item);
            }
        }
        else {
            qDebug()<< "Error: " << q.lastQuery() << q.lastError();
        }
        QSqlDatabase::database().commit();
    }
}
