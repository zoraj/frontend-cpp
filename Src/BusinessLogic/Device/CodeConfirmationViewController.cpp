#include "CodeConfirmationViewController.h"

// Private methods
void CodeConfirmationViewController::persistDeviceInfos(const Device &device)
{
    QList<Setting> settings;
    Setting setting = Setting("UUID", device.uuid);
    settings.append(setting);
    setting = Setting("API-KEY", device.apiKey);
    settings.append(setting);
    setting = Setting("NAME", device.name);
    settings.append(setting);
    setting = Setting("SITE-ID", device.mmcSiteId);
    settings.append(setting);
    setting = Setting("LANGUAGE", device.language);
    settings.append(setting);
    setting = Setting("CURRENCY", device.currency);
    settings.append(setting);
    cache::setting::persist(settings, true);

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
        if (status == constant::HttpStatusCode::OK) {
            auto device = builder::device::create(response); // Should return unique device.  TODO
            // Persist data
            persistDeviceInfos(device);
        }
        else {
            qDebug() << "Something went wrong. " + response;
        }
        qInfo()<< status;
        emit validateCodeTriggeredFinished(status == constant::HttpStatusCode::OK);
        deviceService->deleteLater();
    });
}

