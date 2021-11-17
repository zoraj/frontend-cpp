#include "SplashViewController.h"

/* Constructor And Destructor - Start */
SplashViewController::SplashViewController(QObject *parent) : BaseViewController(parent)
{

}
/* Constructor And Destructor - End */

/* Private Methods - Start */

/* Private Methods - End */


/* Public Methods - Start */

/* Public Methods - End */


/* UI Logic - Start */
void SplashViewController::viewDidLoad()
{
    ApplicationManager::getInstance()->loadSetting();
    bool hasAPIKeyAndUUIDDevice = !ApplicationManager::getInstance()->getAppContext()->apiKey.isNull()
            && !ApplicationManager::getInstance()->getAppContext()->deviceUuid.isNull();

    // Check if the actual token is valid
    if (hasAPIKeyAndUUIDDevice && ApplicationManager::getInstance()->getAppContext()->user != nullptr) {
        qInfo() << "Current user" << ApplicationManager::getInstance()->getAppContext()->user->firstname;
    }
    else {
        auto signupViewController = new SignupViewController();
        ApplicationManager::getInstance()->getAppContext()->uiContext->setContextProperty("_signupViewController", signupViewController);

        auto codeConfirmationViewController = new CodeConfirmationViewController();
        ApplicationManager::getInstance()->getAppContext()->uiContext->setContextProperty("_codeConfirmationViewController", codeConfirmationViewController);
    }

    auto signinViewController = new SigninViewController();
    ApplicationManager::getInstance()->getAppContext()->uiContext->setContextProperty("_signinViewController", signinViewController);

    // Notify the view
    emit viewDidLoadFinished(hasAPIKeyAndUUIDDevice, "SUCCESS");
}

void SplashViewController::viewDidUnload()
{

}
/* UI Logic - End */
