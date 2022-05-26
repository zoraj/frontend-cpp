#pragma once

#include <QObject>
#include "Setting.h"

namespace builder::setting {

    static Setting create(const QJsonObject &json)
    {
        Setting setting;
        setting.cle = json["cle"].toString();
        setting.valeur = json["valeur"].toString();
        return setting;
    };

    static QList<Setting> create(const QByteArray &input)
    {
        QList<Setting> settings;
        QJsonParseError error;

        QJsonDocument jsonDoc = QJsonDocument::fromJson(input, &error);
        if (error.error == QJsonParseError::NoError) {
            QJsonArray jsonArray = jsonDoc.array();
            foreach (const  QJsonValue &value, jsonArray) {
                QJsonObject jsonObject = value.toObject();
                Setting setting = create(jsonObject);
                settings.append(setting);
            }
        }
        return settings;
    };
}

