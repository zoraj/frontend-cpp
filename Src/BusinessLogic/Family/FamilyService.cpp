#include "FamilyService.h"

FamilyService::FamilyService(const QString &apiKey, const QString &token): BaseService(apiKey, token)
{

}


void FamilyService::fetchFamilies()
{
    endpoint = Constant::WSEndpoint::FAMILIES;
    HttpRequest req {fullPath(Constant::WS_FAMILIES),
        "GET",
        nullptr,
        apiKey,
        bearerToken
    };
    executeRequest(req);
}

void FamilyService::fetchSubFamilies()
{
    endpoint = Constant::WSEndpoint::SUB_FAMILIES;
    HttpRequest req {fullPath(Constant::WS_SUB_FAMILIES),
        "GET",
        nullptr,
        apiKey,
        bearerToken
    };
    executeRequest(req);
}

// Main callback methods
void FamilyService::callback(Constant::WSEndpoint endpoint, const QByteArray &response, int status)
{
    switch (endpoint) {
        case Constant::WSEndpoint::FAMILIES:
            emit fetchFamiliesFinished(response, status);
            break;
        case Constant::WSEndpoint::SUB_FAMILIES:
            emit fetchSubFamiliesFinished(response, status);
            break;
    }
}
