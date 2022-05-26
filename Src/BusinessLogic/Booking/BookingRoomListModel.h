#pragma once
#include <QAbstractListModel>
#include "Booking.h"

class BookingRoomListModel : public QAbstractListModel
{
    Q_OBJECT
    QList<BookingRoom *> list;
public:
    explicit BookingRoomListModel(QObject *parent = nullptr);
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QHash<int, QByteArray> roleNames() const;
    void setList(const QList<BookingRoom *> list);
};
