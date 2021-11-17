#pragma once

#include <QObject>
#include "SettingModel.h"

namespace Builder::Setting {

    static SettingModel create(const QJsonObject &json)
    {
        SettingModel setting;
        setting.cle = json["cle"].toString();
        setting.valeur = json["valeur"].toString();
        return setting;
    };

    static QList<SettingModel> create(const QByteArray &input)
    {
        QList<SettingModel> settings;
        QJsonParseError error;

        QJsonDocument jsonDoc = QJsonDocument::fromJson(input, &error);
        if (error.error == QJsonParseError::NoError) {
            QJsonArray jsonArray = jsonDoc.array();
            foreach (const  QJsonValue &value, jsonArray) {
                QJsonObject jsonObject = value.toObject();
                SettingModel setting = create(jsonObject);
                settings.append(setting);
            }
        }
        return settings;
    };
}

