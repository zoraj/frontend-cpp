#pragma once

#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonArray>

#include "User.h"

namespace builder::user {
    static User *create(const QByteArray &json)
    {
        User *user = nullptr;
        QJsonParseError error;

        QJsonDocument jsonDoc = QJsonDocument::fromJson(json, &error);
        if (error.error == QJsonParseError::NoError) {
            user = new User();
            QJsonObject jsonObject = jsonDoc.object();

            user->id = jsonObject["id"].toInt();
            user->firstname = jsonObject["firstname"].toString();
            user->lastname = jsonObject["lastname"].toString();
            user->userType = jsonObject["userType"].toString();
            user->moduleAuthorized = jsonObject["moduleAuthorized"].toString();
            user->token = jsonObject["token"].toString();
            user->pinCode = jsonObject["pinCode"].toString();
        }
        else
            qDebug() << "Error parsing " << json;
        return user;
    };
}
