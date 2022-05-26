#include "PosProductListModel.h"

static const int ID_ROLE = Qt::UserRole + 1;
static const int CODE_ROLE = Qt::UserRole + 2;
static const int LIBELLE_ROLE = Qt::UserRole + 3;
static const int PRIX_ROLE = Qt::UserRole + 4;
static const int PRESTATION_GROUPE_ID_ROLE = Qt::UserRole + 5;
static const int COULEUR_ROLE = Qt::UserRole + 6;

PosProductListModel::PosProductListModel(QObject *parent): QAbstractListModel(parent)
{

}

QVariant PosProductListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
    if (index.row() > list.size() -1)
        return QVariant();

    PosProduct item = list.at(index.row());
    switch (role) {
    case Qt::DisplayRole :
        break;
    case ID_ROLE:
        return QVariant::fromValue(item.id);
    case CODE_ROLE:
        return QVariant::fromValue(item.code);
    case LIBELLE_ROLE:
        return QVariant::fromValue(item.libelle);
    case PRIX_ROLE:
        return QVariant::fromValue(item.prix);
    case PRESTATION_GROUPE_ID_ROLE:
        return QVariant::fromValue(item.posPrestationGroupeId);
    case COULEUR_ROLE:
        return QVariant::fromValue(item.couleur);
    default:
        return QVariant();
    }
    return QVariant();
}

int PosProductListModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    return list.size();
}

QHash<int, QByteArray> PosProductListModel::roleNames() const
{
    QHash<int, QByteArray> roles = QAbstractListModel::roleNames();
    roles.insert(ID_ROLE, QByteArray("_id"));
    roles.insert(CODE_ROLE, QByteArray("code"));
    roles.insert(LIBELLE_ROLE, QByteArray("libelle"));
    roles.insert(PRIX_ROLE, QByteArray("prix"));
    roles.insert(PRESTATION_GROUPE_ID_ROLE, QByteArray("posPrestationGroupeId"));
    roles.insert(COULEUR_ROLE, QByteArray("couleur"));
    return roles;
}

void PosProductListModel::setList(const QList<PosProduct> list)
{
    this->list = list;
    beginResetModel();
    endResetModel();
}

QList<PosProduct> PosProductListModel::getList() const
{
    return list;
}
