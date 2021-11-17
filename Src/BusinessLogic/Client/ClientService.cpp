#include "ClientService.h"

ClientService::ClientService(const QString &apiKey, const QString &token): BaseService(apiKey, token)
{

}

void ClientService::fetchClients()
{
    endpoint = Constant::WSEndpoint::CLIENTS;
    HttpRequest req {fullPath(Constant::WS_CLIENTS),
        "GET",
        nullptr,
        apiKey,
        bearerToken
    };
    executeRequest(req);
}

void ClientService::callback(Constant::WSEndpoint endpoint, const QByteArray &response, int status)
{
    switch (endpoint) {
        case Constant::WSEndpoint::CLIENTS:
            emit fetchClientsFinished(response, status);
            break;
    }
}
