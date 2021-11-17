#include "CashingModeService.h"

CashingModeService::CashingModeService(const QString &apiKey, const QString &token): BaseService(apiKey, token)
{

}

void CashingModeService::fetchCashingMode()
{
    endpoint = Constant::WSEndpoint::CASHING_MODE;
    HttpRequest req {fullPath(Constant::WS_CASHING_MODE),
        "GET",
        nullptr,
        apiKey,
        bearerToken
    };
    executeRequest(req);
}

// Main callback methods
void CashingModeService::callback(Constant::WSEndpoint endpoint, const QByteArray &response, int status)
{
    switch (endpoint) {
        case Constant::WSEndpoint::CASHING_MODE:
            emit fetchCashingModeFinished(response, status);
            break;
    }
}
