#pragma once

#include <QAbstractListModel>
#include "TopUpModel.h"

class CookingListModel: public QAbstractListModel
{
    Q_OBJECT
public:
    explicit CookingListModel(QObject *parent = nullptr);
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QHash<int, QByteArray> roleNames() const;
    QList<CookingModel> list;
};
