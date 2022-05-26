#include "SigninViewController.h"


void SigninViewController::fetchRemoteDataThenCache(constant::Module module)
{
    // Fetch settings then cache to local database
    auto settingService = new SettingService(APP_CONTEXT_API_KEY, APP_CONTEXT_TOKEN);
    settingService->fetchSettings();
    QObject::connect(settingService, &SettingService::fetchSettingsFinished, [=] (const QByteArray &response, int status){
        if (status == constant::HttpStatusCode::OK) {
            auto settings = builder::setting::create(response);
            // Cache data
            cache::setting::persist(settings, false);
        }
        settingService->deleteLater();
    });
    // Fetch VAT & Service then cache to local database
    auto vatServiceService = new VatServiceService(APP_CONTEXT_API_KEY, APP_CONTEXT_TOKEN);
    vatServiceService->fetchVat();
    QObject::connect(vatServiceService, &VatServiceService::fetchVatFinished, [=] (const QByteArray &response, int status){
        if (status == constant::HttpStatusCode::OK) {
            auto vats = builder::vat::create(response);
            // Cache data
            cache::vat::persist(vats);
        }
        vatServiceService->deleteLater();
    });
    // Fetch families then cache to local database
    auto familyService = new FamilyService(APP_CONTEXT_API_KEY, APP_CONTEXT_TOKEN);
    familyService->fetchFamilies();
    QObject::connect(familyService, &FamilyService::fetchFamiliesFinished, [=] (const QByteArray &response, int status){
        if (status == constant::HttpStatusCode::OK) {
            auto families = builder::family::create(response);
            // Cache data
            cache::family::persist(families);
        }
        familyService->deleteLater();
    });
    // Fetch Subfamilies then cache to local database
    auto subFamilyService = new FamilyService(APP_CONTEXT_API_KEY, APP_CONTEXT_TOKEN);
    subFamilyService->fetchSubFamilies();
    QObject::connect(subFamilyService, &FamilyService::fetchSubFamiliesFinished, [=] (const QByteArray &response, int status){
        if (status == constant::HttpStatusCode::OK) {
            auto subFamilies = builder::sub_family::create(response);
            // Cache data
            cache::sub_family::persist(subFamilies);
        }
        subFamilyService->deleteLater();
    });
    // Fetch Cashing Mode then cache to local database
    auto cashingModeService = new CashingModeService(APP_CONTEXT_API_KEY, APP_CONTEXT_TOKEN);
    cashingModeService->fetchCashingMode();
    QObject::connect(cashingModeService, &CashingModeService::fetchCashingModeFinished, [=] (const QByteArray &response, int status) {
        if (status == constant::HttpStatusCode::OK) {
            auto cashingModes = builder::cashing_mode::create(response);
            // Cache data
            cache::cashing_mode::persist(cashingModes);
        }
    });
    // Fetch segmentation then cache to local database
    // Client type
    auto segmentationClientTypeService = new SegmentationService(APP_CONTEXT_API_KEY, APP_CONTEXT_TOKEN);
    segmentationClientTypeService->fetchClientTypes();
    QObject::connect(segmentationClientTypeService, &SegmentationService::fetchClientTypesFinished, [=] (const QByteArray &response, int status) {
        if (status == constant::HttpStatusCode::OK) {
            auto clientTypes = builder::client_type::create(response);
            // Cache data
            cache::client_type::persist(clientTypes);
        }
        segmentationClientTypeService->deleteLater();
    });
    // Segmentation
    auto segmentationSegService = new SegmentationService(APP_CONTEXT_API_KEY, APP_CONTEXT_TOKEN);
    segmentationSegService->fetchSegmentations();
    QObject::connect(segmentationSegService, &SegmentationService::fetchSegmentationsFinished, [=] (const QByteArray &response, int status) {
        if (status == constant::HttpStatusCode::OK) {
            auto segmentations = builder::segmentation::create(response);
            // Cache data
            cache::segmentation::persist(segmentations);
        }
        segmentationSegService->deleteLater();
    });
    // Prescripteur
    auto segmentationPrescripteurService = new SegmentationService(APP_CONTEXT_API_KEY, APP_CONTEXT_TOKEN);
    segmentationPrescripteurService->fetchPrescripteurs();
    QObject::connect(segmentationPrescripteurService, &SegmentationService::fetchPrescripteursFinished, [=] (const QByteArray &response, int status) {
        if (status == constant::HttpStatusCode::OK) {
            auto prescripteurs = builder::prescripteur::create(response);
            cache::prescripteur::persist(prescripteurs);
        }
        segmentationPrescripteurService->deleteLater();
    });
    // Fetch client accounts then cache it to local database
    auto clientService = new ClientService(APP_CONTEXT_API_KEY, APP_CONTEXT_TOKEN);
    clientService->fetchClients();
    QObject::connect(clientService, &ClientService::fetchClientsFinished, [=] (const QByteArray &response, int status) {
       if (status == constant::HttpStatusCode::OK) {
           auto clients = builder::client::create(response);
           // Cache data
           cache::client::persist(clients);
       }
       clientService->deleteLater();
    });
    // Fetch seasons then cache to local database
    auto seasonService = new SeasonService(APP_CONTEXT_API_KEY, APP_CONTEXT_TOKEN);
    seasonService->fetchSeasons();
    QObject::connect(seasonService, &SeasonService::fetchSeasonsFinished, [=] (const QByteArray &response, int status){
        if (status == constant::HttpStatusCode::OK) {
            auto seasons = builder::season::create(response);
            // Cache data
            cache::season::persist(seasons);
        }
        seasonService->deleteLater();
    });
    // Fetch sub-seasons then cache to local database
    auto subSeasonService = new SeasonService(APP_CONTEXT_API_KEY, APP_CONTEXT_TOKEN);
    subSeasonService->fetchSubSeasons();
    QObject::connect(subSeasonService, &SeasonService::fetchSubSeasonsFinished, [=] (const QByteArray &response, int status) {
        if (status == constant::HttpStatusCode::OK) {
            auto subSeasons = builder::sub_season::create(response);
            // Cache data
            cache::sub_season::persist(subSeasons);
        }
        subSeasonService->deleteLater();
    });

    // Fetch rate grids then cache to local database
    auto rateGridService = new RateGridService(APP_CONTEXT_API_KEY, APP_CONTEXT_TOKEN);
    rateGridService->fetchRateGrids();
    QObject::connect(rateGridService, &RateGridService::fetchRateGridsFinished, [=] (const QByteArray &response, int status) {
        if (status == constant::HttpStatusCode::OK) {
            auto rateGrids = builder::rate_grid::create(response);
            // Cache data
            cache::rate_grid::persist(rateGrids);
        }
        rateGridService->deleteLater();
    });

    // Fetch Activities then cache to local database
    auto activitiesService = new ActivityService(APP_CONTEXT_API_KEY, APP_CONTEXT_TOKEN);
    activitiesService->fetchActivities();
    QObject::connect(activitiesService, &ActivityService::fetchActivitiesFinished, [=] (const QByteArray &response, int status){
        if (status == constant::HttpStatusCode::OK) {
            auto activities = builder::activity::create(response);
            // Cache data
            cache::activity::persist(activities);
        }
        activitiesService->deleteLater();
    });
    // Fetch pos group product then cache
    auto posGroupProductService = new ProductService(APP_CONTEXT_API_KEY, APP_CONTEXT_TOKEN);
    posGroupProductService->fetchPosGroupProducts();
    QObject::connect(posGroupProductService, &ProductService::fetchPosGroupProductsFinished, [=] (const QByteArray &response, int status){
        if (status == constant::HttpStatusCode::OK) {
            auto groupProducts = builder::pos_group_product::create(response);
            // Cache data
            cache::pos_group_product::persist(groupProducts);
        }
        posGroupProductService->deleteLater();
    });
    // Fetch pos products then cache
    auto posProductService = new ProductService(APP_CONTEXT_API_KEY, APP_CONTEXT_TOKEN);
    posProductService->fetchPosProducts();
    QObject::connect(posProductService, &ProductService::fetchPosProductsFinished, [=] (const QByteArray &response, int status) {
        if (status == constant::HttpStatusCode::OK) {
            auto posProducts = builder::pos_product::create(response);
            // Cache data
            cache::pos_product::persist(posProducts);
        }
        posProductService->deleteLater();
    });
    // Fetch topup then cache
    // Cooking style
    auto cuissonService = new TopUpService(APP_CONTEXT_API_KEY, APP_CONTEXT_TOKEN);
    cuissonService->fetchCuissons();
    QObject::connect(cuissonService, &TopUpService::fetchCuissonsFinished, [=] (const QByteArray &response, int status){
        if (status == constant::HttpStatusCode::OK) {
            auto cuissons = builder::cooking::create(response);
            // Cache data
            cache::cooking::persist(cuissons);
        }
        cuissonService->deleteLater();
    });
    // Accompaniment
    auto accompanimentService = new TopUpService(APP_CONTEXT_API_KEY, APP_CONTEXT_TOKEN);
    accompanimentService->fetchGarnitures();
    QObject::connect(accompanimentService, &TopUpService::fetchGarnituresFinished, [=] (const QByteArray &response, int status){
        if (status == constant::HttpStatusCode::OK) {
            auto garnitures = builder::accompaniment::create(response);
            // Cache data
            cache::accompaniment::persist(garnitures);
        }
        accompanimentService->deleteLater();
    });
    // Fetch room categories then cache
    auto roomCategoryService = new RoomService(APP_CONTEXT_API_KEY, APP_CONTEXT_TOKEN);
    roomCategoryService->fetchRoomCategories();
    QObject::connect(roomCategoryService, &RoomService::fetchRoomCategoriesFinished, [=] (const QByteArray &response, int status){
       if (status == constant::HttpStatusCode::OK) {
           auto roomCategories = builder::room_category::create(response);
           // Cache data
           cache::room_category::persist(roomCategories);
       }
       roomCategoryService->deleteLater();
    });

    // Fetch room types then cache
    auto roomTypeService = new RoomService(APP_CONTEXT_API_KEY, APP_CONTEXT_TOKEN);
    roomTypeService->fetchRoomTypes();
    QObject::connect(roomTypeService, &RoomService::fetchRoomTypesFinished, [=] (const QByteArray &response, int status) {
        if (status == constant::HttpStatusCode::OK) {
            auto roomTypes = builder::room_type::create(response);
            // Cache data
            cache::room_type::persist(roomTypes);
        }
        roomTypeService->deleteLater();
    });
    // Fetch rooms then cache
    auto roomService = new RoomService(APP_CONTEXT_API_KEY, APP_CONTEXT_TOKEN);
    roomService->fetchRooms();
    QObject::connect(roomService, &RoomService::fetchRoomsFinished, [=] (const QByteArray &response, int status){
        if (status == constant::HttpStatusCode::OK) {
            auto rooms = builder::room::create(response);
            // Cache data
            cache::room::persist(rooms);
        }
        roomService->deleteLater();
    });

}

void SigninViewController::registerControllers(constant::Module module)
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
        if (status == constant::HttpStatusCode::OK) {
            User *user = builder::user::create(response);
            user->setParent(this);

            // This is the only place where we register our user
            ApplicationManager::getInstance()->getAppContext()->user = user;
            /*
            // User wants to automatically sign in next time ?
            if (this->isSessionStored) {
                SettingModel setting;
                setting.cle = "SESSION_LOGIN";
                setting.valeur = user->login;
                Settingcache::persist(setting);

                setting.cle = "SESSION_PWD";
                setting.valeur = password;
                Settingcache::persist(setting);
            }*/

            // The minimum condition for us to retrieve data from the remote server is having APIKEY & Session Token (JWT)
            // If pin code is correct, we will get our session token
            // Let's retrieve data
            const int moduleId = 2;// POS = 0; RECEP = 1, RESA = 2, HOUSEKEEPING = 3, COLLECTIVITE = 4
            auto module = static_cast<constant::Module>(moduleId);
            fetchRemoteDataThenCache(module);
            registerControllers(module);

        }
        emit validatePinCodeTriggeredFinished(status == constant::HttpStatusCode::OK, 0);
    });
}
