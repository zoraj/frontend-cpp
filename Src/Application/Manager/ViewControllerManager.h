#pragma once
#include <QObject>
#include "Src/Application/Manager/ApplicationManager.h"
#include "Src/BusinessLogic/Signup/SignupViewController.h"
#include "Src/BusinessLogic/Device/CodeConfirmationViewController.h"
#include "Src/BusinessLogic/Order/OrderViewController.h"
#include "Src/BusinessLogic/OrderCheckout/OrderCheckoutViewController.h"
#include "Src/BusinessLogic/Booking/BookingDetailViewController.h"
#include "Src/BusinessLogic/Planning/BookingPlanningViewController.h"


class ViewControllerManager : public QObject
{
    Q_OBJECT
    SignupViewController *signupViewController_;
    CodeConfirmationViewController *codeConfirmationViewController_;
    OrderViewController *orderViewController_;
    OrderCheckoutViewController *orderCheckoutViewController_;
    BookingDetailViewController *bookingDetailViewController_;
    BookingPlanningViewController *bookingPlanningViewController_;
public:
    explicit ViewControllerManager(QObject *parent = nullptr);

    void initControllers(constant::Module module);
    void releaseControllers(int module);

signals:

};
