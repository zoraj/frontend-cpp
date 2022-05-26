#pragma once

#include <QAbstractListModel>
#include "Activity.h"

class ActivityListModel: public QAbstractListModel
{
    Q_OBJECT
public:
    explicit ActivityListModel(QObject *parent = nullptr);
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QHash<int, QByteArray> roleNames() const;
    QList<Activity> list;
};
