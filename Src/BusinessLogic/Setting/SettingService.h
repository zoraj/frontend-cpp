#pragma once

#include <QObject>
#include "Src/Application/Base/BaseService.h"

class SettingService : public BaseService
{
    Q_OBJECT
public:
    SettingService(const QString &apiKey, const QString &token);
    void fetchSettings();
    void callback(Constant::WSEndpoint endpoint, const QByteArray &response, int status) override;
signals:
    void fetchSettingsFinished(const QByteArray &, int);
};
