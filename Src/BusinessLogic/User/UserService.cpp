#include "UserService.h"

UserService::UserService(const QString &apiKey, const QString &token): BaseService(apiKey, token)
{

}


void UserService::postUserCredentials(const QString &pinCode)
{
    endpoint = Constant::WSEndpoint::LOGIN;
    QJsonObject payload;
    payload.insert("pinCode", pinCode);
    HttpRequest request { fullPath(Constant::WS_LOGIN),
                "POST",
                &payload,
                apiKey,
                nullptr};
    executeRequest(request);
}

void UserService::fetchUsers()
{
    endpoint = Constant::WSEndpoint::USERS;
    HttpRequest req {fullPath(Constant::WS_USERS),
        "GET",
        nullptr,
        apiKey,
        bearerToken
    };
    executeRequest(req);
}

// Main callback methods
void UserService::callback(Constant::WSEndpoint endpoint, const QByteArray &response, int status)
{
    if (endpoint == Constant::WSEndpoint::USERS)
        emit fetchUsersFinished(response, status);
    if (endpoint == Constant::WSEndpoint::LOGIN)
        emit postUserCredentialsFinished(response, status);
}
