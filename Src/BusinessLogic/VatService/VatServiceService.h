#pragma once

#include "Src/Application/Base/BaseService.h"

class VatServiceService : public BaseService
{
    Q_OBJECT
public:
    VatServiceService(const QString &apiKey, const QString &token);

    void fetchVat();

    void callback(constant::WSEndpoint endpoint, const QByteArray &response, int status) override;
signals:
    void fetchVatFinished(const QByteArray &, int);
};

