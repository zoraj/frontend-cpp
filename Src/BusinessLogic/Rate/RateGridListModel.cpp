#include "RateGridListModel.h"

static const int ID_ROLE = Qt::UserRole + 1;
static const int REFERENCE_ROLE = Qt::UserRole + 2;
static const int NOM_ROLE = Qt::UserRole + 3;

RateGridListModel::RateGridListModel(QObject *parent): QAbstractListModel(parent)
{

}

QVariant RateGridListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
    if (index.row() > list.size() -1)
        return QVariant();

    RateGrid item = list.at(index.row());
    switch (role) {
    case Qt::DisplayRole :
        break;
    case ID_ROLE:
        return QVariant::fromValue(item.id);
    case REFERENCE_ROLE:
        return QVariant::fromValue(item.reference);
    case NOM_ROLE:
        return QVariant::fromValue(item.nom);
    default:
        return QVariant();
    }
    return QVariant();
}

int RateGridListModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    return list.size();
}

QHash<int, QByteArray> RateGridListModel::roleNames() const
{
    QHash<int, QByteArray> roles = QAbstractListModel::roleNames();
    roles.insert(ID_ROLE, QByteArray("id"));
    roles.insert(REFERENCE_ROLE, QByteArray("reference"));
    roles.insert(NOM_ROLE, QByteArray("nom"));
    return roles;
}
