#include "CashingModeService.h"

CashingModeService::CashingModeService(const QString &apiKey, const QString &token): BaseService(apiKey, token)
{

}

void CashingModeService::fetchCashingMode()
{
    endpoint = constant::WSEndpoint::CASHING_MODE;
    HttpRequest req {fullPath(constant::WS_CASHING_MODE),
        "GET",
        nullptr,
        apiKey,
        bearerToken
    };
    executeRequest(req);
}

// Main callback methods
void CashingModeService::callback(constant::WSEndpoint endpoint, const QByteArray &response, int status)
{
    switch (endpoint) {
        case constant::WSEndpoint::CASHING_MODE:
            emit fetchCashingModeFinished(response, status);
            break;
    }
}
