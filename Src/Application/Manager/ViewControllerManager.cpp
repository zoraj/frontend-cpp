#include "ViewControllerManager.h"

ViewControllerManager::ViewControllerManager(QObject *parent) : QObject(parent)
{

}

void ViewControllerManager::initControllers(Constant::Module module)
{
    signupViewController = new SignupViewController();
    ApplicationManager::getInstance()->getAppContext()->uiContext->setContextProperty("_signupViewController", signupViewController);

    codeConfirmationViewController = new CodeConfirmationViewController();
    ApplicationManager::getInstance()->getAppContext()->uiContext->setContextProperty("_codeConfirmationViewController", codeConfirmationViewController);

    orderViewController = new OrderViewController();
    ApplicationManager::getInstance()->getAppContext()->uiContext->setContextProperty("_orderViewController", orderViewController);

    orderCheckoutViewController = new OrderCheckoutViewController();
    ApplicationManager::getInstance()->getAppContext()->uiContext->setContextProperty("_orderCheckoutViewController", orderCheckoutViewController);
}

void ViewControllerManager::releaseControllers(int module)
{

}
