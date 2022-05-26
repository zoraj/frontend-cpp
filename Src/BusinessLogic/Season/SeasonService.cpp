#include "SeasonService.h"

SeasonService::SeasonService(const QString &apiKey, const QString &token): BaseService(apiKey, token)
{

}


void SeasonService::fetchSeasons()
{
    endpoint = constant::WSEndpoint::SEASONS;
    HttpRequest req {fullPath(constant::WS_SEASONS),
        "GET",
        nullptr,
        apiKey,
        bearerToken
    };
    executeRequest(req);
}

void SeasonService::fetchSubSeasons()
{
    endpoint = constant::WSEndpoint::SUB_SEASONS;
    HttpRequest req {fullPath(constant::WS_SUB_SEASONS),
        "GET",
        nullptr,
        apiKey,
        bearerToken
    };
    executeRequest(req);
}

// Main callback methods
void SeasonService::callback(constant::WSEndpoint endpoint, const QByteArray &response, int status)
{
    switch (endpoint) {
        case constant::WSEndpoint::SEASONS:
            emit fetchSeasonsFinished(response, status);
            break;
        case constant::WSEndpoint::SUB_SEASONS:
            emit fetchSubSeasonsFinished(response, status);
            break;
    }
}
