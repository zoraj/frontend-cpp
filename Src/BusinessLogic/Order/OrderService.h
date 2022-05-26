#pragma once

#include <QJsonObject>
#include <QJsonArray>
#include "Src/Application/Base/BaseService.h"
#include "Order.h"
//#include "Models/OrderCheckoutModel.h"

class OrderService : public BaseService
{
    Q_OBJECT
public:
    OrderService(const QString &apiKey, const QString &token);

    void fetchOrders();
    void postOrder(Order *order);
    void postOrderDetail(QList<OrderDetail *>orderDetails);
    //void postOrderCheckout(QList<OrderCheckoutModel *> orderCheckouts);
    void callback(constant::WSEndpoint endpoint, const QByteArray &response, int status) override;
signals:
    void fetchOrdersFinished(const QByteArray &response, int status);
    void postOrderFinished(const QByteArray &response, int status);
    void postOrderDetailFinished(const QByteArray &response, int status);
    void postOrderCheckoutFinished(const QByteArray &response, int status);
};

