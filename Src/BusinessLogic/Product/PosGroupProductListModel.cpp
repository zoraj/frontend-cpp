#include "PosGroupProductListModel.h"

static const int ID_ROLE = Qt::UserRole + 1;
static const int CODE_ROLE = Qt::UserRole + 2;
static const int LIBELLE_ROLE = Qt::UserRole + 3;
static const int ICONIMG_ROLE = Qt::UserRole + 4;

PosGroupProductListModel::PosGroupProductListModel(QObject *parent): QAbstractListModel(parent)
{

}

QVariant PosGroupProductListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
    if (index.row() > list.size() -1)
        return QVariant();

    PosGroupProductModel item = list.at(index.row());
    switch (role) {
    case Qt::DisplayRole :
        break;
    case ID_ROLE:
        return QVariant::fromValue(item.id);
    case CODE_ROLE:
        return QVariant::fromValue(item.code);
    case LIBELLE_ROLE:
        return QVariant::fromValue(item.libelle);
    case ICONIMG_ROLE:
        return QVariant::fromValue(item.iconeImg);
    default:
        return QVariant();
    }
    return QVariant();
}

int PosGroupProductListModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    return list.size();
}

QHash<int, QByteArray> PosGroupProductListModel::roleNames() const
{
    QHash<int, QByteArray> roles = QAbstractListModel::roleNames();
    roles.insert(ID_ROLE, QByteArray("_id"));
    roles.insert(CODE_ROLE, QByteArray("code"));
    roles.insert(LIBELLE_ROLE, QByteArray("libelle"));
    roles.insert(ICONIMG_ROLE, QByteArray("iconeImg"));
    return roles;
}
