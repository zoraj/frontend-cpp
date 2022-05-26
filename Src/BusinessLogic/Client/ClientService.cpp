#include "ClientService.h"

ClientService::ClientService(const QString &apiKey, const QString &token): BaseService(apiKey, token)
{

}

void ClientService::fetchClients()
{
    endpoint = constant::WSEndpoint::CLIENTS;
    HttpRequest req {fullPath(constant::WS_CLIENTS),
        "GET",
        nullptr,
        apiKey,
        bearerToken
    };
    executeRequest(req);
}

void ClientService::callback(constant::WSEndpoint endpoint, const QByteArray &response, int status)
{
    switch (endpoint) {
        case constant::WSEndpoint::CLIENTS:
            emit fetchClientsFinished(response, status);
            break;
    }
}
