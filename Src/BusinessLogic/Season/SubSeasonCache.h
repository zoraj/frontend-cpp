#pragma once

#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QDebug>
#include "SubSeasonModel.h"

namespace Cache::SubSeason {
    static void persist(const SubSeasonModel &data)
    {
        QSqlQuery q;
        q.prepare("INSERT INTO t_pms_sous_saison(id, reference,libelle, pms_saison_id, date_debut, date_fin) "
                  "VALUES (:id, :reference, :libelle, :pms_saison_id, :date_debut, :date_fin)");
        q.bindValue(":id", data.id);
        q.bindValue(":reference", data.reference);
        q.bindValue(":libelle", data.libelle);
        q.bindValue(":pms_saison_id", data.pmsSaisonId);
        q.bindValue(":date_debut", data.dateDebut);
        q.bindValue(":date_fin", data.dateFin);
        if (!q.exec()){
            qDebug()<< "Error: " << q.lastQuery() << q.lastError();
        }
    }

    static void persist(QList<SubSeasonModel> data)
    {
        QSqlDatabase::database().transaction();
        QSqlQuery q;
        q.prepare("DELETE FROM t_pms_sous_saison");
        if (q.exec()) {
            foreach(const SubSeasonModel &item, data) {
                persist(item);
            }
        }
        else {
            qDebug()<< "Error: " << q.lastQuery() << q.lastError();
        }
        QSqlDatabase::database().commit();
    }
}
