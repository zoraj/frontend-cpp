#pragma once

#include "Src/Application/Base/BaseViewController.h"
#include "Src/Application/Manager/ApplicationManager.h"
#include "Src/BusinessLogic/Signup/SignupViewController.h"
#include "Src/BusinessLogic/Device/CodeConfirmationViewController.h"
#include "Src/BusinessLogic/User/SigninViewController.h"

class SplashViewController : public BaseViewController
{
    Q_OBJECT
public:
    explicit SplashViewController(QObject *parent = nullptr);

    Q_INVOKABLE
    void viewDidLoad() override;
    Q_INVOKABLE
    void viewDidUnload() override;
signals:
    void viewDidLoadFinished(bool hasAPIKeyAndUUIDDevice, QString reason);
};

