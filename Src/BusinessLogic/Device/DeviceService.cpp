#include "DeviceService.h"

DeviceService::DeviceService(const QString &apiKey, const QString &token): BaseService(apiKey, token)
{

}

void DeviceService::checkCodeConfirmation(const QString &code)
{
    endpoint = constant::WSEndpoint::CODE_DEVICE_CONFIRMATION;
    QString url = constant::WS_E_URL + QString(constant::WS_CODE_DEVICE_CONFIRMATION).arg(code);
    HttpRequest request { url,
                    "GET",
                    nullptr,
                    apiKey,
                    bearerToken};
    executeRequest(request);
}

void DeviceService::callback(constant::WSEndpoint endpoint, const QByteArray &response, int status)
{
    if (endpoint == constant::WSEndpoint::CODE_DEVICE_CONFIRMATION)
        emit checkCodeConfirmationFinished(response, status);
}
