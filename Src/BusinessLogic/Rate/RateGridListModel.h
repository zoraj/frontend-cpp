#pragma once
#include <QAbstractListModel>

#include "RateGrid.h"

class RateGridListModel: public QAbstractListModel
{
    Q_OBJECT
public:
    explicit RateGridListModel(QObject *parent = nullptr);
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QHash<int, QByteArray> roleNames() const;
    QList<RateGrid> list;
};

