#include "VatServiceService.h"

VatServiceService::VatServiceService(const QString &apiKey, const QString &token): BaseService(apiKey, token)
{

}

void VatServiceService::fetchVat()
{
    endpoint = constant::WSEndpoint::VAT;
    HttpRequest req {fullPath(constant::WS_VAT),
        "GET",
        nullptr,
        apiKey,
        bearerToken
    };
    executeRequest(req);
}

// Main callback methods
void VatServiceService::callback(constant::WSEndpoint endpoint, const QByteArray &response, int status)
{
    switch (endpoint) {
        case constant::WSEndpoint::VAT:
            emit fetchVatFinished(response, status);
            break;
    }
}
