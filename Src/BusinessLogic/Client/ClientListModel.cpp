#include "ClientListModel.h"

static const int ID_ROLE = Qt::UserRole + 1;
static const int CODE_ROLE = Qt::UserRole + 2;
static const int NOM_ROLE = Qt::UserRole + 3;
static const int PRENOM_ROLE = Qt::UserRole + 4;
static const int SOCIETE_ROLE = Qt::UserRole + 5;

ClientListModel::ClientListModel(QObject * parent): QAbstractListModel(parent)
{

}

QVariant ClientListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
    if (index.row() > list.size() -1)
        return QVariant();

    Client item = list.at(index.row());
    switch (role) {
    case Qt::DisplayRole :
        break;
    case ID_ROLE:
        return QVariant::fromValue(item.id);
    case CODE_ROLE:
        return QVariant::fromValue(item.code);
    case NOM_ROLE:
        return QVariant::fromValue(item.nom);
    case PRENOM_ROLE:
        return QVariant::fromValue(item.prenom);
    case SOCIETE_ROLE:
        return QVariant::fromValue(item.prenom);
    default:
        return QVariant();
    }
    return QVariant();

}

int ClientListModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    return list.size();
}


QHash<int, QByteArray> ClientListModel::roleNames() const
{
    QHash<int, QByteArray> roles = QAbstractListModel::roleNames();
    roles.insert(ID_ROLE, QByteArray("id"));
    roles.insert(CODE_ROLE, QByteArray("code"));
    roles.insert(NOM_ROLE, QByteArray("nom"));
    roles.insert(PRENOM_ROLE, QByteArray("prenom"));
    roles.insert(PRENOM_ROLE, QByteArray("societe"));
    return roles;
}
