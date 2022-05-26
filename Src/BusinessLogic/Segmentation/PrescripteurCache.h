#pragma once

#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QtSql/QSqlRecord>
#include <QDebug>
#include "Prescripteur.h"

namespace cache::prescripteur {
    static QList<Prescripteur> getAll()
    {
        QList<Prescripteur> list;
        QSqlQuery q;
        q.prepare("SELECT * FROM t_pms_prescripteur ORDER BY libelle");
        if (q.exec()) {
            int id = q.record().indexOf("id");
            int code = q.record().indexOf("code");
            int libelle = q.record().indexOf("libelle");
            while (q.next()) {
                Prescripteur data;
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

    static void persist(const Prescripteur &data)
    {
        QSqlQuery q;
        q.prepare("INSERT INTO t_pms_prescripteur(id, code, libelle) VALUES (:id, :code, :libelle)");
        q.bindValue(":id", data.id);
        q.bindValue(":code", data.code);
        q.bindValue(":libelle", data.libelle);
        if (!q.exec()){
            qDebug()<< "Error: " << q.lastQuery() << q.lastError();
        }
    }

    static void persist(QList<Prescripteur> data)
    {
        QSqlDatabase::database().transaction();
        QSqlQuery q;
        q.prepare("DELETE FROM t_pms_prescripteur");
        if (q.exec()) {
            foreach(const Prescripteur &item, data) {
                persist(item);
            }
        }
        else {
            qDebug()<< "Error: " << q.lastQuery() << q.lastError();
        }
        QSqlDatabase::database().commit();
    }
}
