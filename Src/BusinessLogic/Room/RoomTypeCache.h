#pragma once

#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QSqlRecord>
#include <QDebug>
#include "RoomTypeModel.h"

namespace Cache::RoomType {
    static QList<RoomTypeModel> getAll()
    {
        QList<RoomTypeModel> list;
        QSqlQuery q;
        q.prepare("SELECT * FROM t_pms_type_chambre ORDER BY libelle");
        if (q.exec()) {
            int id = q.record().indexOf("id");
            int libelle = q.record().indexOf("libelle");
            int reference = q.record().indexOf("reference");
            int persMax = q.record().indexOf("pers_max");
            int persMin = q.record().indexOf("pers_min");
            int nbEnfant = q.record().indexOf("nb_enfant");
            while (q.next()) {
                RoomTypeModel data;
                data.id = q.value(id).toInt();
                data.libelle = q.value(libelle).toString();
                data.reference = q.value(reference).toInt();
                data.persMax = q.value(persMax).toInt();
                data.persMin = q.value(persMin).toInt();
                data.nbEnfant = q.value(nbEnfant).toInt();
                list.append(data);
             }
        }
        else {
            qDebug()<< "Error: " << q.lastQuery() << q.lastError();
        }
        return list;
    }

    static void persist(const RoomTypeModel &data)
    {
        QSqlQuery q;
        q.prepare("INSERT INTO t_pms_type_chambre(id, reference,libelle, pers_min, pers_max, nb_enfant, pms_categorie_chambre_id) "
                    "VALUES (:id, :reference, :libelle, :pers_min, :pers_max, :nb_enfant, :pms_categorie_chambre_id)");
        q.bindValue(":id", data.id);
        q.bindValue(":reference", data.reference);
        q.bindValue(":libelle", data.libelle);
        q.bindValue(":pers_min", data.persMin);
        q.bindValue(":pers_max", data.persMax);
        q.bindValue(":nb_enfant", data.nbEnfant);
        q.bindValue(":pms_categorie_chambre_id", data.pmsCategorieChambreId);
        if (!q.exec()){
            qDebug()<< "Error: " << q.lastQuery() << q.lastError();
        }
    }

    static void persist(QList<RoomTypeModel> data)
    {
        QSqlDatabase::database().transaction();
        QSqlQuery q;
        q.prepare("DELETE FROM t_pms_type_chambre");
        if (q.exec()) {
            foreach(const RoomTypeModel &item, data) {
                persist(item);
            }
        }
        else {
            qDebug()<< "Error: " << q.lastQuery() << q.lastError();
        }
        QSqlDatabase::database().commit();
    }
}
