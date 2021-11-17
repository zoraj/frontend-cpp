#pragma once

#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QDebug>
#include "SeasonModel.h"

namespace SeasonCache {
    static void persist(const SeasonModel &data)
    {
        QSqlQuery q;
        q.prepare("INSERT INTO t_pms_saison(id, reference,libelle) VALUES (:id, :reference, :libelle)");
        q.bindValue(":id", data.id);
        q.bindValue(":reference", data.reference);
        q.bindValue(":libelle", data.libelle);
        if (!q.exec()){
            qDebug()<< "Error: " << q.lastQuery() << q.lastError();
        }
    }

    static void persist(QList<SeasonModel> data)
    {
        QSqlDatabase::database().transaction();
        QSqlQuery q;
        q.prepare("DELETE FROM t_pms_saison");
        if (q.exec()) {
            foreach(const SeasonModel &item, data) {
                persist(item);
            }
        }
        else {
            qDebug()<< "Error: " << q.lastQuery() << q.lastError();
        }
        QSqlDatabase::database().commit();
    }
}
