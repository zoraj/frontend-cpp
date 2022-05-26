#include "OrderViewController.h"

// Private methods
void OrderViewController::loadData()
{
    qDebug() << "Today is:" << ApplicationManager::getInstance()->getAppContext()->currentDate;

    // Load Group products
    auto groupProducts = cache::pos_group_product::getAll();
    groupProductListModel_->list = groupProducts;

    // Load products
    auto products = cache::pos_product::getAll();
    productListModel_->setList(products);
    productListProxyModel_->setSourceModel(productListModel_);
    productSearchListProxyModel_->setSourceModel(productListModel_);

    // Let's filter our products on the first group product
    if (groupProducts.size() > 0 ) {
        productListProxyModel_->setFilterRole(Qt::UserRole + 5);
        productListProxyModel_->setFilterFixedString(QString::number(groupProducts.at(0).id));
    }

    orderDetailListModel_->setList(order_->orderDetail);

    // Load clients
    auto clients = cache::client::getAll();
    clientListModel_->list = clients;
    clientListProxyModel_->setFilterRole(Qt::UserRole + 2); // CODE_ROLE

    // Load TopUp
    auto accompagniments = cache::accompaniment::getAll();
    accompanimentListModel_->list = accompagniments;
    auto cookings = cache::cooking::getAll();
    cookingListModel_->list = cookings;
}

PosProduct OrderViewController::getProductById(int productId)
{
    QList<PosProduct>::iterator product;
    auto list = productListModel_->getList();
    for (product = list.begin(); product != list.end(); ++product) {
        if (product->id == productId) {
            return *product;
        }
    }

    //for (QList<PosProductModel>)
    /*
    foreach(const PosProductModel *product, productListModel->getList()) {
        if (product.id == productId) {
            return product;
        }
    }*/
    return PosProduct();
}


void OrderViewController::recalculateTotal()
{
    grossTotal_ = 0.0f;
    netTotal_ = 0.0f;
    foreach(auto item,  order_->orderDetail) {
        grossTotal_ += item->total;
    }
    // TODO: Calculate the right total
    netTotal_ = grossTotal_;
    // Update UI data
    orderDetailListModel_->setList(order_->orderDetail);
    QString grossT = QString::number(grossTotal_, 'f', 2) + "€";
    QString vatT = QString::number(vatTotal_, 'f', 2) + "€";
    QString netT = QString::number(netTotal_, 'f', 2) + "€";
    emit orderDetailChanged(grossT, vatT, netT);
}

/*
 * It returns the new order identity
 */
int OrderViewController::cacheOrder()
{
    return cache::order::persist(*order_);
}


void OrderViewController::initNewOrder()
{
    order_->id = constant::UNDEFINED_INT; // Important ! to know if it's a new order
    QDateTime dateTime = QDateTime::currentDateTime();
    QDate currentDate = ApplicationManager::getInstance()->getAppContext()->currentDate;
    dateTime.setDate(currentDate);
    order_->dateNote = dateTime;
    order_->numTable = 0;
    order_->nbCouvert = 0;
    order_->posteUuid = ApplicationManager::getInstance()->getAppContext()->deviceUuid;
    order_->service = ApplicationManager::getInstance()->getAppContext()->currentPOSService;
    order_->activiteId = ApplicationManager::getInstance()->getAppContext()->currentActivity;
    order_->userId = ApplicationManager::getInstance()->getAppContext()->user->id;

    order_->orderDetail.clear();
}


// Public methods
OrderViewController::OrderViewController(QObject *parent) : BaseViewController(parent)
{
    order_ = new Order();
    groupProductListModel_ = new PosGroupProductListModel(this);
    productListModel_ = new PosProductListModel(this);
    cookingListModel_ = new CookingListModel(this);
    accompanimentListModel_ = new AccompanimentListModel(this);
    productListProxyModel_ = new QSortFilterProxyModel(this);
    productSearchListProxyModel_ = new QSortFilterProxyModel(this);
    orderDetailListModel_ = new OrderDetailListModel();
    clientListModel_ = new ClientListModel(this);
    clientListProxyModel_ = new QSortFilterProxyModel(this);
    grossTotal_ = 0.0f;
    vatTotal_ = 0.0f;
    netTotal_ = 0.0f;
}

void OrderViewController::openOrder(int orderId, int numTable)
{
    order_->id = orderId;
    if (orderId == constant::UNDEFINED_INT) {// It means it's a new order
        QDateTime dateTime = QDateTime::currentDateTime();
        QDate currentDate = ApplicationManager::getInstance()->getAppContext()->currentDate;
        dateTime.setDate(currentDate);

        order_->numTable = numTable;
        order_->dateNote = dateTime;
        order_->nbCouvert = 0;
        order_->posteUuid = ApplicationManager::getInstance()->getAppContext()->deviceUuid;
        order_->service = ApplicationManager::getInstance()->getAppContext()->currentPOSService;
        order_->activiteId = ApplicationManager::getInstance()->getAppContext()->currentActivity;
    }
    else {
        // Dig into the cache if any order on this table
        auto order = cache::order::getById(orderId);
        if (order) {

            order_->dateNote = order->dateNote;
            order_->numTable = order->numTable;
            order_->posteUuid = ApplicationManager::getInstance()->getAppContext()->deviceUuid;
            order_->service = ApplicationManager::getInstance()->getAppContext()->currentPOSService;
            order_->nbCouvert = order->nbCouvert;
            order_->activiteId = ApplicationManager::getInstance()->getAppContext()->currentActivity;
            order_->orderDetail = order->orderDetail;
            if (!order_->orderDetail.isEmpty()) { // Calculate Net by Unit price
                for(auto i = 0; i < order->orderDetail.size(); ++i) {
                    order_->orderDetail[i]->total = order->orderDetail.at(i)->qte * order->orderDetail.at(i)->pu;
                    auto product = getProductById(order->orderDetail.at(i)->prestationId);
                    order_->orderDetail[i]->prestationLibelle = product.libelle;
                }
            }
        }
    }
    recalculateTotal();
    emit orderChanged(order_);
}

void OrderViewController::viewDidLoad()
{
    loadData();
    initNewOrder();
    emit viewDidLoadFinished();
}

void OrderViewController::viewDidUnload()
{
    delete productListProxyModel_;
    productListProxyModel_ = nullptr;
}

void OrderViewController::setOrder(Order *order)
{
    // Order header
    order_->numTable = order->numTable;
    order_->posteUuid = ApplicationManager::getInstance()->getAppContext()->deviceUuid;
    order_->service = ApplicationManager::getInstance()->getAppContext()->currentPOSService;
    order_->nbCouvert = order->nbCouvert;
    order_->activiteId = ApplicationManager::getInstance()->getAppContext()->currentActivity;
    order_->userId = ApplicationManager::getInstance()->getAppContext()->user->id;
}

// UI Events
void OrderViewController::resetOrder()
{
    order_->id = constant::UNDEFINED_INT; // Important ! to know if it's a new order
    order_->numTable = 0;
    order_->nbCouvert = 0;
    order_->orderDetail.clear();
    orderDetailListModel_->setList(order_->orderDetail);
    recalculateTotal();
    emit orderChanged(order_);
}

void OrderViewController::quitButtonClicked()
{
    cacheOrder();
    // Reinitialize everything
    resetOrder();
}

void OrderViewController::checkoutButtonClicked()
{
    // Persist data before checking out
    order_->id = cacheOrder();
    emit checkoutButtonClickFinished(order_->id);
}

void OrderViewController::groupProductSelected(int productGroupId)
{
    productListProxyModel_->setFilterRole(Qt::UserRole + 5);
    productListProxyModel_->setFilterFixedString(QString::number(productGroupId));
}

void OrderViewController::productSelected(int productId, int qty)
{
    // Check first if product already added
    int i = 0;
    bool isProductExist = false;
    foreach(OrderDetail *orderDetail, order_->orderDetail) {
        if (orderDetail->prestationId == productId) {
            order_->orderDetail.at(i)->qte += qty;
            isProductExist = true;
        }
        i++;
    }

    if (!isProductExist) {
        PosProduct product = getProductById(productId);
        OrderDetail *orderDetail = new OrderDetail();
        orderDetail->setParent(this);
        orderDetail->qte = qty;
        orderDetail->prestationId = productId;
        orderDetail->prestationLibelle = product.libelle;
        orderDetail->pu = product.prix;
        orderDetail->total = qty * product.prix;
        order_->orderDetail.append(orderDetail);
    }

    recalculateTotal();
}

void OrderViewController::clientSearchTextChanged(const QString &keyword)
{

}

void OrderViewController::productSearchTextChanged(const QString &keyword)
{
    qInfo() << keyword;
    productSearchListProxyModel_->setFilterRole(Qt::UserRole + 3);
    productSearchListProxyModel_->setFilterFixedString(keyword);
}

void OrderViewController::deleteOrderButtonClicked(int productId, int qty)
{
    int i = 0;
    foreach(OrderDetail *orderDetail, order_->orderDetail) {
        if (orderDetail->prestationId == productId) {
            int newQty = orderDetail->qte - qty;
            if (newQty > 0) {
                order_->orderDetail.at(i)->qte = newQty;
            }
            else {
                order_->orderDetail.removeAt(i);
            }
        }
        i++;
    }
    recalculateTotal();
}

void OrderViewController::offertOrderButtonClicked(int productId, int qty)
{
    int i = 0;
    foreach(OrderDetail *orderDetail, order_->orderDetail) {
        if (orderDetail->prestationId == productId) {
            order_->orderDetail.at(i)->pu = 0;
        }
        i++;
    }
    recalculateTotal();
}

void OrderViewController::ticketButtonClicked()
{
    //PrinterWorker::printTicket(*this->order.data());
}
