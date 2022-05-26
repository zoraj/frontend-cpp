#pragma once
#include <QAbstractListModel>
#include "Room.h"


class RoomListModel: public QAbstractListModel
{
    Q_OBJECT
    QList<Room *> list;
public:
    RoomListModel(QObject *parent = nullptr);
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QHash<int, QByteArray> roleNames() const;
    void setList(QList<Room *> list);
};

