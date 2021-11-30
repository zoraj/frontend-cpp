#include "OrderCheckoutListModel.h"

static const int ID_ROLE = Qt::UserRole + 1;
static const int ENCAISSEMENT_ID_ROLE = Qt::UserRole + 2;
static const int ENCAISSEMENT_LIBELLE_ROLE = Qt::UserRole + 3;
static const int MONTANT_ROLE = Qt::UserRole + 4;

OrderCheckoutListModel::OrderCheckoutListModel(QObject * parent): QAbstractListModel(parent)
{

}

QVariant OrderCheckoutListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
    if (index.row() > list.size() -1)
        return QVariant();

    OrderCheckoutModel *item = list.at(index.row());
    switch (role) {
    case Qt::DisplayRole :
        break;
    case ID_ROLE:
        return QVariant::fromValue(item->id);
    case ENCAISSEMENT_ID_ROLE:
        return QVariant::fromValue(item->modeEncaissementId);
    case ENCAISSEMENT_LIBELLE_ROLE:
        return QVariant::fromValue(item->modeEncaissementLibelle);
    case MONTANT_ROLE:
        return QVariant::fromValue(item->montantTtc);
    default:
        return QVariant();
    }
    return QVariant();

}

int OrderCheckoutListModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    return list.size();
}


QHash<int, QByteArray> OrderCheckoutListModel::roleNames() const
{
    QHash<int, QByteArray> roles = QAbstractListModel::roleNames();
    roles.insert(ID_ROLE, QByteArray("id"));
    roles.insert(ENCAISSEMENT_ID_ROLE, QByteArray("encaiss_id"));
    roles.insert(ENCAISSEMENT_LIBELLE_ROLE, QByteArray("encaiss_lib"));
    roles.insert(MONTANT_ROLE, QByteArray("montant"));
    return roles;
}

void OrderCheckoutListModel::setList(const QList<OrderCheckoutModel *> list)
{
    beginResetModel();
    this->list = list;
    endResetModel();
}
