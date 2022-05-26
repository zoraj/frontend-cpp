#include "ActivityListModel.h"

static const int ID_ROLE = Qt::UserRole + 1;
static const int CODE_ROLE = Qt::UserRole + 2;
static const int LIBELLE_ROLE = Qt::UserRole + 3;
static const int ICONE_IMG_ROLE = Qt::UserRole + 4;
static const int NOMBRE_TABLE_ROLE = Qt::UserRole + 5;
static const int IS_GESTION_SERVEUR_ROLE = Qt::UserRole + 6;
static const int IS_GESTION_TABLE_ROLE = Qt::UserRole + 7;
static const int IS_GESTION_COUVERT_ROLE = Qt::UserRole + 8;

ActivityListModel::ActivityListModel(QObject * parent): QAbstractListModel(parent)
{

}

QVariant ActivityListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
    if (index.row() > list.size() -1)
        return QVariant();

    Activity item = list.at(index.row());
    switch (role) {
    case Qt::DisplayRole :
        break;
    case ID_ROLE:
        return QVariant::fromValue(item.id);
    case CODE_ROLE:
        return QVariant::fromValue(item.code);
    case LIBELLE_ROLE:
        return QVariant::fromValue(item.libelle);
    case ICONE_IMG_ROLE:
        return QVariant::fromValue(item.iconeImg);
    case NOMBRE_TABLE_ROLE:
        return QVariant::fromValue(item.nombreTable);
    case IS_GESTION_SERVEUR_ROLE:
        return QVariant::fromValue(item.isGestionServeur);
    case IS_GESTION_TABLE_ROLE:
        return QVariant::fromValue(item.isGestionTable);
    case IS_GESTION_COUVERT_ROLE:
        return QVariant::fromValue(item.isGestionCouvert);
    default:
        return QVariant();
    }
    return QVariant();

}

int ActivityListModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    return list.size();
}

QHash<int, QByteArray> ActivityListModel::roleNames() const
{
    QHash<int, QByteArray> roles = QAbstractListModel::roleNames();
    roles.insert(ID_ROLE, QByteArray("_id"));
    roles.insert(CODE_ROLE, QByteArray("code"));
    roles.insert(LIBELLE_ROLE, QByteArray("libelle"));
    roles.insert(ICONE_IMG_ROLE, QByteArray("iconImg"));
    roles.insert(NOMBRE_TABLE_ROLE, QByteArray("nombreTable"));
    roles.insert(IS_GESTION_SERVEUR_ROLE, QByteArray("isGestionServeur"));
    roles.insert(IS_GESTION_TABLE_ROLE, QByteArray("isGestionTable"));
    roles.insert(IS_GESTION_COUVERT_ROLE, QByteArray("isGestionCouvert"));
    return roles;
}
