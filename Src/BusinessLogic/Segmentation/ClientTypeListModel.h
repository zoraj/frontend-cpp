#pragma once
#include <QAbstractListModel>
#include "ClientType.h"

class ClientTypeListModel: public QAbstractListModel
{
    Q_OBJECT
public:
    explicit ClientTypeListModel(QObject *parent = nullptr);
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QHash<int, QByteArray> roleNames() const;
    QList<ClientType> list;
};

