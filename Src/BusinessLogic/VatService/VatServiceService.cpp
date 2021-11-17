#include "VatServiceService.h"

VatServiceService::VatServiceService(const QString &apiKey, const QString &token): BaseService(apiKey, token)
{

}

void VatServiceService::fetchVat()
{
    endpoint = Constant::WSEndpoint::VAT;
    HttpRequest req {fullPath(Constant::WS_VAT),
        "GET",
        nullptr,
        apiKey,
        bearerToken
    };
    executeRequest(req);
}

// Main callback methods
void VatServiceService::callback(Constant::WSEndpoint endpoint, const QByteArray &response, int status)
{
    switch (endpoint) {
        case Constant::WSEndpoint::VAT:
            emit fetchVatFinished(response, status);
            break;
    }
}
