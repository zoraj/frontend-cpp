#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QLocale>
#include <QTranslator>
#include <QDateTime>
#include <QFile>
#include <QQuickStyle>
#include <QIcon>

#include "Src/Application/ApplicationManager.h"
#include "Src/Splash/SplashViewController.h"

/*! Log redirection
 * @param
 * @param
 */
void messageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    QString dateTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    QByteArray localMsg = msg.toLocal8Bit();
    QString log = QString("[%1] - %2 (%3:%4, %5)").arg(dateTime, localMsg.constData(),context.file,QString::number(context.line),context.function);

    switch (type) {
    case QtDebugMsg:
        fprintf(stderr, "[%s] - Debug - %s (%s:%u, %s)\n", dateTime.toLocal8Bit().data(), localMsg.constData(), context.file, context.line, context.function);
        break;
    case QtInfoMsg:
        fprintf(stderr, "[%s] - Info - %s (%s:%u, %s)\n", dateTime.toLocal8Bit().data(), localMsg.constData(), context.file, context.line, context.function);
        break;
    case QtWarningMsg:
        fprintf(stderr, "[%s] - Warning: %s (%s:%u, %s)\n",dateTime.toLocal8Bit().data(), localMsg.constData(), context.file, context.line, context.function);
        break;
    case QtCriticalMsg:
        fprintf(stderr, "[%s] - Critical: %s (%s:%u, %s)\n", dateTime.toLocal8Bit().data(), localMsg.constData(), context.file, context.line, context.function);
        break;
    case QtFatalMsg:
        fprintf(stderr, "[%s] - Fatal: %s (%s:%u, %s)\n", dateTime.toLocal8Bit().data(), localMsg.constData(), context.file, context.line, context.function);
        abort();
    }
    QFile outFile("mat.log");
    outFile.open(QIODevice::WriteOnly | QIODevice::Append);
    QTextStream textStream(&outFile);
    textStream << log << Qt::endl;
    outFile.close();
}

int main(int argc, char *argv[])
{
    //qInfo() << QSslSocket::supportsSsl() << QSslSocket::sslLibraryBuildVersionString() << QSslSocket::sslLibraryVersionString();
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    QIcon::setThemeName("gallery");
    QQuickStyle::setStyle("Material");

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "Frontend_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            app.installTranslator(&translator);
            break;
        }
    }

    QQmlApplicationEngine engine;

    // This is the first thing to do when we have an instance of rootContect from engine,
    // so we could easily set context property for our view controllers
    ApplicationManager::getInstance()->getAppContext()->uiContext = engine.rootContext();

    ApplicationManager::getInstance()->initCacheSystem();

    auto splashViewController = new SplashViewController();
    ApplicationManager::getInstance()->getAppContext()->uiContext->setContextProperty("_splashViewController", splashViewController);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
