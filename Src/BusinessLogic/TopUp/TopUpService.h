#pragma once

#include "Src/Application/Base/BaseService.h"

class TopUpService : public BaseService
{
    Q_OBJECT
public:
    TopUpService(const QString &apiKey, const QString &token);
    void fetchCuissons();
    void fetchGarnitures();

    void callback(constant::WSEndpoint endpoint, const QByteArray &response, int status) override;
signals:
    void fetchCuissonsFinished(const QByteArray &, int);
    void fetchGarnituresFinished(const QByteArray &, int);

};
