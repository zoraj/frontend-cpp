#pragma once

#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QtSql/QSqlRecord>
#include <QDebug>

#include "Src/Application/Util/Constant.h"
#include "OrderModel.h"

namespace OrderCache {
    static OrderModel *getById(int id)
    {
        OrderModel *data = new OrderModel();
        QSqlQuery q;
        q.prepare("SELECT * FROM t_pos_note_entete WHERE id = :id");
        q.bindValue(":id", id);
        if (q.exec()) {
            int id = q.record().indexOf("id");
            int numTable = q.record().indexOf("num_table");
            int nbCouvert = q.record().indexOf("nb_couvert");
            int activiteId = q.record().indexOf("pos_activite_id");
            int dateNote = q.record().indexOf("date_note");
            int uuid = q.record().indexOf("poste_uuid");
            int etat = q.record().indexOf("etat");

            if (q.next()) {
                data->id = q.value(id).toInt();
                data->numTable = q.value(numTable).toInt();
                data->nbCouvert = q.value(nbCouvert).toInt();
                data->activiteId = q.value(activiteId).toInt();
                data->dateNote = QDateTime::fromString(q.value(dateNote).toString(), "yyyy-MM-dd hh:mm:ss");
                data->posteUuid = q.value(uuid).toString();
                data->etat = q.value(etat).toString();

                // Let's see if there is some details
                q.prepare("SELECT * FROM t_pos_note_detail WHERE pos_note_entete_id =:headerId ORDER BY id");
                q.bindValue(":headerId", data->id);
                if (q.exec()) {
                    int id = q.record().indexOf("id");
                    int dateNote = q.record().indexOf("date_note");
                    int prestationId = q.record().indexOf("pos_prestation_id");
                    int pu = q.record().indexOf("pos_prestation_prix");
                    int qte = q.record().indexOf("qte");
                    int qteCdeMarche = q.record().indexOf("qte_cde_marche");
                    int ordre = q.record().indexOf("ordre");
                    int venteType = q.record().indexOf("vente_type");
                    int enteteId = q.record().indexOf("pos_note_entete_id");

                    while (q.next()) {
                        OrderDetailModel *detail = new OrderDetailModel();
                        detail->id = q.value(id).toInt();
                        detail->prestationId = q.value(prestationId).toInt();
                        detail->prestationLibelle = "";
                        detail->dateNote = QDateTime::fromString(q.value(dateNote).toString(), "yyyy-MM-dd hh:mm:ss");
                        detail->prix = 0.00f;
                        detail->qte = q.value(qte).toInt();
                        detail->isVAE = false;
                        detail->isOffert = false;
                        detail->total = 0.00f;
                        detail->pu = q.value(pu).toFloat();
                        detail->noteEnteteId = q.value(enteteId).toInt();
                        data->orderDetail.append(detail);
                     }
                }
                else {
                    qDebug()<< "Error: " << q.lastQuery() << q.lastError();
                }
            }
        }
        else {
            qDebug()<< "Error: " << q.lastQuery() << q.lastError();
            return nullptr;
        }
        return data;
    }

    static bool remove(int id)
    {
        QSqlDatabase::database().transaction();
        QSqlQuery q;
        // Note detail
        q.prepare("DELETE FROM t_pos_note_detail WHERE pos_note_entete_id = :pos_note_entete_id");
        q.bindValue(":pos_note_entete_id", id);
        if (!q.exec()) {
            qDebug()<< "Error: " << q.lastQuery() << q.lastError();
            return false;
        }
        // Checkout
        q.prepare("DELETE FROM t_pos_encaissement WHERE pos_note_entete_id = :pos_note_entete_id");
        q.bindValue(":pos_note_entete_id", id);
        if (!q.exec()) {
            qDebug()<< "Error: " << q.lastQuery() << q.lastError();
            return false;
        }
        // Note header
        q.prepare("DELETE FROM t_pos_note_entete WHERE id = :id");
        q.bindValue(":id", id);
        if (!q.exec()) {
            qDebug()<< "Error: " << q.lastQuery() << q.lastError();
            return false;
        }
        QSqlDatabase::database().commit();

        return true;
    }

    static QList<OrderModel *> getAll()
    {
        QList<OrderModel *> list;
        QSqlQuery q;
        q.prepare("SELECT * FROM t_pos_note_entete ORDER BY date_note");
        if (q.exec()) {
            int id = q.record().indexOf("id");
            int numTable = q.record().indexOf("num_table");
            int nbCouvert = q.record().indexOf("nb_couvert");
            int activiteId = q.record().indexOf("pos_activite_id");
            int uuid = q.record().indexOf("poste_uuid");
            int etat = q.record().indexOf("etat");

            while (q.next()) {
                OrderModel *data = new OrderModel();
                data->id = q.value(id).toInt();
                data->numTable = q.value(numTable).toInt();
                data->nbCouvert = q.value(nbCouvert).toInt();
                data->activiteId = q.value(activiteId).toInt();
                data->posteUuid = q.value(uuid).toString();
                data->etat = q.value(etat).toString();
                list.append(data);
             }
        }
        else {
            qDebug()<< "Error: " << q.lastQuery() << q.lastError();
        }
        return list;
    }

    static QList<OrderModel *> getByActivity(int activityId, int numTable = 0)
    {
        QList<OrderModel *> list;
        QSqlQuery q;
        if (numTable != 0) {
            q.prepare("SELECT * FROM t_pos_note_entete WHERE etat = 'ENCOURS' AND pos_activite_id = :pos_activite_id AND num_table=:num_table");
            q.bindValue(":pos_activite_id", activityId);
            q.bindValue(":num_table", numTable);
        }
        else {
            q.prepare("SELECT * FROM t_pos_note_entete  WHERE etat = 'ENCOURS' AND pos_activite_id = :pos_activite_id ORDER BY date_note");
            q.bindValue(":pos_activite_id", activityId);
        }

        if (q.exec()) {
            int id = q.record().indexOf("id");
            int numTable = q.record().indexOf("num_table");
            int nbCouvert = q.record().indexOf("nb_couvert");
            int activiteId = q.record().indexOf("pos_activite_id");
            int uuid = q.record().indexOf("poste_uuid");
            int etat = q.record().indexOf("etat");
            while (q.next()) {
                OrderModel *data = new OrderModel();
                data->id = q.value(id).toInt();
                data->numTable = q.value(numTable).toInt();
                data->nbCouvert = q.value(nbCouvert).toInt();
                data->activiteId = q.value(activiteId).toInt();
                data->posteUuid = q.value(uuid).toString();
                data->etat = q.value(etat).toString();
                list.append(data);
             }
        }
        else {
            qDebug()<< "Error: " << q.lastQuery() << q.lastError();
        }

        // Let's see if there is some details
        if (numTable != 0 && !list.isEmpty()) {
            q.prepare("SELECT * FROM t_pos_note_detail WHERE pos_note_entete_id =:headerId ORDER BY id");
            q.bindValue(":headerId", list.first()->id);
            if (q.exec()) {
                int id = q.record().indexOf("id");
                int dateNote = q.record().indexOf("date_note");
                int prestationId = q.record().indexOf("pos_prestation_id");
                int pu = q.record().indexOf("pos_prestation_prix");
                int qte = q.record().indexOf("qte");
                int qteCdeMarche = q.record().indexOf("qte_cde_marche");
                int ordre = q.record().indexOf("ordre");
                int venteType = q.record().indexOf("vente_type");
                int enteteId = q.record().indexOf("pos_note_entete_id");

                while (q.next()) {
                    OrderDetailModel *data = new OrderDetailModel();
                    data->id = q.value(id).toInt();
                    data->prestationId = q.value(prestationId).toInt();
                    data->prestationLibelle = "";
                    data->prix = 0.00f;
                    data->qte = q.value(qte).toInt();
                    data->isVAE = false;
                    data->isOffert = false;
                    data->total = 0.00f;
                    data->pu = q.value(pu).toFloat();
                    data->noteEnteteId = q.value(enteteId).toInt();
                    list.first()->orderDetail.append(data);
                 }
            }
            else {
                qDebug()<< "Error: " << q.lastQuery() << q.lastError();
            }
        }


        return list;
    }

    static int persist(const OrderModel &data)
    {
        QSqlDatabase::database().transaction();
        QSqlQuery q;
        int headerId = Constant::UNDEFINED_INT;
        QString sql = data.id == Constant::UNDEFINED_INT ?
                    "INSERT INTO t_pos_note_entete(date_note, num_table, nb_couvert, poste_uuid, service, pos_activite_id, mmc_user_id) "
                    "VALUES (:date_note, :num_table, :nb_couvert, :poste_uuid, :service, :pos_activite_id, :mmc_user_id)" :
                    "UPDATE t_pos_note_entete SET (id, date_note, num_table, nb_couvert, poste_uuid, service, pos_activite_id) "
                    "VALUES (:id, :date_note, :num_table, :nb_couvert, :poste_uuid, :service, :pos_activite_id) WHERE id =:id";
        q.prepare(sql);


        if (data.id != Constant::UNDEFINED_INT)
            q.bindValue(":id", data.id);
        q.bindValue(":date_note", data.dateNote.toString("yyyy-MM-dd hh:mm:ss"));
        q.bindValue(":num_table", data.numTable);
        q.bindValue(":nb_couvert", data.nbCouvert);
        q.bindValue(":poste_uuid", data.posteUuid);
        q.bindValue(":service", data.service);
        q.bindValue(":pos_activite_id", data.activiteId);
        q.bindValue(":mmc_user_id", data.userId);
        if (q.exec()){
            headerId = q.lastInsertId().toInt();

            // Order detail
            foreach(auto orderDetail, data.orderDetail) {
                sql = "INSERT INTO t_pos_note_detail(date_note, pos_prestation_id, pos_note_entete_id, pos_prestation_prix, qte, qte_cde_marche, ordre, vente_type)"
                              "VALUES(:date_note, :pos_prestation_id, :pos_note_entete_id, :pos_prestation_prix, :qte, :qte_cde_marche, :ordre, :vente_type)";
                q.prepare(sql);
                q.bindValue(":date_note", data.dateNote.toString("yyyy-MM-dd hh:mm:ss"));
                q.bindValue(":pos_prestation_id", orderDetail->prestationId);
                q.bindValue(":pos_note_entete_id", headerId);
                q.bindValue(":pos_prestation_prix", orderDetail->prix);
                q.bindValue(":qte", orderDetail->qte);
                q.bindValue(":qte_cde_marche", orderDetail->qte);
                q.bindValue(":vente_type", "NORMAL");
                // TODO: Remove hardcoded value
                q.bindValue(":ordre", 1);
                if (!q.exec()){
                    qDebug()<< "Error: " << q.lastQuery() << q.lastError();
                }
            }
        }
        else {
            qDebug()<< "Error: " << q.lastQuery() << q.lastError();
        }
        QSqlDatabase::database().commit();

        return headerId;
    }

    static void persist(QList<OrderModel *> data)
    {
        QSqlQuery q;
        q.prepare("DELETE FROM t_pos_note_entete");
        if (q.exec()) {
            foreach(const OrderModel *item, data) {
                persist(*item);
            }
        }
        else {
            qDebug()<< "Error: " << q.lastQuery() << q.lastError();
        }
    }
}
