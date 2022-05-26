#include "BookingRoomListModel.h"

static const int ID_ROLE = Qt::UserRole + 1;
static const int RESERVATION_ID_ROLE = Qt::UserRole + 2;
static const int TYPE_CHB_ID_ROLE = Qt::UserRole + 3;
static const int CHB_ID_ROLE = Qt::UserRole + 4;
static const int NUM_CHB_ROLE = Qt::UserRole + 5;
static const int TYPE_CHB_LIBELLE_ROLE = Qt::UserRole + 6;

BookingRoomListModel::BookingRoomListModel(QObject * parent): QAbstractListModel(parent)
{

}

QVariant BookingRoomListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
    if (index.row() > list.size() -1)
        return QVariant();

    BookingRoom *item = list.at(index.row());
    switch (role) {
    case Qt::DisplayRole :
        break;
    case ID_ROLE:
        return QVariant::fromValue(item->id);
    case RESERVATION_ID_ROLE:
        return QVariant::fromValue(item->reservationId);
    case TYPE_CHB_ID_ROLE:
        return QVariant::fromValue(item->typeChambreId);
    case CHB_ID_ROLE:
        return QVariant::fromValue(item->chambreId);
    case NUM_CHB_ROLE:
        return QVariant::fromValue(item->numeroChambre);
    case TYPE_CHB_LIBELLE_ROLE:
        return QVariant::fromValue(item->typeChambreLibelle);
    default:
        return QVariant();
    }
    return QVariant();
}

int BookingRoomListModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    return list.size();
}


QHash<int, QByteArray> BookingRoomListModel::roleNames() const
{
    QHash<int, QByteArray> roles = QAbstractListModel::roleNames();
    roles.insert(ID_ROLE, QByteArray("id"));
    roles.insert(RESERVATION_ID_ROLE, QByteArray("reservationId"));
    roles.insert(TYPE_CHB_ID_ROLE, QByteArray("typeChambreId"));
    roles.insert(CHB_ID_ROLE, QByteArray("chambreId"));
    roles.insert(NUM_CHB_ROLE, QByteArray("numeroChambre"));
    roles.insert(TYPE_CHB_LIBELLE_ROLE, QByteArray("typeChambreLibelle"));
    return roles;
}

void BookingRoomListModel::setList(const QList<BookingRoom *> list)
{
    beginResetModel();
    this->list = list;
    endResetModel();
}

