#pragma once

#include "Src/Application/Base/BaseService.h"

class ActivityService : public BaseService
{
    Q_OBJECT
public:
    ActivityService(const QString &apiKey, const QString &token);

    void fetchActivities();

    void callback(constant::WSEndpoint endpoint, const QByteArray &response, int status) override;
signals:
    void fetchActivitiesFinished(const QByteArray &, int);
};

