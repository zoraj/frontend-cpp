#pragma once

#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QtSql/QSqlRecord>
#include <QDebug>
#include "Vat.h"

namespace cache::vat {
    static void persist(const Vat &data)
    {
        QSqlQuery q;
        q.prepare("INSERT INTO t_mmc_tva(id, date_effective, valeur) "
                    "VALUES (:id, :date_effective, :valeur)");

        q.bindValue(":id", data.id);
        q.bindValue(":date_effective", data.dateEffective);
        q.bindValue(":valeur", data.valeur);
        if (!q.exec()){
            qDebug()<< "Error: " << q.lastQuery() << q.lastError();
        }
    }

    static void persist(QList<Vat> data)
    {
        QSqlDatabase::database().transaction();
        QSqlQuery q;
        q.prepare("DELETE FROM t_mmc_tva");
        if (q.exec()) {
            foreach(const Vat &item, data) {
                persist(item);
            }
        }
        else {
            qDebug()<< "Error: " << q.lastQuery() << q.lastError();
        }
        QSqlDatabase::database().commit();
    }
}
