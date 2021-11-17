#include "SeasonService.h"

SeasonService::SeasonService(const QString &apiKey, const QString &token): BaseService(apiKey, token)
{

}


void SeasonService::fetchSeasons()
{
    endpoint = Constant::WSEndpoint::SEASONS;
    HttpRequest req {fullPath(Constant::WS_SEASONS),
        "GET",
        nullptr,
        apiKey,
        bearerToken
    };
    executeRequest(req);
}

void SeasonService::fetchSubSeasons()
{
    endpoint = Constant::WSEndpoint::SUB_SEASONS;
    HttpRequest req {fullPath(Constant::WS_SUB_SEASONS),
        "GET",
        nullptr,
        apiKey,
        bearerToken
    };
    executeRequest(req);
}

// Main callback methods
void SeasonService::callback(Constant::WSEndpoint endpoint, const QByteArray &response, int status)
{
    switch (endpoint) {
        case Constant::WSEndpoint::SEASONS:
            emit fetchSeasonsFinished(response, status);
            break;
        case Constant::WSEndpoint::SUB_SEASONS:
            emit fetchSubSeasonsFinished(response, status);
            break;
    }
}
