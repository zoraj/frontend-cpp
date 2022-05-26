#pragma once
#include <QObject>
#include "Src/Application/Base/BaseService.h"


class ClientService : public BaseService
{
    Q_OBJECT
public:
    ClientService(const QString &apiKey, const QString &token);
    void fetchClients();
    void callback(constant::WSEndpoint endpoint, const QByteArray &response, int status) override;

signals:
    void fetchClientsFinished(const QByteArray &, int);
};
