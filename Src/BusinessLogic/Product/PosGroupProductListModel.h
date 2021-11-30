#pragma once
#include <QAbstractListModel>
#include "PosGroupProductModel.h"

class PosGroupProductListModel: public QAbstractListModel
{
    Q_OBJECT
public:
    PosGroupProductListModel(QObject *parent = nullptr);
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QHash<int, QByteArray> roleNames() const;
    QList<PosGroupProductModel> list;

};
