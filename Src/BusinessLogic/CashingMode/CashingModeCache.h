#pragma once

#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QtSql/QSqlRecord>
#include <QDebug>

#include "CashingMode.h"

namespace cache::cashing_mode {
    static QList<CashingMode> getAll()
    {
        QList<CashingMode> list;
        QSqlQuery q;
        q.prepare("SELECT * FROM t_mmc_mode_encaissement ORDER BY libelle");
        if (q.exec()) {
            int id = q.record().indexOf("id");
            int code = q.record().indexOf("code");
            int libelle = q.record().indexOf("libelle");
            int nature = q.record().indexOf("nature");
            while (q.next()) {
                CashingMode data;
                data.id = q.value(id).toInt();
                data.code = q.value(code).toString();
                data.libelle = q.value(libelle).toString();
                data.nature = q.value(nature).toString();
                list.append(data);
             }
        }
        else {
            qDebug()<< "Error: " << q.lastQuery() << q.lastError();
        }
        return list;
    }

    static void persist(const CashingMode &data)
    {
        QSqlQuery q;
        q.prepare("INSERT INTO t_mmc_mode_encaissement(id, code, libelle, nature) "
                    "VALUES (:id, :code, :libelle, :nature)");

        q.bindValue(":id", data.id);
        q.bindValue(":code", data.code);
        q.bindValue(":libelle", data.libelle);
        q.bindValue(":nature", data.nature);
        if (!q.exec()){
            qDebug()<< "Error: " << q.lastQuery() << q.lastError();
        }
    }

    static void persist(QList<CashingMode> data)
    {
        QSqlDatabase::database().transaction();
        QSqlQuery q;
        q.prepare("DELETE FROM t_mmc_mode_encaissement");
        if (q.exec()) {
            foreach(const CashingMode &item, data) {
                persist(item);
            }
        }
        else {
            qDebug()<< "Error: " << q.lastQuery() << q.lastError();
        }
        QSqlDatabase::database().commit();
    }
}
