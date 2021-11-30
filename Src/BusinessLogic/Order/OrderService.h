#pragma once

#include <QJsonObject>
#include <QJsonArray>
#include "Src/Application/Base/BaseService.h"
#include "OrderModel.h"
//#include "Models/OrderCheckoutModel.h"

class OrderService : public BaseService
{
    Q_OBJECT
public:
    OrderService(const QString &apiKey, const QString &token);

    void fetchOrders();
    void postOrder(OrderModel *order);
    void postOrderDetail(QList<OrderDetailModel *>orderDetails);
    //void postOrderCheckout(QList<OrderCheckoutModel *> orderCheckouts);
    void callback(Constant::WSEndpoint endpoint, const QByteArray &response, int status) override;
signals:
    void fetchOrdersFinished(const QByteArray &response, int status);
    void postOrderFinished(const QByteArray &response, int status);
    void postOrderDetailFinished(const QByteArray &response, int status);
    void postOrderCheckoutFinished(const QByteArray &response, int status);
};

