#include "PlanningDateListModel.h"

static const int INDEX_ROLE = Qt::UserRole + 1;
static const int DATE_ROLE = Qt::UserRole + 2;
static const int IS_WEEKEND_ROLE = Qt::UserRole + 3;

PlanningDateListModel::PlanningDateListModel(QObject * parent): QAbstractListModel(parent)
{

}

QVariant PlanningDateListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
    if (index.row() > list.size() -1)
        return QVariant();

    PlanningDate *item = list.at(index.row());
    switch (role) {
    case Qt::DisplayRole :
        break;
    case INDEX_ROLE:
        return QVariant::fromValue(item->index);
    case DATE_ROLE:
        return QVariant::fromValue(item->date);
    case IS_WEEKEND_ROLE:
        return QVariant::fromValue(item->isWeekEnd);
    default:
        return QVariant();
    }
    return QVariant();
}

int PlanningDateListModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    return list.size();
}


QHash<int, QByteArray> PlanningDateListModel::roleNames() const
{
    QHash<int, QByteArray> roles = QAbstractListModel::roleNames();
    roles.insert(INDEX_ROLE, QByteArray("index"));
    roles.insert(DATE_ROLE, QByteArray("date"));
    roles.insert(IS_WEEKEND_ROLE, QByteArray("isWeekEnd"));
    return roles;
}

void PlanningDateListModel::setList(QList<PlanningDate *> list)
{
    beginResetModel();
    this->list = list;
    endResetModel();
}
