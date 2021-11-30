#pragma once

#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QtSql/QSqlRecord>
#include <QDebug>
#include "OrderCheckoutModel.h"

namespace Cache::OrderCheckout {
    static QList<OrderCheckoutModel *> getByOrderHeader(int headerId)
    {
        QList<OrderCheckoutModel *> result;
        QSqlQuery q;
        q.prepare("SELECT * FROM t_pos_encaissement WHERE pos_note_entete_id = :headerId");
        q.bindValue(":headerId", headerId);
        if (q.exec()) {
            int id = q.record().indexOf("id");
            int posNoteEnteteId = q.record().indexOf("pos_note_entete_id");
            int modeEncaissementId = q.record().indexOf("mmc_mode_encaissement_id");
            int userId = q.record().indexOf("mmc_user_id");
            int dateEncaissement = q.record().indexOf("date_encaissement");
            int montantTTC = q.record().indexOf("montant_ttc");
            while (q.next()) {
                OrderCheckoutModel *checkout = new OrderCheckoutModel();
                checkout->id = q.value(id).toInt();
                checkout->noteEnteteId = q.value(posNoteEnteteId).toInt();
                checkout->modeEncaissementId = q.value(modeEncaissementId).toInt();
                checkout->userId = q.value(userId).toInt();
                checkout->dateEncaissement = QDateTime::fromString(q.value(dateEncaissement).toString(), "yyyy-MM-dd hh:mm:ss");
                checkout->montantTtc = q.value(montantTTC).toFloat();
                result.append(checkout);
            }
        }
        return result;

    }

    static void persist(OrderCheckoutModel *data)
    {
        QSqlQuery q;
        QString sql = "INSERT INTO t_pos_encaissement(pos_note_entete_id, mmc_mode_encaissement_id, mmc_user_id, montant_ttc, date_encaissement) "
                      "VALUES(:pos_note_entete_id, :mmc_mode_encaissement_id, :mmc_user_id, :montant_ttc, :date_encaissement)";
        q.prepare(sql);
        q.bindValue(":pos_note_entete_id", data->noteEnteteId);
        q.bindValue(":mmc_mode_encaissement_id", data->modeEncaissementId);
        q.bindValue(":mmc_user_id", data->userId);
        q.bindValue(":montant_ttc", data->montantTtc);
        q.bindValue(":date_encaissement", data->dateEncaissement.toString("yyyy-MM-dd hh:mm:ss"));
        if (!q.exec()){
            qDebug()<< "Error: " << q.lastQuery() << q.lastError();
        }

        // We must update order header status to 'SOLDE' after checking out
        sql = "UPDATE t_pos_note_entete SET etat = 'SOLDE' WHERE id = :id";
        q.prepare(sql);
        q.bindValue(":id", data->noteEnteteId);
        if (!q.exec()){
            qDebug()<< "Error: " << q.lastQuery() << q.lastError();
        }
    }

    static void persist(QList<OrderCheckoutModel *>data)
    {
        QSqlDatabase::database().transaction();
        foreach(OrderCheckoutModel *item, data) {
            persist(item);
        }
        QSqlDatabase::database().commit();
    }
}
