#include "FamilyService.h"

FamilyService::FamilyService(const QString &apiKey, const QString &token): BaseService(apiKey, token)
{

}


void FamilyService::fetchFamilies()
{
    endpoint = constant::WSEndpoint::FAMILIES;
    HttpRequest req {fullPath(constant::WS_FAMILIES),
        "GET",
        nullptr,
        apiKey,
        bearerToken
    };
    executeRequest(req);
}

void FamilyService::fetchSubFamilies()
{
    endpoint = constant::WSEndpoint::SUB_FAMILIES;
    HttpRequest req {fullPath(constant::WS_SUB_FAMILIES),
        "GET",
        nullptr,
        apiKey,
        bearerToken
    };
    executeRequest(req);
}

// Main callback methods
void FamilyService::callback(constant::WSEndpoint endpoint, const QByteArray &response, int status)
{
    switch (endpoint) {
        case constant::WSEndpoint::FAMILIES:
            emit fetchFamiliesFinished(response, status);
            break;
        case constant::WSEndpoint::SUB_FAMILIES:
            emit fetchSubFamiliesFinished(response, status);
            break;
    }
}
