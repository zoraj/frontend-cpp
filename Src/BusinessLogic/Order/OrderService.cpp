#include "OrderService.h"

OrderService::OrderService(const QString &apiKey, const QString &token): BaseService(apiKey, token)
{

}

void OrderService::postOrder(Order *order)
{
    QJsonObject payload;
    payload.insert("numTable", order->numTable);
    payload.insert("nbCouvert", order->nbCouvert);
    payload.insert("posteUuid", order->posteUuid);
    payload.insert("service", "M");
    payload.insert("dateNote", order->dateNote.toString("yyyy-MM-dd hh:mm:ss"));
    payload.insert("posActiviteId", order->activiteId);
    payload.insert("etat", order->etat);

    endpoint = constant::WSEndpoint::ORDER_POST;
    HttpRequest req {fullPath(constant::WS_POS_ORDERS),
        "POST",
        &payload,
        apiKey,
        bearerToken
    };
    executeRequest(req);
}

void OrderService::fetchOrders()
{
    endpoint = constant::WSEndpoint::ORDER_GET;
    HttpRequest req {fullPath(constant::WS_POS_ORDERS),
        "GET",
        nullptr,
        apiKey,
        bearerToken
    };
    executeRequest(req);
}


// Order Detail
void OrderService::postOrderDetail(QList<OrderDetail *>orderDetails)
{
    endpoint = constant::WSEndpoint::ORDER_DETAIL_POST;

    QJsonArray payloadArray;
    foreach(auto item, orderDetails) {
        QJsonObject payload;
        payload.insert("ordre", 1);
        payload.insert("dateNote", item->dateNote.toString("yyyy-MM-dd hh:mm:ss"));
        payload.insert("posPrestationId", item->prestationId);
        payload.insert("posNoteEnteteId", item->noteEnteteId);
        payload.insert("posPrestationPrix", item->pu);
        payload.insert("qteCdeMarche", item->qte);
        payload.insert("qte", item->qte);
        payload.insert("venteType" , "NORMAL");
        payloadArray.append(payload);
    }


    HttpRequestForArray req {fullPath(constant::WS_POS_ORDER_DETAILS),
        "POST",
        &payloadArray,
        apiKey,
        bearerToken
    };
    executeRequest(req);
}
/*
void OrderService::postOrderCheckout(QList<OrderCheckoutModel *> orderCheckouts)
{
    endpoint = constant::WSEndpoint::ORDER_CHECKOUT_POST;
    QJsonArray payloadArray;
    foreach(auto item, orderCheckouts) {
        QJsonObject payload;
        payload.insert("mmcModeEncaissementId", item->modeEncaissementId);
        //payload.insert("mmcModeEncaissementId", item->dateNote.toString("yyyy-MM-dd hh:mm:ss"));
        payload.insert("posNoteEnteteId", item->noteEnteteId);
        payload.insert("mmcUserId", item->userId);
        payload.insert("montant", item->montantTtc);
        payloadArray.append(payload);
    }


    HttpRequestForArray req {fullPath(constant::WS_POST_ORDER_CHECKOUT),
        "POST",
        &payloadArray,
        apiKey,
        bearerToken
    };
    executeRequest(req);
}
*/
// Main callback methods
void OrderService::callback(constant::WSEndpoint endpoint, const QByteArray &response, int status)
{
    if (endpoint == constant::WSEndpoint::ORDER_GET)
        emit fetchOrdersFinished(response, status);
    if (endpoint == constant::WSEndpoint::ORDER_POST)
        emit postOrderFinished(response, status);
    if (endpoint == constant::WSEndpoint::ORDER_DETAIL_POST)
        emit postOrderDetailFinished(response, status);
    if (endpoint == constant::WSEndpoint::ORDER_CHECKOUT_POST)
        emit postOrderCheckoutFinished(response, status);

}
