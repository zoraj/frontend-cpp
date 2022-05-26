#pragma once

#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QtSql/QSqlRecord>
#include <QDebug>
#include "TopUp.h"

namespace cache::accompaniment {
    static QList<Accompaniment> getAll()
    {
        QList<Accompaniment> list;
        QSqlQuery q;
        q.prepare("SELECT * FROM t_pos_accompagnement ORDER BY code");
        if (q.exec()) {
            int id = q.record().indexOf("id");
            int code = q.record().indexOf("code");
            int libelle = q.record().indexOf("libelle");
            while (q.next()) {
                Accompaniment data;
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
    static void persist(const Accompaniment &data)
    {
        QSqlQuery q;
        q.prepare("INSERT INTO t_pos_accompagnement(id, code, libelle) "
                    "VALUES (:id, :code, :libelle)");

        q.bindValue(":id", data.id);
        q.bindValue(":code", data.code);
        q.bindValue(":libelle", data.libelle);
        if (!q.exec()){
            qDebug()<< "Error: " << q.lastQuery() << q.lastError();
        }
    }

    static void persist(QList<Accompaniment> data)
    {
        QSqlDatabase::database().transaction();
        QSqlQuery q;
        q.prepare("DELETE FROM t_pos_accompagnement");
        if (q.exec()) {
            foreach(const Accompaniment &item, data) {
                persist(item);
            }
        }
        else {
            qDebug()<< "Error: " << q.lastQuery() << q.lastError();
        }
        QSqlDatabase::database().commit();
    }
}
