#pragma once

#include "Src/Application/Base/BaseViewController.h"
#include "Src/BusinessLogic/User/UserService.h"
#include "Src/BusinessLogic/User/UserBuilder.h"
#include "Src/BusinessLogic/Setting/SettingService.h"
#include "Src/BusinessLogic/Setting/SettingBuilder.h"
#include "Src/BusinessLogic/VatService/VatServiceService.h"
#include "Src/BusinessLogic/VatService/VatBuilder.h"
#include "Src/BusinessLogic/VatService/VatCache.h"
#include "Src/BusinessLogic/Family/FamilyService.h"
#include "Src/BusinessLogic/Family/FamilyBuilder.h"
#include "Src/BusinessLogic/Family/FamilyCache.h"
#include "Src/BusinessLogic/Family/SubFamilyBuilder.h"
#include "Src/BusinessLogic/Family/SubFamilyCache.h"
#include "Src/BusinessLogic/CashingMode/CashingModeService.h"
#include "Src/BusinessLogic/CashingMode/CashingModeBuilder.h"
#include "Src/BusinessLogic/CashingMode/CashingModeCache.h"
#include "Src/BusinessLogic/Segmentation/SegmentationService.h"
#include "Src/BusinessLogic/Segmentation/ClientTypeBuilder.h"
#include "Src/BusinessLogic/Segmentation/ClientTypeCache.h"
#include "Src/BusinessLogic/Segmentation/SegmentationBuilder.h"
#include "Src/BusinessLogic/Segmentation/SegmentationCache.h"
#include "Src/BusinessLogic/Segmentation/PrescripteurBuilder.h"
#include "Src/BusinessLogic/Segmentation/PrescripteurCache.h"
#include "Src/BusinessLogic/Client/ClientBuilder.h"
#include "Src/BusinessLogic/Client/ClientCache.h"
#include "Src/BusinessLogic/Client/ClientService.h"
#include "Src/BusinessLogic/Season/SeasonService.h"
#include "Src/BusinessLogic/Season/SeasonCache.h"
#include "Src/BusinessLogic/Season/SeasonBuilder.h"
#include "Src/BusinessLogic/Season/SubSeasonBuilder.h"
#include "Src/BusinessLogic/Season/SubSeasonCache.h"
#include "Src/BusinessLogic/Activities/ActivityBuilder.h"
#include "Src/BusinessLogic/Activities/ActivityCache.h"
#include "Src/BusinessLogic/Activities/ActivityService.h"
#include "Src/BusinessLogic/Product/ProductService.h"
#include "Src/BusinessLogic/Product/PosGroupProductBuilder.h"
#include "Src/BusinessLogic/Product/PosGroupProductCache.h"
#include "Src/BusinessLogic/Product/PosProductBuilder.h"
#include "Src/BusinessLogic/Product/PosProductCache.h"
#include "Src/BusinessLogic/TopUp/TopUpService.h"
#include "Src/BusinessLogic/TopUp/CookingBuilder.h"
#include "Src/BusinessLogic/TopUp/CookingCache.h"
#include "Src/BusinessLogic/TopUp/AccompanimentBuilder.h"
#include "Src/BusinessLogic/TopUp/AccompanimentCache.h"
#include "Src/BusinessLogic/Room/RoomService.h"
#include "Src/BusinessLogic/Room/RoomCategoryBuilder.h"
#include "Src/BusinessLogic/Room/RoomCategoryCache.h"
#include "Src/BusinessLogic/Room/RoomTypeBuilder.h"
#include "Src/BusinessLogic/Room/RoomTypeCache.h"
#include "Src/BusinessLogic/Room/RoomBuilder.h"
#include "Src/BusinessLogic/Room/RoomCache.h"

class SigninViewController : public BaseViewController
{
    Q_OBJECT
    void fetchRemoteDataThenCache(Constant::Module module);
public:
    SigninViewController(QObject *parent = nullptr);
signals:
    void validatePinCodeTriggeredFinished(bool result, int module);
public slots:
    void validatePinCodeTriggered(const QString& pinCode);
};
