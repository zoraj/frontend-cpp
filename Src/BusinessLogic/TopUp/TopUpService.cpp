#include "TopUpService.h"

TopUpService::TopUpService(const QString &apiKey, const QString &token): BaseService(apiKey, token)
{

}

void TopUpService::fetchCuissons()
{
    endpoint = constant::WSEndpoint::CUISSON;
    HttpRequest req {fullPath(constant::WS_CUISSON),
        "GET",
        nullptr,
        apiKey,
        bearerToken
    };
    executeRequest(req);
}

void TopUpService::fetchGarnitures()
{
    endpoint = constant::WSEndpoint::GARNITURE;
    HttpRequest req {fullPath(constant::WS_GARNITURE),
        "GET",
        nullptr,
        apiKey,
        bearerToken
    };
    executeRequest(req);
}

// Main callback methods
void TopUpService::callback(constant::WSEndpoint endpoint, const QByteArray &response, int status)
{
    if (endpoint == constant::WSEndpoint::CUISSON) {
        emit fetchCuissonsFinished(response, status);
    }
    if (endpoint == constant::WSEndpoint::GARNITURE) {
        emit fetchGarnituresFinished(response, status);
    }
}
