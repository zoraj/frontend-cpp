#pragma once
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QtSql/QSqlRecord>
#include <QDebug>
#include "SubFamilyModel.h"

namespace cache::sub_family {
    static void persist(const SubFamilyModel &data)
    {
        QSqlQuery q;
        q.prepare("INSERT INTO t_mmc_sous_famille_ca(id, mmc_famille_ca_id, code, libelle, mmc_tva_id) "
                    "VALUES (:id, :mmc_famille_ca_id, :code, :libelle, :mmc_tva_id)");

        q.bindValue(":id", data.id);
        q.bindValue(":mmc_famille_ca_id", data.mmcFamilleCaId);
        q.bindValue(":code", data.code);
        q.bindValue(":libelle", data.libelle);
        q.bindValue(":mmc_tva_id", data.mmcTvaId);
        if (!q.exec()){
            qDebug()<< "Error: " << q.lastQuery() << q.lastError();
        }
    }

    static void persist(QList<SubFamilyModel> data)
    {
        QSqlDatabase::database().transaction();
        QSqlQuery q;
        q.prepare("DELETE FROM t_mmc_sous_famille_ca");
        if (q.exec()) {
            foreach(const SubFamilyModel &item, data) {
                persist(item);
            }
        }
        else {
            qDebug()<< "Error: " << q.lastQuery() << q.lastError();
        }
        QSqlDatabase::database().commit();
    }
}
