#pragma once
#include <QAbstractListModel>
#include "Prescripteur.h"

class PrescripteurListModel: public QAbstractListModel
{
    Q_OBJECT
public:
    explicit PrescripteurListModel(QObject *parent = nullptr);
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QHash<int, QByteArray> roleNames() const;
    QList<Prescripteur> list;
};

