#include "TopUpService.h"

TopUpService::TopUpService(const QString &apiKey, const QString &token): BaseService(apiKey, token)
{

}

void TopUpService::fetchCuissons()
{
    endpoint = Constant::WSEndpoint::CUISSON;
    HttpRequest req {fullPath(Constant::WS_CUISSON),
        "GET",
        nullptr,
        apiKey,
        bearerToken
    };
    executeRequest(req);
}

void TopUpService::fetchGarnitures()
{
    endpoint = Constant::WSEndpoint::GARNITURE;
    HttpRequest req {fullPath(Constant::WS_GARNITURE),
        "GET",
        nullptr,
        apiKey,
        bearerToken
    };
    executeRequest(req);
}

// Main callback methods
void TopUpService::callback(Constant::WSEndpoint endpoint, const QByteArray &response, int status)
{
    if (endpoint == Constant::WSEndpoint::CUISSON) {
        emit fetchCuissonsFinished(response, status);
    }
    if (endpoint == Constant::WSEndpoint::GARNITURE) {
        emit fetchGarnituresFinished(response, status);
    }
}
