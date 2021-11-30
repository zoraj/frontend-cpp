#include "OrderCheckoutViewController.h"


// Private methods
void OrderCheckoutViewController::loadData()
{
    auto cashingModes = Cache::CashingMode::getAll();
    cashingModeListModel->list = cashingModes;
    //orderDetailListModel->setList(order->orderDetail);
}

CashingModeModel OrderCheckoutViewController::getCashingModeById(int cashingModeId)
{
    QList<CashingModeModel>::iterator cashingMode;
    auto list = cashingModeListModel->list;
    for (cashingMode = list.begin(); cashingMode != list.end(); ++cashingMode) {
        if (cashingMode->id == cashingModeId) {
            return *cashingMode;
        }
    }

    return CashingModeModel();
}

float OrderCheckoutViewController::calculateTotalCheckout()
{
    auto total = 0.00f;
    foreach(auto orderCheckout, orderCheckouts) {
        total += orderCheckout->montantTtc;
    }
    return total;
}

float OrderCheckoutViewController::getBalance()
{
    auto totalOrder = 0.0f;
    auto totalCheckout = 0.0f;

    foreach(auto orderCheckout, this->orderCheckouts) {
        totalCheckout += orderCheckout->montantTtc;
    }

    foreach(auto orderDetail, this->order->orderDetail) {
        totalOrder += orderDetail->qte * orderDetail->pu;
    }

    return totalOrder - totalCheckout;
}

// Public methods
OrderCheckoutViewController::OrderCheckoutViewController(QObject *parent) : BaseViewController(parent)
{
    cashingModeListModel = new CashingModeListModel(this);
    orderDetailListModel = new OrderDetailListModel(this);
    orderCheckoutListModel = new OrderCheckoutListModel(this);
    orderCheckout = new OrderCheckoutModel();
}

void OrderCheckoutViewController::viewDidLoad()
{
    loadData();
    emit viewDidLoadFinished();
}

void OrderCheckoutViewController::viewDidUnload()
{

}

void OrderCheckoutViewController::setOrder(OrderModel *orderModel)
{
    this->order = orderModel;
}

// UI Events
void OrderCheckoutViewController::cashingModeSelected(int cashingModeId, float amount)
{
    OrderCheckoutModel *checkout = new OrderCheckoutModel;
    checkout->noteEnteteId = this->order->id;
    checkout->userId = this->order->userId;
    checkout->modeEncaissementId = cashingModeId;
    auto cashingMode = getCashingModeById(cashingModeId);
    checkout->modeEncaissementLibelle = cashingMode.libelle;
    // Let's set the date based on current date of the software, not the system
    QDateTime dateTime;
    dateTime.setDate(ApplicationManager::getInstance()->getAppContext()->currentDate);
    dateTime.setTime(QTime::currentTime());
    checkout->dateEncaissement = dateTime;

    qInfo() << "Balance " << amount;
    if (amount <= 0.0f) { // It means that the user has finished selecting cashing mode

        checkout->montantTtc = getBalance();
        orderCheckouts.append(checkout);

        // Store checkout information in cache
        Cache::OrderCheckout::persist(orderCheckouts);

        // After checking out, we put the order id into singleton Order Pool, so the background worker will do its job to sync to the cloud
        ApplicationManager::getInstance()->getAppContext()->ordersPool.append(this->order->id);
    }
    else { // The user hasn't finished yet setting every cashing mode
        checkout->montantTtc = amount;
        orderCheckouts.append(checkout);
        // Manage UI
        orderCheckoutListModel->setList(orderCheckouts);
        auto total = calculateTotalCheckout();
        QString totalStr = QString::number(total, 'f', 2) + "€";
    }


    //emit checkoutDetailChanged(totalStr);
    // emit validateButtonFinished();

    /*
    // Notify UI
    emit cashingModeSelectedCallback();
    */
}

void OrderCheckoutViewController::validateButtonClicked()
{
    Cache::OrderCheckout::persist(orderCheckouts);
    emit validateButtonFinished();
}
