#include "TablePlanListModel.h"

static const int NUMTABLE_ROLE = Qt::UserRole + 1;
static const int IS_AVAILABLE_ROLE = Qt::UserRole + 2;
static const int ORDER_ID_ROLE = Qt::UserRole + 3;

TablePlanListModel::TablePlanListModel(QObject * parent): QAbstractListModel(parent)
{

}

QVariant TablePlanListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
    if (index.row() > list.size() -1)
        return QVariant();

    Table item = list.at(index.row());
    switch (role) {
    case Qt::DisplayRole :
        break;
    case NUMTABLE_ROLE:
        return QVariant::fromValue(item.numTable);
    case IS_AVAILABLE_ROLE:
        return QVariant::fromValue(item.isAvailable);
    case ORDER_ID_ROLE:
        return QVariant::fromValue(item.orderId);

    default:
        return QVariant();
    }
    return QVariant();

}

int TablePlanListModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    return list.size();
}


QHash<int, QByteArray> TablePlanListModel::roleNames() const
{
    QHash<int, QByteArray> roles = QAbstractListModel::roleNames();
    roles.insert(NUMTABLE_ROLE, QByteArray("tableNum"));
    roles.insert(IS_AVAILABLE_ROLE, QByteArray("isAvailable"));
    roles.insert(ORDER_ID_ROLE, QByteArray("_orderId"));
    return roles;
}

void TablePlanListModel::setList(QList<Table> list)
{
    this->list = list;
    beginResetModel();
    endResetModel();
}
