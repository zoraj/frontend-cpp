#pragma once

#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QtSql/QSqlRecord>
#include <QDebug>
#include "TopUp.h"

namespace cache::cooking {
    static QList<Cooking> getAll()
    {
        QList<Cooking> list;
        QSqlQuery q;
        q.prepare("SELECT * FROM t_pos_cuisson ORDER BY code");
        if (q.exec()) {
            int id = q.record().indexOf("id");
            int code = q.record().indexOf("code");
            int libelle = q.record().indexOf("libelle");
            while (q.next()) {
                Cooking data;
                data.id = q.value(id).toInt();
                data.code = q.value(code).toString();
                data.libelle = q.value(libelle).toString();
                list.append(data);
             }
        }
        else {
            qDebug()<< "Error: " << q.lastQuery() << q.lastError();
        }
        return list;
    }
    static void persist(const Cooking &data)
    {
        QSqlQuery q;
        q.prepare("INSERT INTO t_pos_cuisson(id, code, libelle) "
                    "VALUES (:id, :code, :libelle)");

        q.bindValue(":id", data.id);
        q.bindValue(":code", data.code);
        q.bindValue(":libelle", data.libelle);
        if (!q.exec()){
            qDebug()<< "Error: " << q.lastQuery() << q.lastError();
        }
    }

    static void persist(QList<Cooking> data)
    {
        QSqlDatabase::database().transaction();
        QSqlQuery q;
        q.prepare("DELETE FROM t_pos_cuisson");
        if (q.exec()) {
            foreach(const Cooking &item, data) {
                persist(item);
            }
        }
        else {
            qDebug()<< "Error: " << q.lastQuery() << q.lastError();
        }
        QSqlDatabase::database().commit();
    }
}
