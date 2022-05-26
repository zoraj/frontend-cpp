#pragma once

#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QDebug>
#include "Season.h"

namespace cache::season {
    static void persist(const Season &data)
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

    static void persist(QList<Season> data)
    {
        QSqlDatabase::database().transaction();
        QSqlQuery q;
        q.prepare("DELETE FROM t_pms_saison");
        if (q.exec()) {
            foreach(const Season &item, data) {
                persist(item);
            }
        }
        else {
            qDebug()<< "Error: " << q.lastQuery() << q.lastError();
        }
        QSqlDatabase::database().commit();
    }
}
