#pragma once
#include <QObject>
#include "Src/Application/Base/BaseService.h"


class SeasonService : public BaseService
{
    Q_OBJECT
public:
    SeasonService(const QString &apiKey, const QString &token);

    void fetchSeasons();
    void fetchSubSeasons();
    void callback(constant::WSEndpoint endpoint, const QByteArray &response, int status) override;
signals:
    void fetchSeasonsFinished(const QByteArray &, int);
    void fetchSubSeasonsFinished(const QByteArray &, int);
};
