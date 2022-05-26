#include "SettingService.h"

SettingService::SettingService(const QString &apiKey, const QString &token): BaseService(apiKey, token)
{

}

void SettingService::fetchSettings()
{
    endpoint = constant::WSEndpoint::SETTING;
    HttpRequest req {fullPath(constant::WS_SETTING),
        "GET",
        nullptr,
        apiKey,
        bearerToken
    };
    executeRequest(req);
}

void SettingService::callback(constant::WSEndpoint endpoint, const QByteArray &response, int status)
{
    switch (endpoint) {
        case constant::WSEndpoint::SETTING:
            emit fetchSettingsFinished(response, status);
            break;
    }
}
