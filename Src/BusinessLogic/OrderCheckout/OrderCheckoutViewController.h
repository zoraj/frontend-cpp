#pragma once

#include "Src/Application/Base/BaseViewController.h"
#include "Src/Application/Manager/ApplicationManager.h"
#include "Src/BusinessLogic/CashingMode/CashingModeCache.h"

#include "Src/BusinessLogic/CashingMode/CashingModeListModel.h"
#include "Src/BusinessLogic/Order/OrderDetailListModel.h"
#include "OrderCheckoutListModel.h"

#include "Src/BusinessLogic/Order/OrderModel.h"
#include "OrderCheckoutModel.h"
#include "Src/BusinessLogic/CashingMode/CashingModeModel.h"

#include "OrderCheckoutCache.h"

class OrderCheckoutViewController : public BaseViewController
{
    Q_OBJECT
    Q_PROPERTY(CashingModeListModel *cashingModeListModel MEMBER cashingModeListModel)
    Q_PROPERTY(OrderDetailListModel *orderDetailListModel MEMBER orderDetailListModel)
    Q_PROPERTY(OrderCheckoutListModel *orderCheckoutListModel MEMBER orderCheckoutListModel)

    CashingModeListModel *cashingModeListModel;
    OrderDetailListModel *orderDetailListModel;
    OrderCheckoutListModel *orderCheckoutListModel;
    OrderModel *order;
    QList<OrderCheckoutModel *> orderCheckouts;

    OrderCheckoutModel *orderCheckout;
    void loadData();
    CashingModeModel getCashingModeById(int cashingModeId);
    float calculateTotalCheckout();
    float getBalance();
public:
    explicit OrderCheckoutViewController(QObject *parent = nullptr);

    void viewDidLoad() override;
    void viewDidUnload() override;
    void setOrder(OrderModel *orderModel);

public slots:
    void validateButtonClicked();
    void cashingModeSelected(int cashingModeId, float amount);
signals:
    void viewDidLoadFinished();
    void cashingModeSelectedCallback(bool callback);
    void checkoutDetailChanged(QString total);
    void validateButtonFinished();
};

