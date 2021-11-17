#pragma once

#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonArray>

#include "UserModel.h"

namespace Builder::User {
    static UserModel *create(const QByteArray &json)
    {
        UserModel *user = nullptr;
        QJsonParseError error;

        QJsonDocument jsonDoc = QJsonDocument::fromJson(json, &error);
        if (error.error == QJsonParseError::NoError) {
            user = new UserModel();
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
