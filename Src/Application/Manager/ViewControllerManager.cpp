#include "ViewControllerManager.h"

ViewControllerManager::ViewControllerManager(QObject *parent) : QObject(parent)
{

}

void ViewControllerManager::initControllers(constant::Module module)
{
    signupViewController_ = new SignupViewController();
    ApplicationManager::getInstance()->getAppContext()->uiContext->setContextProperty("_signupViewController", signupViewController_);

    codeConfirmationViewController_ = new CodeConfirmationViewController();
    ApplicationManager::getInstance()->getAppContext()->uiContext->setContextProperty("_codeConfirmationViewController", codeConfirmationViewController_);

    orderViewController_ = new OrderViewController();
    ApplicationManager::getInstance()->getAppContext()->uiContext->setContextProperty("_orderViewController", orderViewController_);

    orderCheckoutViewController_ = new OrderCheckoutViewController();
    ApplicationManager::getInstance()->getAppContext()->uiContext->setContextProperty("_orderCheckoutViewController", orderCheckoutViewController_);

    bookingDetailViewController_ = new BookingDetailViewController();
    ApplicationManager::getInstance()->getAppContext()->uiContext->setContextProperty("_bookingDetailViewController", bookingDetailViewController_);

    bookingPlanningViewController_ = new BookingPlanningViewController();
    ApplicationManager::getInstance()->getAppContext()->uiContext->setContextProperty("_bookingPlanningViewController", bookingPlanningViewController_);
}

void ViewControllerManager::releaseControllers(int module)
{
    delete signupViewController_;
    delete codeConfirmationViewController_;
    delete orderViewController_;
    delete orderCheckoutViewController_;
    delete bookingDetailViewController_;
}
