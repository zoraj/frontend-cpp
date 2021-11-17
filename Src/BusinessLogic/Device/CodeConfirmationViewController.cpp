#include "CodeConfirmationViewController.h"

// Private methods
void CodeConfirmationViewController::persistDeviceInfos(const DeviceModel &device)
{
    QList<SettingModel> settings;
    SettingModel setting = SettingModel("UUID", device.uuid);
    settings.append(setting);
    setting = SettingModel("API-KEY", device.apiKey);
    settings.append(setting);
    setting = SettingModel("NAME", device.name);
    settings.append(setting);
    setting = SettingModel("SITE-ID", device.mmcSiteId);
    settings.append(setting);
    setting = SettingModel("LANGUAGE", device.language);
    settings.append(setting);
    setting = SettingModel("CURRENCY", device.currency);
    settings.append(setting);
    Cache::Setting::persist(settings, true);

    ApplicationManager::getInstance()->getAppContext()->apiKey = device.apiKey;
    ApplicationManager::getInstance()->getAppContext()->deviceUuid = device.uuid;
}

CodeConfirmationViewController::CodeConfirmationViewController(QObject *parent) : BaseViewController(parent)
{

}

void CodeConfirmationViewController::validateCodeTriggered(const QString &code)
{
    auto deviceService = new DeviceService(nullptr, nullptr);
    deviceService->checkCodeConfirmation(code);
    QObject::connect(deviceService, &DeviceService::checkCodeConfirmationFinished, [=] (const QByteArray &response, const int status){
        if (status == Constant::HttpStatusCode::OK) {
            auto device = DeviceBuilder::create(response); // Should return unique device.  TODO
            // Persist data
            persistDeviceInfos(device);
        }
        else {
            qDebug() << "Something went wrong. " + response;
        }
        qInfo()<< status;
        emit validateCodeTriggeredFinished(status == Constant::HttpStatusCode::OK);
        deviceService->deleteLater();
    });
}

