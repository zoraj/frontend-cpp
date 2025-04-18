#pragma once

#include <QAbstractListModel>

#include "OrderCheckout.h"

class OrderCheckoutListModel : public QAbstractListModel
{
    Q_OBJECT
    QList<OrderCheckout *> list;
public:
    explicit OrderCheckoutListModel(QObject *parent = nullptr);
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QHash<int, QByteArray> roleNames() const;
    void setList(const QList<OrderCheckout *> list);
};
