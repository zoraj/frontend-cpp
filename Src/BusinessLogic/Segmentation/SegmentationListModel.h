#pragma once
#include <QAbstractListModel>
#include "Segmentation.h"

class SegmentationListModel: public QAbstractListModel
{
    Q_OBJECT
public:
    explicit SegmentationListModel(QObject *parent = nullptr);
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QHash<int, QByteArray> roleNames() const;
    QList<Segmentation> list;
};
