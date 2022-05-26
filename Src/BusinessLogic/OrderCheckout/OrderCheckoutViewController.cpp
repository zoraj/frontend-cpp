#include "OrderCheckoutViewController.h"


// Private methods
void OrderCheckoutViewController::loadData()
{
    auto cashingModes = cache::cashing_mode::getAll();
    cashingModeListModel->list = cashingModes;

    // Retrieve order's detail from cache
    if (orderId_ != constant::UNDEFINED_INT) {
        order = cache::order::getById(orderId_);
        orderDetailListModel->setList(order->orderDetail);
    }
}

CashingMode OrderCheckoutViewController::getCashingModeById(int cashingModeId)
{
    QList<CashingMode>::iterator cashingMode;
    auto list = cashingModeListModel->list;
    for (cashingMode = list.begin(); cashingMode != list.end(); ++cashingMode) {
        if (cashingMode->id == cashingModeId) {
            return *cashingMode;
        }
    }

    return CashingMode();
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
    orderCheckout = new OrderCheckout();
}

void OrderCheckoutViewController::viewDidLoad()
{
    loadData();
    emit viewDidLoadFinished();
}

void OrderCheckoutViewController::viewDidUnload()
{

}

// UI Events
void OrderCheckoutViewController::cashingMode_Selected(int cashingModeId, float amount)
{
    OrderCheckout *checkout = new OrderCheckout();
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

    orderCheckoutListModel->setList(orderCheckouts);
    qInfo() << "Balance " << amount;
    if (amount <= 0.0f) { // The user didn't set the amout or directly chose the cashing mode
        checkout->montantTtc = getBalance();

        // After checking out, we put the order id into singleton Order Pool, so the background worker will do its job to sync to the cloud
        //ApplicationManager::getInstance()->getAppContext()->ordersPool.append(this->order->id);
    }
    else { // The user hasn't finished yet setting every cashing mode
        checkout->montantTtc = amount;
    }
    orderCheckouts.append(checkout);

    auto total = calculateTotalCheckout();
    QString totalStr = QString::number(total, 'f', 2) + "€";

    // Refresh UI
    orderCheckoutListModel->setList(orderCheckouts);

    // Store checkout information in cache
    //cache::order_checkout::persist(orderCheckouts);

    emit checkoutDetailChanged(totalStr);
    // emit validateButtonFinished();

    // Notify UI
    //emit cashingModeSelectedFinished();
}

void OrderCheckoutViewController::validateButton_Clicked()
{
    cache::order_checkout::persist(orderCheckouts);
    emit validateButtonClickedFinished();
}

void OrderCheckoutViewController::setOrderId(int id)
{
    orderId_ = id;
}
