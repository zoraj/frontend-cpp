#include "OrderListModel.h"

static const int ID_ROLE = Qt::UserRole + 1;
static const int CLIENT_ROLE = Qt::UserRole + 2;
static const int NUMTABLE_ROLE = Qt::UserRole + 3;
static const int NBCOUVERT_ROLE = Qt::UserRole + 4;
static const int SERVICE_ROLE = Qt::UserRole + 5;

OrderListModel::OrderListModel(QObject * parent): QAbstractListModel(parent)
{

}

QVariant OrderListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
    if (index.row() > list.size() -1)
        return QVariant();

    OrderModel *item = list.at(index.row());
    switch (role) {
    case Qt::DisplayRole :
        break;
    case ID_ROLE:
        return QVariant::fromValue(item->id);
    case CLIENT_ROLE:
        return QVariant::fromValue(item->mmcClientId);
    case NUMTABLE_ROLE:
        return QVariant::fromValue(item->numTable);
    case NBCOUVERT_ROLE:
        return QVariant::fromValue(item->nbCouvert);
    case SERVICE_ROLE:
        return QVariant::fromValue(item->service);
    default:
        return QVariant();
    }
    return QVariant();

}

int OrderListModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    return list.size();
}


QHash<int, QByteArray> OrderListModel::roleNames() const
{
    QHash<int, QByteArray> roles = QAbstractListModel::roleNames();
    roles.insert(ID_ROLE, QByteArray("_id"));
    roles.insert(CLIENT_ROLE, QByteArray("mmcClientId"));
    roles.insert(NUMTABLE_ROLE, QByteArray("numeroTable"));
    roles.insert(NBCOUVERT_ROLE, QByteArray("nbCouvert"));
    roles.insert(SERVICE_ROLE, QByteArray("service"));
    return roles;
}

void OrderListModel::setList(QList<OrderModel *> list)
{
    this->list = list;
    beginResetModel();
    endResetModel();
}
