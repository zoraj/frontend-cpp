#pragma once

#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QtSql/QSqlRecord>
#include <QDebug>
#include "PosGroupProduct.h"

namespace cache::pos_group_product {

    static QList<PosGroupProduct> getAll()
    {
        QList<PosGroupProduct> list;
        QSqlQuery q;
        q.prepare("SELECT * FROM t_pos_prestation_groupe ORDER BY libelle");
        if (q.exec()) {
            int id = q.record().indexOf("id");
            int code = q.record().indexOf("code");
            int libelle = q.record().indexOf("libelle");
            int iconeImg = q.record().indexOf("icone_img");
            while (q.next()) {
                PosGroupProduct data;
                data.id = q.value(id).toInt();
                data.code = q.value(code).toString();
                data.libelle = q.value(libelle).toString();
                data.iconeImg = q.value(iconeImg).toString();
                list.append(data);
             }
        }
        else {
            qDebug()<< "Error: " << q.lastQuery() << q.lastError();
        }
        return list;
    }
    static void persist(const PosGroupProduct &data)
    {
        QSqlQuery q;
        q.prepare("INSERT INTO t_pos_prestation_groupe(id, code, libelle, icone_img) "
                    "VALUES (:id, :code, :libelle, :icone_img)");

        q.bindValue(":id", data.id);
        q.bindValue(":code", data.code);
        q.bindValue(":libelle", data.libelle);
        q.bindValue(":icone_img", data.iconeImg);
        if (!q.exec()){
            qDebug()<< "Error: " << q.lastQuery() << q.lastError();
        }
    }

    static void persist(QList<PosGroupProduct> data)
    {
        QSqlDatabase::database().transaction();
        QSqlQuery q;
        q.prepare("DELETE FROM t_pos_prestation_groupe");
        if (q.exec()) {
            foreach(const PosGroupProduct &item, data) {
                persist(item);
            }
        }
        else {
            qDebug()<< "Error: " << q.lastQuery() << q.lastError();
        }
        QSqlDatabase::database().commit();
    }
}
