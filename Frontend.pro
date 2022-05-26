QT += quick sql quickcontrols2

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        Src/Application/Manager/ViewControllerManager.cpp \
        Src/BusinessLogic/Activities/ActivitiesViewController.cpp \
        Src/Application/Manager/ApplicationManager.cpp \
        Src/Application/Base/BaseService.cpp \
        Src/Application/Base/BaseViewController.cpp \
        Src/BusinessLogic/Activities/ActivityListModel.cpp \
        Src/BusinessLogic/Activities/ActivityService.cpp \
        Src/BusinessLogic/Booking/BookingDetailViewController.cpp \
        Src/BusinessLogic/Booking/BookingRoomListModel.cpp \
        Src/BusinessLogic/Booking/BookingService.cpp \
        Src/BusinessLogic/CashingMode/CashingModeListModel.cpp \
        Src/BusinessLogic/CashingMode/CashingModeService.cpp \
        Src/BusinessLogic/Client/ClientListModel.cpp \
        Src/BusinessLogic/Client/ClientService.cpp \
        Src/BusinessLogic/Device/CodeConfirmationViewController.cpp \
        Src/BusinessLogic/Device/DeviceService.cpp \
        Src/BusinessLogic/Family/FamilyService.cpp \
        Src/BusinessLogic/Order/OrderDetailListModel.cpp \
        Src/BusinessLogic/Order/OrderListModel.cpp \
        Src/BusinessLogic/Order/OrderService.cpp \
        Src/BusinessLogic/Order/OrderViewController.cpp \
        Src/BusinessLogic/OrderCheckout/OrderCheckoutListModel.cpp \
        Src/BusinessLogic/OrderCheckout/OrderCheckoutViewController.cpp \
        Src/BusinessLogic/Planning/BookingPlanningViewController.cpp \
        Src/BusinessLogic/Planning/PlanningDateListModel.cpp \
        Src/BusinessLogic/Product/PosGroupProductListModel.cpp \
        Src/BusinessLogic/Product/PosProductListModel.cpp \
        Src/BusinessLogic/Product/ProductService.cpp \
        Src/BusinessLogic/Rate/RateGridListModel.cpp \
        Src/BusinessLogic/Rate/RateGridService.cpp \
        Src/BusinessLogic/Room/RoomListModel.cpp \
        Src/BusinessLogic/Room/RoomService.cpp \
        Src/BusinessLogic/Room/RoomTypeListModel.cpp \
        Src/BusinessLogic/Season/SeasonService.cpp \
        Src/BusinessLogic/Segmentation/ClientTypeListModel.cpp \
        Src/BusinessLogic/Segmentation/PrescripteurListModel.cpp \
        Src/BusinessLogic/Segmentation/SegmentationListModel.cpp \
        Src/BusinessLogic/Segmentation/SegmentationService.cpp \
        Src/BusinessLogic/Setting/SettingService.cpp \
        Src/BusinessLogic/Table/TablePlanListModel.cpp \
        Src/BusinessLogic/TopUp/AccompanimentListModel.cpp \
        Src/BusinessLogic/TopUp/CookingListModel.cpp \
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
    Src/Application/Manager/ViewControllerManager.h \
    Src/BusinessLogic/Activities/ActivitiesViewController.h \
    Src/Application/Manager/ApplicationManager.h \
    Src/Application/Base/BaseService.h \
    Src/Application/Base/BaseViewController.h \
    Src/BusinessLogic/Activities/Activity.h \
    Src/BusinessLogic/Activities/ActivityBuilder.h \
    Src/BusinessLogic/Activities/ActivityCache.h \
    Src/BusinessLogic/Activities/ActivityListModel.h \
    Src/BusinessLogic/Activities/ActivityService.h \
    Src/BusinessLogic/Booking/Booking.h \
    Src/BusinessLogic/Booking/BookingBuilder.h \
    Src/BusinessLogic/Booking/BookingDetailViewController.h \
    Src/BusinessLogic/Booking/BookingRoomBuilder.h \
    Src/BusinessLogic/Booking/BookingRoomListModel.h \
    Src/BusinessLogic/Booking/BookingService.h \
    Src/BusinessLogic/CashingMode/CashingMode.h \
    Src/BusinessLogic/CashingMode/CashingModeBuilder.h \
    Src/BusinessLogic/CashingMode/CashingModeCache.h \
    Src/BusinessLogic/CashingMode/CashingModeListModel.h \
    Src/BusinessLogic/CashingMode/CashingModeService.h \
    Src/BusinessLogic/Client/Client.h \
    Src/BusinessLogic/Client/ClientBuilder.h \
    Src/BusinessLogic/Client/ClientCache.h \
    Src/BusinessLogic/Client/ClientListModel.h \
    Src/BusinessLogic/Client/ClientService.h \
    Src/BusinessLogic/Device/CodeConfirmationViewController.h \
    Src/BusinessLogic/Device/Device.h \
    Src/BusinessLogic/Device/DeviceBuilder.h \
    Src/BusinessLogic/Device/DeviceService.h \
    Src/BusinessLogic/Family/Family.h \
    Src/BusinessLogic/Family/FamilyBuilder.h \
    Src/BusinessLogic/Family/FamilyCache.h \
    Src/BusinessLogic/Family/FamilyService.h \
    Src/BusinessLogic/Family/SubFamilyBuilder.h \
    Src/BusinessLogic/Family/SubFamilyCache.h \
    Src/BusinessLogic/Family/SubFamilyModel.h \
    Src/BusinessLogic/Order/Order.h \
    Src/BusinessLogic/Order/OrderBuilder.h \
    Src/BusinessLogic/Order/OrderCache.h \
    Src/BusinessLogic/Order/OrderDetailListModel.h \
    Src/BusinessLogic/Order/OrderListModel.h \
    Src/BusinessLogic/Order/OrderService.h \
    Src/BusinessLogic/Order/OrderViewController.h \
    Src/BusinessLogic/OrderCheckout/OrderCheckout.h \
    Src/BusinessLogic/OrderCheckout/OrderCheckoutCache.h \
    Src/BusinessLogic/OrderCheckout/OrderCheckoutListModel.h \
    Src/BusinessLogic/OrderCheckout/OrderCheckoutViewController.h \
    Src/BusinessLogic/Planning/BookingPlanningViewController.h \
    Src/BusinessLogic/Planning/PlanningDate.h \
    Src/BusinessLogic/Planning/PlanningDateListModel.h \
    Src/BusinessLogic/Product/PosGroupProduct.h \
    Src/BusinessLogic/Product/PosGroupProductBuilder.h \
    Src/BusinessLogic/Product/PosGroupProductCache.h \
    Src/BusinessLogic/Product/PosGroupProductListModel.h \
    Src/BusinessLogic/Product/PosProduct.h \
    Src/BusinessLogic/Product/PosProductBuilder.h \
    Src/BusinessLogic/Product/PosProductCache.h \
    Src/BusinessLogic/Product/PosProductListModel.h \
    Src/BusinessLogic/Product/ProductService.h \
    Src/BusinessLogic/Rate/RateGrid.h \
    Src/BusinessLogic/Rate/RateGridBuilder.h \
    Src/BusinessLogic/Rate/RateGridCache.h \
    Src/BusinessLogic/Rate/RateGridListModel.h \
    Src/BusinessLogic/Rate/RateGridService.h \
    Src/BusinessLogic/Room/Room.h \
    Src/BusinessLogic/Room/RoomBuilder.h \
    Src/BusinessLogic/Room/RoomCache.h \
    Src/BusinessLogic/Room/RoomCategoryBuilder.h \
    Src/BusinessLogic/Room/RoomCategoryCache.h \
    Src/BusinessLogic/Room/RoomCategoryModel.h \
    Src/BusinessLogic/Room/RoomListModel.h \
    Src/BusinessLogic/Room/RoomRepartitionBuilder.h \
    Src/BusinessLogic/Room/RoomService.h \
    Src/BusinessLogic/Room/RoomType.h \
    Src/BusinessLogic/Room/RoomTypeBuilder.h \
    Src/BusinessLogic/Room/RoomTypeCache.h \
    Src/BusinessLogic/Room/RoomTypeListModel.h \
    Src/BusinessLogic/Season/Season.h \
    Src/BusinessLogic/Season/SeasonBuilder.h \
    Src/BusinessLogic/Season/SeasonCache.h \
    Src/BusinessLogic/Season/SeasonService.h \
    Src/BusinessLogic/Season/SubSeason.h \
    Src/BusinessLogic/Season/SubSeasonBuilder.h \
    Src/BusinessLogic/Season/SubSeasonCache.h \
    Src/BusinessLogic/Segmentation/ClientType.h \
    Src/BusinessLogic/Segmentation/ClientTypeBuilder.h \
    Src/BusinessLogic/Segmentation/ClientTypeCache.h \
    Src/BusinessLogic/Segmentation/ClientTypeListModel.h \
    Src/BusinessLogic/Segmentation/Prescripteur.h \
    Src/BusinessLogic/Segmentation/PrescripteurBuilder.h \
    Src/BusinessLogic/Segmentation/PrescripteurCache.h \
    Src/BusinessLogic/Segmentation/PrescripteurListModel.h \
    Src/BusinessLogic/Segmentation/Segmentation.h \
    Src/BusinessLogic/Segmentation/SegmentationBuilder.h \
    Src/BusinessLogic/Segmentation/SegmentationCache.h \
    Src/BusinessLogic/Segmentation/SegmentationListModel.h \
    Src/BusinessLogic/Segmentation/SegmentationService.h \
    Src/BusinessLogic/Setting/Setting.h \
    Src/BusinessLogic/Setting/SettingBuilder.h \
    Src/BusinessLogic/Setting/SettingCache.h \
    Src/BusinessLogic/Setting/SettingService.h \
    Src/BusinessLogic/Table/Table.h \
    Src/BusinessLogic/Table/TablePlanListModel.h \
    Src/BusinessLogic/TopUp/AccompanimentBuilder.h \
    Src/BusinessLogic/TopUp/AccompanimentCache.h \
    Src/BusinessLogic/TopUp/AccompanimentListModel.h \
    Src/BusinessLogic/TopUp/CookingBuilder.h \
    Src/BusinessLogic/TopUp/CookingCache.h \
    Src/BusinessLogic/TopUp/CookingListModel.h \
    Src/BusinessLogic/TopUp/TopUp.h \
    Src/BusinessLogic/TopUp/TopUpService.h \
    Src/BusinessLogic/User/SigninViewController.h \
    Src/BusinessLogic/Signup/SignupViewController.h \
    Src/BusinessLogic/Splash/SplashViewController.h \
    Src/BusinessLogic/User/User.h \
    Src/BusinessLogic/User/UserBuilder.h \
    Src/BusinessLogic/User/UserService.h \
    Src/Application/Util/Constant.h \
    Src/Application/Util/HttpRequest.h \
    Src/Application/Util/HttpUtil.h \
    Src/BusinessLogic/VatService/Vat.h \
    Src/BusinessLogic/VatService/VatBuilder.h \
    Src/BusinessLogic/VatService/VatCache.h \
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
