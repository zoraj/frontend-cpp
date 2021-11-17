#pragma once
#include "Src/Application/Base/BaseViewController.h"
#include "Src/BusinessLogic/Device/DeviceService.h"
#include "Src/BusinessLogic/Device/DeviceBuilder.h"
#include "Src/BusinessLogic/Setting/SettingModel.h"
#include "Src/BusinessLogic/Setting/SettingCache.h"

class CodeConfirmationViewController : public BaseViewController
{
    Q_OBJECT
    void persistDeviceInfos(const DeviceModel &device);
public:
    explicit CodeConfirmationViewController(QObject *parent = nullptr);

signals:
    void validateCodeTriggeredFinished(bool result);
public slots:
    void validateCodeTriggered(const QString &code);
};
