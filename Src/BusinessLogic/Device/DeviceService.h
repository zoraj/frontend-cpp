#pragma once
#include "Src/Application/Base/BaseService.h"
#include "Src/Application/Util/Constant.h"

class DeviceService: public BaseService
{
    Q_OBJECT
public:
    DeviceService(const QString &apiKey, const QString &token);
    void checkCodeConfirmation( const QString &code);

    void callback(constant::WSEndpoint endpoint, const QByteArray &response, int status) override;
signals:
  void checkCodeConfirmationFinished(const QByteArray &response, int status);
};

