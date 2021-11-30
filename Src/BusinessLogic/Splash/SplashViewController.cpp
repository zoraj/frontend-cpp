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
        const int moduleId = 2;// POS = 0; RECEP = 1, RESA = 2, HOUSEKEEPING = 3, COLLECTIVITE = 4
        auto module = static_cast<Constant::Module>(moduleId);

        auto viewControllerManager = new ViewControllerManager();
        viewControllerManager->initControllers(module);
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
