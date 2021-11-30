#pragma once
#include <QObject>
#include "Src/Application/Manager/ApplicationManager.h"
#include "Src/BusinessLogic/Signup/SignupViewController.h"
#include "Src/BusinessLogic/Device/CodeConfirmationViewController.h"
#include "Src/BusinessLogic/Order/OrderViewController.h"
#include "Src/BusinessLogic/OrderCheckout/OrderCheckoutViewController.h"


class ViewControllerManager : public QObject
{
    Q_OBJECT
    SignupViewController *signupViewController;
    CodeConfirmationViewController *codeConfirmationViewController;
    OrderViewController *orderViewController;
    OrderCheckoutViewController *orderCheckoutViewController;
public:
    explicit ViewControllerManager(QObject *parent = nullptr);

    void initControllers(Constant::Module module);
    void releaseControllers(int module);

signals:

};
