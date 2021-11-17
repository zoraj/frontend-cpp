#pragma once

#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QDebug>
#include "RoomCategoryModel.h"

namespace Cache::RoomCategory {
    static void persist(const RoomCategoryModel &data)
    {
        QSqlQuery q;
        q.prepare("INSERT INTO t_pms_categorie_chambre(id, reference,libelle) VALUES (:id, :reference, :libelle)");
        q.bindValue(":id", data.id);
        q.bindValue(":reference", data.reference);
        q.bindValue(":libelle", data.libelle);
        if (!q.exec()){
            qDebug()<< "Error: " << q.lastQuery() << q.lastError();
        }
    }

    static void persist(QList<RoomCategoryModel> data)
    {
        QSqlDatabase::database().transaction();
        QSqlQuery q;
        q.prepare("DELETE FROM t_pms_categorie_chambre");
        if (q.exec()) {
            foreach(const RoomCategoryModel &item, data) {
                persist(item);
            }
        }
        else {
            qDebug()<< "Error: " << q.lastQuery() << q.lastError();
        }
        QSqlDatabase::database().commit();
    }
}
