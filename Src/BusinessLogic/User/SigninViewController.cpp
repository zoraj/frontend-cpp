#include "SigninViewController.h"


void SigninViewController::fetchRemoteDataThenCache(Constant::Module module)
{
    // Fetch settings then cache to local database
    auto settingService = new SettingService(APP_CONTEXT_API_KEY, APP_CONTEXT_TOKEN);
    settingService->fetchSettings();
    QObject::connect(settingService, &SettingService::fetchSettingsFinished, [=] (const QByteArray &response, int status){
        if (status == Constant::HttpStatusCode::OK) {
            auto settings = Builder::Setting::create(response);
            // Cache data
            Cache::Setting::persist(settings, false);
        }
        settingService->deleteLater();
    });
    // Fetch settings then cache to local database
    auto vatServiceService = new VatServiceService(APP_CONTEXT_API_KEY, APP_CONTEXT_TOKEN);
    vatServiceService->fetchVat();
    QObject::connect(vatServiceService, &VatServiceService::fetchVatFinished, [=] (const QByteArray &response, int status){
        if (status == Constant::HttpStatusCode::OK) {
            auto vats = Builder::Vat::create(response);
            // Cache data
            Cache::Vat::persist(vats);
        }
        vatServiceService->deleteLater();
    });
    // Fetch families then cache to local database
    auto familyService = new FamilyService(APP_CONTEXT_API_KEY, APP_CONTEXT_TOKEN);
    familyService->fetchFamilies();
    QObject::connect(familyService, &FamilyService::fetchFamiliesFinished, [=] (const QByteArray &response, int status){
        if (status == Constant::HttpStatusCode::OK) {
            auto families = Builder::Family::create(response);
            // Cache data
            Cache::Family::persist(families);
        }
        familyService->deleteLater();
    });
    // Fetch Subfamilies then cache to local database
    auto subFamilyService = new FamilyService(APP_CONTEXT_API_KEY, APP_CONTEXT_TOKEN);
    subFamilyService->fetchSubFamilies();
    QObject::connect(subFamilyService, &FamilyService::fetchSubFamiliesFinished, [=] (const QByteArray &response, int status){
        if (status == Constant::HttpStatusCode::OK) {
            auto subFamilies = Builder::SubFamily::create(response);
            // Cache data
            Cache::SubFamily::persist(subFamilies);
        }
        subFamilyService->deleteLater();
    });
    // Fetch Cashing Mode then cache to local database
    auto cashingModeService = new CashingModeService(APP_CONTEXT_API_KEY, APP_CONTEXT_TOKEN);
    cashingModeService->fetchCashingMode();
    QObject::connect(cashingModeService, &CashingModeService::fetchCashingModeFinished, [=] (const QByteArray &response, int status) {
        if (status == Constant::HttpStatusCode::OK) {
            auto cashingModes = Builder::CashingMode::create(response);
            // Cache data
            Cache::CashingMode::persist(cashingModes);
        }
    });
    // Fetch segmentation then cache to local database
    // Client type
    auto segmentationClientTypeService = new SegmentationService(APP_CONTEXT_API_KEY, APP_CONTEXT_TOKEN);
    segmentationClientTypeService->fetchClientTypes();
    QObject::connect(segmentationClientTypeService, &SegmentationService::fetchClientTypesFinished, [=] (const QByteArray &response, int status) {
        if (status == Constant::HttpStatusCode::OK) {
            auto clientTypes = Builder::ClientType::create(response);
            // Cache data
            Cache::ClientType::persist(clientTypes);
        }
        segmentationClientTypeService->deleteLater();
    });
    // Segmentation
    auto segmentationSegService = new SegmentationService(APP_CONTEXT_API_KEY, APP_CONTEXT_TOKEN);
    segmentationSegService->fetchSegmentations();
    QObject::connect(segmentationSegService, &SegmentationService::fetchSegmentationsFinished, [=] (const QByteArray &response, int status) {
        if (status == Constant::HttpStatusCode::OK) {
            auto segmentations = Builder::Segmentation::create(response);
            // Cache data
            Cache::Segmentation::persist(segmentations);
        }
        segmentationSegService->deleteLater();
    });
    // Prescripteur
    auto segmentationPrescripteurService = new SegmentationService(APP_CONTEXT_API_KEY, APP_CONTEXT_TOKEN);
    segmentationPrescripteurService->fetchPrescripteurs();
    QObject::connect(segmentationPrescripteurService, &SegmentationService::fetchPrescripteursFinished, [=] (const QByteArray &response, int status) {
        if (status == Constant::HttpStatusCode::OK) {
            auto prescripteurs = Builder::Prescripteur::create(response);
            Cache::Prescripteur::persist(prescripteurs);
        }
        segmentationPrescripteurService->deleteLater();
    });
    // Fetch client accounts then cache it to local database
    auto clientService = new ClientService(APP_CONTEXT_API_KEY, APP_CONTEXT_TOKEN);
    clientService->fetchClients();
    QObject::connect(clientService, &ClientService::fetchClientsFinished, [=] (const QByteArray &response, int status) {
       if (status == Constant::HttpStatusCode::OK) {
           auto clients = Builder::Client::create(response);
           // Cache data
           Cache::Client::persist(clients);
       }
       clientService->deleteLater();
    });
    // Fetch seasons then cache to local database
    auto seasonService = new SeasonService(APP_CONTEXT_API_KEY, APP_CONTEXT_TOKEN);
    seasonService->fetchSeasons();
    QObject::connect(seasonService, &SeasonService::fetchSeasonsFinished, [=] (const QByteArray &response, int status){
        if (status == Constant::HttpStatusCode::OK) {
            auto seasons = SeasonBuilder::create(response);
            // Cache data
            SeasonCache::persist(seasons);
        }
        seasonService->deleteLater();
    });
    // Fetch sub-seasons then cache to local database
    auto subSeasonService = new SeasonService(APP_CONTEXT_API_KEY, APP_CONTEXT_TOKEN);
    subSeasonService->fetchSubSeasons();
    QObject::connect(subSeasonService, &SeasonService::fetchSubSeasonsFinished, [=] (const QByteArray &response, int status) {
        if (status == Constant::HttpStatusCode::OK) {
            auto subSeasons = Builder::SubSeason::create(response);
            // Cache data
            Cache::SubSeason::persist(subSeasons);
        }
        subSeasonService->deleteLater();
    });
    // Fetch Activities then cache to local database
    auto activitiesService = new ActivityService(APP_CONTEXT_API_KEY, APP_CONTEXT_TOKEN);
    activitiesService->fetchActivities();
    QObject::connect(activitiesService, &ActivityService::fetchActivitiesFinished, [=] (const QByteArray &response, int status){
        if (status == Constant::HttpStatusCode::OK) {
            auto activities = Builder::Activity::create(response);
            // Cache data
            Cache::Activity::persist(activities);
        }
    });
    // Fetch pos group product then cache
    auto posGroupProductService = new ProductService(APP_CONTEXT_API_KEY, APP_CONTEXT_TOKEN);
    posGroupProductService->fetchPosGroupProducts();
    QObject::connect(posGroupProductService, &ProductService::fetchPosGroupProductsFinished, [=] (const QByteArray &response, int status){
        if (status == Constant::HttpStatusCode::OK) {
            auto groupProducts = Builder::PosGroupProduct::create(response);
            // Cache data
            Cache::PosGroupProduct::persist(groupProducts);
        }
        posGroupProductService->deleteLater();
    });
    // Fetch pos products then cache
    auto posProductService = new ProductService(APP_CONTEXT_API_KEY, APP_CONTEXT_TOKEN);
    posProductService->fetchPosProducts();
    QObject::connect(posProductService, &ProductService::fetchPosProductsFinished, [=] (const QByteArray &response, int status) {
        if (status == Constant::HttpStatusCode::OK) {
            auto posProducts = Builder::PosProduct::create(response);
            // Cache data
            Cache::PosProduct::persist(posProducts);
        }
        posProductService->deleteLater();
    });
    // Fetch topup then cache
    // Cooking style
    auto cuissonService = new TopUpService(APP_CONTEXT_API_KEY, APP_CONTEXT_TOKEN);
    cuissonService->fetchCuissons();
    QObject::connect(cuissonService, &TopUpService::fetchCuissonsFinished, [=] (const QByteArray &response, int status){
        if (status == Constant::HttpStatusCode::OK) {
            auto cuissons = Builder::Cooking::create(response);
            // Cache data
            Cache::Cooking::persist(cuissons);
        }
        cuissonService->deleteLater();
    });
    // Accompaniment
    auto accompanimentService = new TopUpService(APP_CONTEXT_API_KEY, APP_CONTEXT_TOKEN);
    accompanimentService->fetchGarnitures();
    QObject::connect(accompanimentService, &TopUpService::fetchGarnituresFinished, [=] (const QByteArray &response, int status){
        if (status == Constant::HttpStatusCode::OK) {
            auto garnitures = Builder::Accompaniment::create(response);
            // Cache data
            Cache::Accompaniment::persist(garnitures);
        }
        accompanimentService->deleteLater();
    });
    // Fetch room categories then cache
    auto roomCategoryService = new RoomService(APP_CONTEXT_API_KEY, APP_CONTEXT_TOKEN);
    roomCategoryService->fetchRoomCategories();
    QObject::connect(roomCategoryService, &RoomService::fetchRoomCategoriesFinished, [=] (const QByteArray &response, int status){
       if (status == Constant::HttpStatusCode::OK) {
           auto roomCategories = Builder::RoomCategory::create(response);
           // Cache data
           Cache::RoomCategory::persist(roomCategories);
       }
       roomCategoryService->deleteLater();
    });

    // Fetch room types then cache
    auto roomTypeService = new RoomService(APP_CONTEXT_API_KEY, APP_CONTEXT_TOKEN);
    roomTypeService->fetchRoomTypes();
    QObject::connect(roomTypeService, &RoomService::fetchRoomTypesFinished, [=] (const QByteArray &response, int status) {
        if (status == Constant::HttpStatusCode::OK) {
            auto roomTypes = Builder::RoomType::create(response);
            // Cache data
            Cache::RoomType::persist(roomTypes);
        }
        roomTypeService->deleteLater();
    });
    // Fetch rooms then cache
    auto roomService = new RoomService(APP_CONTEXT_API_KEY, APP_CONTEXT_TOKEN);
    roomService->fetchRooms();
    QObject::connect(roomService, &RoomService::fetchRoomsFinished, [=] (const QByteArray &response, int status){
        if (status == Constant::HttpStatusCode::OK) {
            auto rooms = Builder::Room::create(response);
            // Cache data
            Cache::Room::persist(rooms);
        }
        roomService->deleteLater();
    });

}

void SigninViewController::registerControllers(Constant::Module module)
{
    auto activitiesViewController = new ActivitiesViewController();
    ApplicationManager::getInstance()->getAppContext()->uiContext->setContextProperty("_activitiesViewController",activitiesViewController);
}

SigninViewController::SigninViewController(QObject *parent) : BaseViewController(parent)
{

}

void SigninViewController::validatePinCodeTriggered(const QString& pinCode)
{
    QString apiKey = ApplicationManager::getInstance()->getAppContext()->apiKey;
    auto userService = new UserService(apiKey, nullptr);
    userService->postUserCredentials(pinCode);
    QObject::connect(userService, &UserService::postUserCredentialsFinished, [=] (const QByteArray &response, const int status){
        if (status == Constant::HttpStatusCode::OK) {
            UserModel *user = Builder::User::create(response);
            user->setParent(this);

            // This is the only place where we register our user
            ApplicationManager::getInstance()->getAppContext()->user = user;
            /*
            // User wants to automatically sign in next time ?
            if (this->isSessionStored) {
                SettingModel setting;
                setting.cle = "SESSION_LOGIN";
                setting.valeur = user->login;
                SettingCache::persist(setting);

                setting.cle = "SESSION_PWD";
                setting.valeur = password;
                SettingCache::persist(setting);
            }*/

            // The minimum condition for us to retrieve data from the remote server is having APIKEY & Session Token (JWT)
            // If pin code is correct, we will get our session token
            // Let's retrieve data
            const int moduleId = 2;// POS = 0; RECEP = 1, RESA = 2, HOUSEKEEPING = 3, COLLECTIVITE = 4
            auto module = static_cast<Constant::Module>(moduleId);
            fetchRemoteDataThenCache(module);
            registerControllers(module);

        }
        emit validatePinCodeTriggeredFinished(status == Constant::HttpStatusCode::OK, 0);
    });
}
