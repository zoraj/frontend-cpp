#pragma once

#include <QObject>
#include <QJsonObject>
#include <QJsonParseError>
#include <QDebug>

struct User: public QObject
{
    int id;
    QString firstname;
    QString lastname;
    QString userType;
    QString moduleAuthorized;
    QString token;
    QString pinCode;
};

