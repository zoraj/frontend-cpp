#include "UserService.h"

UserService::UserService(const QString &apiKey, const QString &token): BaseService(apiKey, token)
{

}


void UserService::postUserCredentials(const QString &pinCode)
{
    endpoint = constant::WSEndpoint::LOGIN;
    QJsonObject payload;
    payload.insert("pinCode", pinCode);
    HttpRequest request { fullPath(constant::WS_LOGIN),
                "POST",
                &payload,
                apiKey,
                nullptr};
    executeRequest(request);
}

void UserService::fetchUsers()
{
    endpoint = constant::WSEndpoint::USERS;
    HttpRequest req {fullPath(constant::WS_USERS),
        "GET",
        nullptr,
        apiKey,
        bearerToken
    };
    executeRequest(req);
}

// Main callback methods
void UserService::callback(constant::WSEndpoint endpoint, const QByteArray &response, int status)
{
    if (endpoint == constant::WSEndpoint::USERS)
        emit fetchUsersFinished(response, status);
    if (endpoint == constant::WSEndpoint::LOGIN)
        emit postUserCredentialsFinished(response, status);
}
