#pragma once

#include <QAbstractListModel>
#include "OrderModel.h"

class OrderListModel : public QAbstractListModel
{
    Q_OBJECT
    QList<OrderModel *> list;
public:
    explicit OrderListModel(QObject *parent = nullptr);
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QHash<int, QByteArray> roleNames() const;
    void setList(QList<OrderModel *> list);
};

