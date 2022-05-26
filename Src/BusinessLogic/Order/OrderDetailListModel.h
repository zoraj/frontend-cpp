#pragma once

#include <QAbstractListModel>
#include "Order.h"


class OrderDetailListModel: public QAbstractListModel
{
    Q_OBJECT
    QList<OrderDetail *> list;
public:
    explicit OrderDetailListModel(QObject *parent = nullptr);
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QHash<int, QByteArray> roleNames() const;
    void setList(const QList<OrderDetail *> list);
};
