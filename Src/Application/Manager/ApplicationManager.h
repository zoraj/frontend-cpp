/*!
 *  @file ApplicationManager.h
 *  @brief This header file will be useful for the doxygen.
 *
 *  @author Zo Rajaonarivony <zo@multimicro.fr>
 *  @date
 */

#pragma once

#include <QObject>
#include <QDate>
#include <QQmlContext>
#include <QDir>
#include <QSqlDatabase>
#include <QException>
#include <QTimer>

#include "Src/Application/Util/Constant.h"
#include "Src/BusinessLogic/User/User.h"
#include "Src/BusinessLogic/Setting/SettingCache.h"

/* Blueprint for storing global context */
struct ApplicationContext
{
    QString apiKey;
    QString deviceUuid;
    QDate currentDate; // Not always today
    QTimer *timer;
    User *user = nullptr;
    bool isCacheNeedToReload = true;
    int currentActivity = constant::UNDEFINED_INT;
    QString currentPOSService = "M"; // M: MIDI, S: SOIR
    QThread *cacheThread;
    QVector<int> ordersPool; // It will store <orderId> . Needed for the cloud syncing
    QQmlContext *uiContext;
    //OrderWorker *orderWorker = nullptr;
};


class ApplicationManager : public QObject
{
    Q_OBJECT
    static ApplicationManager *instance;
    ApplicationContext *applicationContext = nullptr;
public:
    explicit ApplicationManager(QObject *parent = nullptr);
    static ApplicationManager *getInstance();
    ApplicationContext *getAppContext();

    void initCacheSystem();
    void loadSetting();
signals:

};
