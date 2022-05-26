#include "RateGridService.h"

RateGridService::RateGridService(const QString &apiKey, const QString &token): BaseService(apiKey, token)
{

}


void RateGridService::fetchRateGrids()
{
    endpoint = constant::WSEndpoint::RATE_GRID;
    HttpRequest req {fullPath(constant::WS_RATE_GRID),
        "GET",
        nullptr,
        apiKey,
        bearerToken
    };
    executeRequest(req);
}

// Main callback methods
void RateGridService::callback(constant::WSEndpoint endpoint, const QByteArray &response, int status)
{
    switch (endpoint) {
        case constant::WSEndpoint::RATE_GRID:
            emit fetchRateGridsFinished(response, status);
            break;
    }
}
