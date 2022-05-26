#pragma once

#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QtSql/QSqlRecord>
#include <QDebug>
#include "PosProduct.h"

namespace cache::pos_product {
    static QList<PosProduct> getAll()
    {
        QList<PosProduct> list;
        QSqlQuery q;
        q.prepare("SELECT * FROM t_pos_prestation ORDER BY libelle");
        if (q.exec()) {
            int id = q.record().indexOf("id");
            int code = q.record().indexOf("code");
            int libelle = q.record().indexOf("libelle");
            int prix = q.record().indexOf("prix");
            int groupeId = q.record().indexOf("pos_prestation_groupe_id");
            int couleur = q.record().indexOf("couleur");
            while (q.next()) {
                PosProduct data;
                data.id = q.value(id).toInt();
                data.code = q.value(code).toString();
                data.libelle = q.value(libelle).toString();
                data.prix = q.value(prix).toString().toFloat();
                data.posPrestationGroupeId = q.value(groupeId).toInt();
                data.couleur = q.value(couleur).toString();
                list.append(data);
             }
        }
        else {
            qDebug()<< "Error: " << q.lastQuery() << q.lastError();
        }
        return list;
    }

    static void persist(const PosProduct &data)
    {
        QSqlQuery q;
        q.prepare("INSERT INTO t_pos_prestation(id, code, libelle, pos_prestation_groupe_id, position_commande, type, prix, couleur, mmc_sous_famille_ca_id) "
                    "VALUES (:id, :code, :libelle, :pos_prestation_groupe_id, :position_commande, :type, :prix, :couleur, :mmc_sous_famille_ca_id)");

        q.bindValue(":id", data.id);
        q.bindValue(":code", data.code);
        q.bindValue(":libelle", data.libelle);
        q.bindValue(":pos_prestation_groupe_id", data.posPrestationGroupeId);
        q.bindValue(":position_commande", data.positionCommande);
        q.bindValue(":type", data.type);
        q.bindValue(":prix", data.prix);
        q.bindValue(":couleur", data.couleur);
        q.bindValue(":mmc_sous_famille_ca_id", data.mmcSousFamilleCaId);
        if (!q.exec()){
            qDebug()<< "Error: " << q.lastQuery() << q.lastError();
        }
    }

    static void persist(QList<PosProduct> data)
    {
        QSqlDatabase::database().transaction();
        QSqlQuery q;
        q.prepare("DELETE FROM t_pos_prestation");
        if (q.exec()) {
            foreach(const PosProduct &item, data) {
                persist(item);
            }
        }
        else {
            qDebug()<< "Error: " << q.lastQuery() << q.lastError();
        }
        QSqlDatabase::database().commit();
    }
}
