#pragma once
#include <QObject>
#include "Src/Application/Base/BaseService.h"


class RateGridService : public BaseService
{
    Q_OBJECT
public:
    RateGridService(const QString &apiKey, const QString &token);

    void fetchRateGrids();
    void callback(constant::WSEndpoint endpoint, const QByteArray &response, int status) override;
signals:
    void fetchRateGridsFinished(const QByteArray &, int);
};
