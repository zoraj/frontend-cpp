#pragma once

#include <QAbstractListModel>
#include "TableModel.h"

class TablePlanListModel : public QAbstractListModel
{
    Q_OBJECT
    QList<TableModel> list;
public:
    explicit TablePlanListModel(QObject *parent = nullptr);
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QHash<int, QByteArray> roleNames() const;
    void setList(QList<TableModel> list);
};

