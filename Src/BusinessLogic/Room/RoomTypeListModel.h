#pragma once
#include <QAbstractListModel>
#include "RoomType.h"

class RoomTypeListModel: public QAbstractListModel
{
    Q_OBJECT

public:
    explicit RoomTypeListModel(QObject *parent = nullptr);
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QHash<int, QByteArray> roleNames() const;
    QList<RoomType *> list;
};

