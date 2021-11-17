#pragma once

#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QtSql/QSqlRecord>
#include <QDebug>
#include "ClientModel.h"

namespace Cache::Client {

    static QList<ClientModel> getAll()
    {
        QList<ClientModel> list;
        QSqlQuery q;
        q.prepare("SELECT * FROM t_mmc_client ORDER BY nom");
        if (q.exec()) {
            int id = q.record().indexOf("id");
            int code = q.record().indexOf("code");
            int nom = q.record().indexOf("nom");
            while (q.next()) {
                ClientModel data;
                data.id = q.value(id).toInt();
                data.code = q.value(code).toString();
                data.nom = q.value(nom).toString();
                list.append(data);
             }
        }
        else {
            qDebug()<< "Error: " << q.lastQuery() << q.lastError();
        }
        return list;
    }

    static void persist(const ClientModel &data)
    {
        QSqlQuery q;
        q.prepare("INSERT INTO t_mmc_client(id, code, nom, prenom, adresse, ville, pays, pms_prescripteur_id, mmc_type_client_id, mmc_segment_client_id) "
                    "VALUES (:id, :code, :nom, :prenom, :adresse, :ville, :pays, :pmsPrescripteurId, :mmcTypeClientId, :mmcSegmentClientId)");

        q.bindValue(":id", data.id);
        q.bindValue(":code", data.code);
        q.bindValue(":nom", data.nom);
        q.bindValue(":prenom", data.prenom);
        q.bindValue(":adresse", data.adresse);
        q.bindValue(":ville", data.ville);
        q.bindValue(":pays", data.pays);
        q.bindValue(":pmsPrescripteurId", data.pmsPrescripteurId);
        q.bindValue(":mmcTypeClientId", data.mmcTypeClientId);
        q.bindValue(":mmcSegmentClientId", data.mmcSegmentClientId);
        if (!q.exec()){
            qDebug()<< "Error: " << q.lastQuery() << q.lastError();
        }
    }

    static void persist(QList<ClientModel> data)
    {
        QSqlDatabase::database().transaction();
        QSqlQuery q;
        q.prepare("DELETE FROM t_mmc_client");
        if (q.exec()) {
            foreach(const ClientModel &item, data) {
                persist(item);
            }

        }
        else {
            qDebug()<< "Error: " << q.lastQuery() << q.lastError();
        }
        QSqlDatabase::database().commit();
    }
}
