#pragma once

#include <QAbstractListModel>
#include <QDebug>
#include "PosProductModel.h"

class PosProductListModel: public QAbstractListModel
{
    Q_OBJECT
    QList<PosProductModel> list;
public:
    PosProductListModel(QObject *parent = nullptr);
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QHash<int, QByteArray> roleNames() const;
    QList<PosProductModel> getList() const;
    void setList(const QList<PosProductModel> list);
};

