#pragma once

#include <QAbstractListModel>
#include "CashingModeModel.h"

class CashingModeListModel: public QAbstractListModel
{
    Q_OBJECT
public:
    explicit CashingModeListModel(QObject *parent = nullptr);
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QHash<int, QByteArray> roleNames() const;
    QList<CashingModeModel> list;
};
