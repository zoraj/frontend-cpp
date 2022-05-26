#pragma once

#include <QAbstractListModel>
#include "Order.h"

class OrderListModel : public QAbstractListModel
{
    Q_OBJECT
    QList<Order *> list;
public:
    explicit OrderListModel(QObject *parent = nullptr);
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QHash<int, QByteArray> roleNames() const;
    void setList(QList<Order *> list);
};

