#include "OrderDetailListModel.h"

static const int ID_ROLE = Qt::UserRole + 1;
static const int PRESTATION_ID_ROLE = Qt::UserRole + 2;
static const int PRESTATION_LIBELLE_ROLE = Qt::UserRole + 3;
static const int PRIX_ROLE = Qt::UserRole + 4;
static const int QTE_ROLE = Qt::UserRole + 5;
static const int IS_VAE_ROLE = Qt::UserRole + 6;
static const int IS_OFFERT_ROLE = Qt::UserRole + 7;
static const int TOTAL_ROLE = Qt::UserRole + 8;
static const int PU_ROLE = Qt::UserRole + 9;

OrderDetailListModel::OrderDetailListModel(QObject * parent): QAbstractListModel(parent)
{

}

QVariant OrderDetailListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
    if (index.row() > list.size() -1)
        return QVariant();

    OrderDetail *item = list.at(index.row());
    switch (role) {
    case Qt::DisplayRole :
        break;
    case ID_ROLE:
        return QVariant::fromValue(item->id);
    case PRESTATION_ID_ROLE:
        return QVariant::fromValue(item->prestationId);
    case PRESTATION_LIBELLE_ROLE:
        return QVariant::fromValue(item->prestationLibelle);
    case QTE_ROLE:
        return QVariant::fromValue(item->qte);
    case IS_VAE_ROLE:
        return QVariant::fromValue(item->isVAE);
    case IS_OFFERT_ROLE:
        return QVariant::fromValue(item->isOffert);
    case TOTAL_ROLE:
        return QVariant::fromValue(item->total);
    case PU_ROLE:
        return QVariant::fromValue(item->pu);
    default:
        return QVariant();
    }
    return QVariant();

}

int OrderDetailListModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    return list.size();
}

QHash<int, QByteArray> OrderDetailListModel::roleNames() const
{
    QHash<int, QByteArray> roles = QAbstractListModel::roleNames();
    roles.insert(ID_ROLE, QByteArray("_id"));
    roles.insert(PRESTATION_ID_ROLE, QByteArray("prestationId"));
    roles.insert(PRESTATION_LIBELLE_ROLE, QByteArray("prestationLibelle"));
    roles.insert(QTE_ROLE, QByteArray("qte"));
    roles.insert(IS_VAE_ROLE, QByteArray("isVAE"));
    roles.insert(IS_OFFERT_ROLE, QByteArray("isOffert"));
    roles.insert(TOTAL_ROLE, QByteArray("totalLine"));
    roles.insert(PU_ROLE, QByteArray("pu"));
    return roles;
}

void OrderDetailListModel::setList(const QList<OrderDetail *> list)
{
    this->list = list;
    beginResetModel();
    endResetModel();
}
