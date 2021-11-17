#pragma once

#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QtSql/QSqlRecord>
#include <QDebug>
#include "RoomModel.h"

namespace Cache::Room {

    static QList<RoomModel> getAll()
    {
        QList<RoomModel> list;
        QSqlQuery q;
        q.prepare("SELECT * FROM t_pms_chambre ORDER BY numero_chambre");
        if (q.exec()) {
            int id = q.record().indexOf("id");
            int numeroChambre = q.record().indexOf("numero_chambre");
            int numeroEtage = q.record().indexOf("numero_etage");
            int pmsTypeChambreId = q.record().indexOf("pms_type_chambre_id");
            int etatChambre = q.record().indexOf("etat_chambre");
            while (q.next()) {
                RoomModel data;
                data.id = q.value(id).toInt();
                data.numeroChambre = q.value(numeroChambre).toString();
                data.numeroEtage = q.value(numeroEtage).toInt();
                data.pmsTypeChambreId = q.value(pmsTypeChambreId).toInt();
                data.etatChambre = q.value(etatChambre).toString();
                list.append(data);
             }
        }
        else {
            qDebug()<< "Error: " << q.lastQuery() << q.lastError();
        }
        return list;
    }

    static void persist(const RoomModel &data)
    {
        QSqlQuery q;
        q.prepare("INSERT INTO t_pms_chambre(id, numero_chambre, numero_etage, pms_type_chambre_id, etat_chambre) "
                    "VALUES (:id, :numero_chambre, :numero_etage, :pms_type_chambre_id, :etat_chambre)");

        q.bindValue(":id", data.id);
        q.bindValue(":numero_chambre", data.numeroChambre);
        q.bindValue(":numero_etage", data.numeroEtage);
        q.bindValue(":pms_type_chambre_id", data.pmsTypeChambreId);
        q.bindValue(":etat_chambre", data.etatChambre);
        if (!q.exec()){
            qDebug()<< "Error: " << q.lastQuery() << q.lastError();
        }
    }

    static void persist(QList<RoomModel> data)
    {
        QSqlDatabase::database().transaction();
        QSqlQuery q;
        q.prepare("DELETE FROM t_pms_chambre");
        if (q.exec()) {
            foreach(const RoomModel &item, data) {
                persist(item);
            }
        }
        else {
            qDebug()<< "Error: " << q.lastQuery() << q.lastError();
        }
        QSqlDatabase::database().commit();
    }
}
