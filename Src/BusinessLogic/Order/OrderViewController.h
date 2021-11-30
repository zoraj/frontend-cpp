#pragma once

#include <QSortFilterProxyModel>
#include "Src/Application/Base/BaseViewController.h"
#include "Src/Application/Base/BaseViewController.h"
#include "Src/Application/Manager/ApplicationManager.h"
#include "Src/BusinessLogic/Order/OrderModel.h"
#include "Src/BusinessLogic/Product/PosGroupProductListModel.h"
#include "Src/BusinessLogic/Product/PosProductListModel.h"
#include "Src/BusinessLogic/Order/OrderDetailListModel.h"
#include "Src/BusinessLogic/Client/ClientListModel.h"
#include "Src/BusinessLogic/TopUp/CookingListModel.h"
#include "Src/BusinessLogic/TopUp/AccompanimentListModel.h"

#include "Src/BusinessLogic/Product/PosGroupProductModel.h"
#include "Src/BusinessLogic/Setting/SettingModel.h"

#include "Src/BusinessLogic/Product/PosGroupProductCache.h"
#include "Src/BusinessLogic/Product/PosProductCache.h"
#include "Src/BusinessLogic/Order/OrderCache.h"
#include "Src/BusinessLogic/Setting/SettingCache.h"
#include "Src/BusinessLogic/Client/ClientCache.h"
#include "Src/BusinessLogic/TopUp/CookingCache.h"
#include "Src/BusinessLogic/TopUp/AccompanimentCache.h"

//#include "Controllers/CheckOutViewController.h"

//#include "Workers/PrinterWorker.h"

class OrderViewController : public BaseViewController
{
    Q_OBJECT
    Q_PROPERTY(float grossTotal MEMBER grossTotal_)
    Q_PROPERTY(float netTotal MEMBER netTotal_)
    Q_PROPERTY(PosGroupProductListModel *groupProductListModel MEMBER groupProductListModel_)
    Q_PROPERTY(PosProductListModel *productListModel MEMBER productListModel_)
    Q_PROPERTY(OrderDetailListModel *orderDetailListModel MEMBER orderDetailListModel_)
    Q_PROPERTY(CookingListModel *cookingListModel MEMBER cookingListModel_)
    Q_PROPERTY(AccompanimentListModel *accompanimentListModel MEMBER accompanimentListModel_)
    Q_PROPERTY(ClientListModel *clientListModel MEMBER clientListModel_)
    Q_PROPERTY(OrderModel *order MEMBER order_)
    Q_PROPERTY(QSortFilterProxyModel *productListProxyModel MEMBER productListProxyModel_ CONSTANT)
    Q_PROPERTY(QSortFilterProxyModel *productSearchListProxyModel MEMBER productSearchListProxyModel_ CONSTANT)
    Q_PROPERTY(QSortFilterProxyModel *clientListProxyModel MEMBER clientListProxyModel_ CONSTANT)

    float grossTotal_;
    float vatTotal_;
    float netTotal_;
    OrderModel *order_;
    PosGroupProductListModel *groupProductListModel_;
    PosProductListModel *productListModel_;
    OrderDetailListModel *orderDetailListModel_;
    ClientListModel *clientListModel_;
    CookingListModel *cookingListModel_;
    AccompanimentListModel *accompanimentListModel_;
    QSortFilterProxyModel *productListProxyModel_;
    QSortFilterProxyModel *productSearchListProxyModel_;
    QSortFilterProxyModel *clientListProxyModel_;

    //QSharedPointer<CheckOutViewController> checkoutViewController;

    int cacheOrder();
    PosProductModel getProductById(int productId);
    void loadData();
    void recalculateTotal();
    void initNewOrder();
public:
    OrderViewController(QObject *parent = nullptr);

    Q_INVOKABLE
    void openOrder(int orderId, int numTable);
    Q_INVOKABLE
    void viewDidLoad() override;
    Q_INVOKABLE
    void viewDidUnload() override;

    Q_INVOKABLE
    void setOrder(OrderModel *);
    Q_INVOKABLE
    void resetOrder();

public slots:
    void groupProductSelected(int productGroupId);
    void checkoutButtonClicked();
    void productSelected(int productId, int qty);
    void quitButtonClicked();
    void clientSearchTextChanged(const QString &keyword);
    void productSearchTextChanged(const QString &keyword);
    void deleteOrderButtonClicked(int productId, int qty);
    void offertOrderButtonClicked(int productId, int qty);
    void ticketButtonClicked();
signals:
    void viewDidLoadFinished();
    void orderChanged(OrderModel *order);
    void orderDetailChanged(QString grossTotal, QString vatTotal, QString netTotal);
    void checkoutButtonClickFinished(int orderId);
};
