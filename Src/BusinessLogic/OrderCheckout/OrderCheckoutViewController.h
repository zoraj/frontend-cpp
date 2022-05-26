#pragma once

#include "Src/Application/Base/BaseViewController.h"
#include "Src/Application/Manager/ApplicationManager.h"
#include "Src/BusinessLogic/CashingMode/CashingModeCache.h"

#include "Src/BusinessLogic/CashingMode/CashingModeListModel.h"
#include "Src/BusinessLogic/Order/OrderDetailListModel.h"
#include "OrderCheckoutListModel.h"

#include "Src/BusinessLogic/Order/Order.h"
#include "Src/BusinessLogic/Order/OrderCache.h"
#include "OrderCheckout.h"
#include "Src/BusinessLogic/CashingMode/CashingMode.h"

#include "OrderCheckoutCache.h"

class OrderCheckoutViewController : public BaseViewController
{
    Q_OBJECT
    Q_PROPERTY(CashingModeListModel *cashingModeListModel MEMBER cashingModeListModel)
    Q_PROPERTY(OrderDetailListModel *orderDetailListModel MEMBER orderDetailListModel)
    Q_PROPERTY(OrderCheckoutListModel *orderCheckoutListModel MEMBER orderCheckoutListModel)

    int orderId_;
    CashingModeListModel *cashingModeListModel;
    OrderDetailListModel *orderDetailListModel;
    OrderCheckoutListModel *orderCheckoutListModel;
    Order *order;
    QList<OrderCheckout *> orderCheckouts;

    OrderCheckout *orderCheckout;
    void loadData();
    CashingMode getCashingModeById(int cashingModeId);
    float calculateTotalCheckout();
    float getBalance();
public:
    explicit OrderCheckoutViewController(QObject *parent = nullptr);

    void viewDidLoad() override;
    void viewDidUnload() override;
public slots:
    void validateButton_Clicked();
    void cashingMode_Selected(int cashingModeId, float amount);
    void setOrderId(int id);
signals:
    void viewDidLoadFinished();
    void cashingModeSelectedFinished();
    void checkoutDetailChanged(QString total);
    void validateButtonClickedFinished();
};

