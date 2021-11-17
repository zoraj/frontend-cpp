#pragma once

#include <QObject>
#include "Src/Application/Manager/ApplicationManager.h"

#define APP_CONTEXT_API_KEY ApplicationManager::getInstance()->getAppContext()->apiKey
#define APP_CONTEXT_TOKEN (ApplicationManager::getInstance()->getAppContext()->user) != nullptr ? ApplicationManager::getInstance()->getAppContext()->user->token : nullptr

class BaseViewController : public QObject
{
    Q_OBJECT
protected:
    QString *apiKey = nullptr;
    //UserModel *user = nullptr;
    QString *deviceUuid = nullptr;

public:
    explicit BaseViewController(QObject *parent = nullptr);
    Q_INVOKABLE
    virtual void viewDidLoad() {};
    Q_INVOKABLE
    virtual void viewDidUnload() {};
};
