#pragma once

#include "Src/Application/Base/BaseService.h"
#include <QObject>

class UserService : public BaseService
{
    Q_OBJECT
public:
    UserService(const QString &apiKey, const QString &token);

    void postUserCredentials(const QString &pinCode);
    void fetchUsers();
    void callback(constant::WSEndpoint endpoint, const QByteArray &response, int status) override;
signals:
    void postUserCredentialsFinished(const QByteArray &, int);
    void fetchUsersFinished(const QByteArray &, int);

};
