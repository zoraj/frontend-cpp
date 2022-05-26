#pragma once

#include "Src/Application/Base/BaseService.h"

class CashingModeService : public BaseService
{
    Q_OBJECT
public:
    CashingModeService(const QString &apiKey, const QString &token);

    void fetchCashingMode();

    void callback(constant::WSEndpoint endpoint, const QByteArray &response, int status) override;
signals:
    void fetchCashingModeFinished(const QByteArray &, int);
};

