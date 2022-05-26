#pragma once

#include <QAbstractListModel>
#include <QDebug>
#include "PosProduct.h"

class PosProductListModel: public QAbstractListModel
{
    Q_OBJECT
    QList<PosProduct> list;
public:
    PosProductListModel(QObject *parent = nullptr);
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QHash<int, QByteArray> roleNames() const;
    QList<PosProduct> getList() const;
    void setList(const QList<PosProduct> list);
};

