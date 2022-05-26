#pragma once

#include <QAbstractListModel>
#include "TopUp.h"

class AccompanimentListModel: public QAbstractListModel
{
    Q_OBJECT
public:
    explicit AccompanimentListModel(QObject *parent = nullptr);
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QHash<int, QByteArray> roleNames() const;
    QList<Accompaniment> list;
};
