#include "ApplicationManager.h"

/* Constructor And Destructor - Start */
ApplicationManager *ApplicationManager::instance = nullptr;
ApplicationManager::ApplicationManager(QObject *parent) : QObject(parent)
{

}
/* Constructor And Destructor - End */

/* Private Methods - Start */

/* Private Methods - End */


/* Public Methods - Start */
ApplicationManager *ApplicationManager::getInstance()
{
    if (ApplicationManager::instance == nullptr) {
        ApplicationManager::instance = new ApplicationManager();
    }
    return ApplicationManager::instance;
}

ApplicationContext *ApplicationManager::getAppContext()
{
    if (applicationContext == nullptr)
        applicationContext = new ApplicationContext();
    return applicationContext;
}

/*!
 * @brief Initialize the embeded sqlite database
 *
 * @details Look if the embedded database is on the user path, if not, copy it
 *          Then open an instance
 *
 * @param
 * @return
 */
void ApplicationManager::initCacheSystem()
{
    QDir directory(QDir::homePath());
    QString databasePath = directory.absolutePath();
    qInfo() << "Database path : " << databasePath;
    QString databaseFile = databasePath  + "/" +  constant::DB_CACHE;

    bool cacheExists = QFile::exists(databaseFile);

    if (!cacheExists) {
        qInfo() << "Caching database doesn't exist";
        QFile cacheDb(":/Assets/Db/" + constant::DB_CACHE);
        bool cacheCopyStatus = cacheDb.copy(databaseFile);
        if (cacheCopyStatus) {
            qInfo() << "Copying database cache successfully";
            // Make it writable
            QFile cacheFile(databaseFile);
            cacheFile.setPermissions(QFileDevice::ReadOwner | QFileDevice::WriteOwner);
        }
        else {
            throw "Copying caching database failed." ;
        }
    }

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(databaseFile);
    try {
        db.open();
    }
    catch(QException e) {
        throw "Something went wrong while opening database cache" + QString::fromUtf8(e.what());
    }
}

/*!
 * @brief Load setting from the embedded database
 *
 * @details
 *
 *
 * @param
 * @return
 */
void ApplicationManager::loadSetting()
{
    auto setting =  cache::setting::get("DATE_LOGICIELLE");
    applicationContext->currentDate = QDate::fromString(setting.valeur, "yyyy-MM-dd");

    setting =  cache::setting::get("API-KEY");
    applicationContext->apiKey = setting.valeur;

    setting =  cache::setting::get("UUID");
    applicationContext->deviceUuid = setting.valeur;
}

/* Public Methods - End */

/* UI Logic - Start */

/* UI Logic - End */
