#include "SettingService.h"

SettingService::SettingService(const QString &apiKey, const QString &token): BaseService(apiKey, token)
{

}

void SettingService::fetchSettings()
{
    endpoint = Constant::WSEndpoint::SETTING;
    HttpRequest req {fullPath(Constant::WS_SETTING),
        "GET",
        nullptr,
        apiKey,
        bearerToken
    };
    executeRequest(req);
}

void SettingService::callback(Constant::WSEndpoint endpoint, const QByteArray &response, int status)
{
    switch (endpoint) {
        case Constant::WSEndpoint::SETTING:
            emit fetchSettingsFinished(response, status);
            break;
    }
}
