#include "RoomListModel.h"

static const int ID_ROLE = Qt::UserRole + 1;
static const int NUMERO_CHAMBRE_ROLE = Qt::UserRole + 2;
static const int CHAMBRE_TYPE_ID_ROLE = Qt::UserRole + 3;
static const int CHAMBRE_TYPE_LIBELLE_ROLE = Qt::UserRole + 4;

RoomListModel::RoomListModel(QObject * parent): QAbstractListModel(parent)
{

}


QVariant RoomListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
    if (index.row() > list.size() -1)
        return QVariant();

    Room *item = list.at(index.row());
    switch (role) {
    case Qt::DisplayRole :
        break;
    case ID_ROLE:
        return QVariant::fromValue(item->id);
    case NUMERO_CHAMBRE_ROLE:
        return QVariant::fromValue(item->numeroChambre);
    case CHAMBRE_TYPE_ID_ROLE:
        return QVariant::fromValue(item->typeChambreId);
    case CHAMBRE_TYPE_LIBELLE_ROLE:
        return QVariant::fromValue(item->typeChambreLibelle);
    default:
        return QVariant();
    }
    return QVariant();

}

int RoomListModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    return list.size();
}


QHash<int, QByteArray> RoomListModel::roleNames() const
{
    QHash<int, QByteArray> roles = QAbstractListModel::roleNames();
    roles.insert(ID_ROLE, QByteArray("_id"));
    roles.insert(NUMERO_CHAMBRE_ROLE, QByteArray("numeroChambre"));
    roles.insert(CHAMBRE_TYPE_ID_ROLE, QByteArray("typeChambreId"));
    roles.insert(CHAMBRE_TYPE_LIBELLE_ROLE, QByteArray("typeChambreLibelle"));
    return roles;
}

void RoomListModel::setList(QList<Room *> list)
{
    beginResetModel();
    this->list = list;
    endResetModel();
}
