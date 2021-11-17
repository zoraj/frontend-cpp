#pragma once

#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonArray>
#include <QDebug>

#include "Src/BusinessLogic/Device/DeviceModel.h"

namespace DeviceBuilder {
    static DeviceModel create(const QByteArray &json) {
        DeviceModel device;
        QJsonParseError error;

        QJsonDocument jsonDoc= QJsonDocument::fromJson(json, &error);
        if (error.error == QJsonParseError::NoError) {
            QJsonObject jsonObject = jsonDoc.object();

            device.uuid = jsonObject["uuid"].toString();
            device.name = jsonObject["name"].toString();
            device.mmcSiteId = jsonObject["siteCode"].toString();
            device.currency = jsonObject["currency"].toString();
            device.language = jsonObject["language"].toString();
            device.apiKey = jsonObject["apiKey"].toString();
        }
        return device;
    }
}
