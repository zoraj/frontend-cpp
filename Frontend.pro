QT += quick sql quickcontrols2

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        Src/BusinessLogic/Activities/ActivitiesViewController.cpp \
        Src/Application/Manager/ApplicationManager.cpp \
        Src/Application/Base/BaseService.cpp \
        Src/Application/Base/BaseViewController.cpp \
        Src/BusinessLogic/Activities/ActivityService.cpp \
        Src/BusinessLogic/CashingMode/CashingModeService.cpp \
        Src/BusinessLogic/Client/ClientService.cpp \
        Src/BusinessLogic/Device/CodeConfirmationViewController.cpp \
        Src/BusinessLogic/Device/DeviceService.cpp \
        Src/BusinessLogic/Family/FamilyService.cpp \
        Src/BusinessLogic/Order/OrderViewController.cpp \
        Src/BusinessLogic/OrderCheckout/OrderCheckoutViewController.cpp \
        Src/BusinessLogic/Product/ProductService.cpp \
        Src/BusinessLogic/Room/RoomService.cpp \
        Src/BusinessLogic/Season/SeasonService.cpp \
        Src/BusinessLogic/Segmentation/SegmentationService.cpp \
        Src/BusinessLogic/Setting/SettingService.cpp \
        Src/BusinessLogic/TopUp/TopUpService.cpp \
        Src/BusinessLogic/User/SigninViewController.cpp \
        Src/BusinessLogic/Signup/SignupViewController.cpp \
        Src/BusinessLogic/Splash/SplashViewController.cpp \
        Src/BusinessLogic/User/UserService.cpp \
        Src/Application/Util/HttpUtil.cpp \
        Src/BusinessLogic/VatService/VatServiceService.cpp \
        main.cpp

RESOURCES += qml.qrc

TRANSLATIONS += \
    Frontend_fr_FR.ts \
    Frontend_en_US.ts

CONFIG += lrelease
CONFIG += embed_translations

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    Src/BusinessLogic/Activities/ActivitiesViewController.h \
    Src/Application/Manager/ApplicationManager.h \
    Src/Application/Base/BaseService.h \
    Src/Application/Base/BaseViewController.h \
    Src/BusinessLogic/Activities/ActivityBuilder.h \
    Src/BusinessLogic/Activities/ActivityCache.h \
    Src/BusinessLogic/Activities/ActivityModel.h \
    Src/BusinessLogic/Activities/ActivityService.h \
    Src/BusinessLogic/CashingMode/CashingModeBuilder.h \
    Src/BusinessLogic/CashingMode/CashingModeCache.h \
    Src/BusinessLogic/CashingMode/CashingModeModel.h \
    Src/BusinessLogic/CashingMode/CashingModeService.h \
    Src/BusinessLogic/Client/ClientBuilder.h \
    Src/BusinessLogic/Client/ClientCache.h \
    Src/BusinessLogic/Client/ClientModel.h \
    Src/BusinessLogic/Client/ClientService.h \
    Src/BusinessLogic/Device/CodeConfirmationViewController.h \
    Src/BusinessLogic/Device/DeviceBuilder.h \
    Src/BusinessLogic/Device/DeviceModel.h \
    Src/BusinessLogic/Device/DeviceService.h \
    Src/BusinessLogic/Family/FamilyBuilder.h \
    Src/BusinessLogic/Family/FamilyCache.h \
    Src/BusinessLogic/Family/FamilyModel.h \
    Src/BusinessLogic/Family/FamilyService.h \
    Src/BusinessLogic/Family/SubFamilyBuilder.h \
    Src/BusinessLogic/Family/SubFamilyCache.h \
    Src/BusinessLogic/Family/SubFamilyModel.h \
    Src/BusinessLogic/Order/OrderViewController.h \
    Src/BusinessLogic/OrderCheckout/OrderCheckoutViewController.h \
    Src/BusinessLogic/Product/PosGroupProductBuilder.h \
    Src/BusinessLogic/Product/PosGroupProductCache.h \
    Src/BusinessLogic/Product/PosGroupProductModel.h \
    Src/BusinessLogic/Product/PosProductBuilder.h \
    Src/BusinessLogic/Product/PosProductCache.h \
    Src/BusinessLogic/Product/PosProductModel.h \
    Src/BusinessLogic/Product/ProductService.h \
    Src/BusinessLogic/Room/RoomBuilder.h \
    Src/BusinessLogic/Room/RoomCache.h \
    Src/BusinessLogic/Room/RoomCategoryBuilder.h \
    Src/BusinessLogic/Room/RoomCategoryCache.h \
    Src/BusinessLogic/Room/RoomCategoryModel.h \
    Src/BusinessLogic/Room/RoomModel.h \
    Src/BusinessLogic/Room/RoomService.h \
    Src/BusinessLogic/Room/RoomTypeBuilder.h \
    Src/BusinessLogic/Room/RoomTypeCache.h \
    Src/BusinessLogic/Room/RoomTypeModel.h \
    Src/BusinessLogic/Season/SeasonBuilder.h \
    Src/BusinessLogic/Season/SeasonCache.h \
    Src/BusinessLogic/Season/SeasonModel.h \
    Src/BusinessLogic/Season/SeasonService.h \
    Src/BusinessLogic/Season/SubSeasonBuilder.h \
    Src/BusinessLogic/Season/SubSeasonCache.h \
    Src/BusinessLogic/Season/SubSeasonModel.h \
    Src/BusinessLogic/Segmentation/ClientTypeBuilder.h \
    Src/BusinessLogic/Segmentation/ClientTypeCache.h \
    Src/BusinessLogic/Segmentation/ClientTypeModel.h \
    Src/BusinessLogic/Segmentation/PrescripteurBuilder.h \
    Src/BusinessLogic/Segmentation/PrescripteurCache.h \
    Src/BusinessLogic/Segmentation/PrescripteurModel.h \
    Src/BusinessLogic/Segmentation/SegmentationBuilder.h \
    Src/BusinessLogic/Segmentation/SegmentationCache.h \
    Src/BusinessLogic/Segmentation/SegmentationModel.h \
    Src/BusinessLogic/Segmentation/SegmentationService.h \
    Src/BusinessLogic/Setting/SettingBuilder.h \
    Src/BusinessLogic/Setting/SettingCache.h \
    Src/BusinessLogic/Setting/SettingModel.h \
    Src/BusinessLogic/Setting/SettingService.h \
    Src/BusinessLogic/TopUp/AccompanimentBuilder.h \
    Src/BusinessLogic/TopUp/AccompanimentCache.h \
    Src/BusinessLogic/TopUp/CookingBuilder.h \
    Src/BusinessLogic/TopUp/CookingCache.h \
    Src/BusinessLogic/TopUp/TopUpModel.h \
    Src/BusinessLogic/TopUp/TopUpService.h \
    Src/BusinessLogic/User/SigninViewController.h \
    Src/BusinessLogic/Signup/SignupViewController.h \
    Src/BusinessLogic/Splash/SplashViewController.h \
    Src/BusinessLogic/User/UserBuilder.h \
    Src/BusinessLogic/User/UserModel.h \
    Src/BusinessLogic/User/UserService.h \
    Src/Application/Util/Constant.h \
    Src/Application/Util/HttpRequest.h \
    Src/Application/Util/HttpUtil.h \
    Src/BusinessLogic/VatService/VatBuilder.h \
    Src/BusinessLogic/VatService/VatCache.h \
    Src/BusinessLogic/VatService/VatModel.h \
    Src/BusinessLogic/VatService/VatServiceService.h

DISTFILES += \
    Frontend_en_US.ts \
    Readme.md \
    qtquickcontrols2.conf

#Application version
VERSION_MAJOR = 1
VERSION_MINOR = 0
VERSION_BUILD = 0

DEFINES += "VERSION_MAJOR=$$VERSION_MAJOR"\
       "VERSION_MINOR=$$VERSION_MINOR"\
       "VERSION_BUILD=$$VERSION_BUILD"

VERSION = $${VERSION_MAJOR}.$${VERSION_MINOR}.$${VERSION_BUILD}
