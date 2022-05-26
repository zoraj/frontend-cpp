#pragma once

#include <QAbstractListModel>
#include "PlanningDate.h"

class PlanningDateListModel : public QAbstractListModel
{
    Q_OBJECT
    QList<PlanningDate *> list;
public:
    explicit PlanningDateListModel(QObject *parent = nullptr);
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QHash<int, QByteArray> roleNames() const;
    void setList(const QList<PlanningDate *> list);
};
