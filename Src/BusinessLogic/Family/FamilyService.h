#pragma once

#include "Src/Application/Base/BaseService.h"

class FamilyService : public BaseService
{
    Q_OBJECT
public:
    FamilyService(const QString &apiKey, const QString &token);

    void fetchFamilies();
    void fetchSubFamilies();

    void callback(Constant::WSEndpoint endpoint, const QByteArray &response, int status) override;
signals:
    void fetchFamiliesFinished(const QByteArray &, int);
    void fetchSubFamiliesFinished(const QByteArray &, int);
};
