/*!
 *  @file ApplicationManager.h
 *  @brief This header file will be useful for the doxygen.
 *
 *  @author Zo Rajaonarivony <zo@multimicro.fr>
 *  @date
 */

#pragma once

#include <QString>

namespace Constant {
#ifdef QT_DEBUG
    static const QString WS_ROOT_URL = QStringLiteral("http://develop.local/api");
    static const QString WS_E_URL = QStringLiteral("http://develop.local/e/api"); // e for Establishment
#else
    static const QString WS_ROOT_URL = QStringLiteral("https://bymmc.com/api");
    static const QString WS_E_URL = QStringLiteral("https://bymmc.com/e/api"); // e for Establishment
#endif
    static const QString DB_CACHE = QStringLiteral("mmc.prod.db3");

    // WS PATH
    // Users
    static const QString WS_USERS = QStringLiteral("/users");
    // Setting
    static const QString WS_SETTING = QStringLiteral("/settings");
    // Authentication
    static const QString WS_LOGIN = QStringLiteral("/users/signin");

    // Booking
    static const QString WS_BOOKING = QStringLiteral("/reservation");
    static const QString WS_BOOKING_ROOM_REPARTITION = QStringLiteral("/reservation/ventillation/%1");

    // Stay
    static const QString WS_STAY = QStringLiteral("/stay");

    // Seasons
    static const QString WS_SEASONS = QStringLiteral("/seasons");
    static const QString WS_SUB_SEASONS = QStringLiteral("/sub-season");

    // Rates
    // Grid
    static const QString WS_RATE_GRID = QStringLiteral("/rate-grid/?season=1&sub-season=1");

    // Clients
    static const QString WS_CLIENTS = QStringLiteral("/clients");

    // Segmentations
    // Client type
    static const QString WS_CLIENT_TYPES = QStringLiteral("/clients/type-client");
    // Segmentation
    static const QString WS_SEGMENTATION = QStringLiteral("/clients/segment-client");
    // Prescripteur
    static const QString WS_PRESCRIPTEUR = QStringLiteral("/clients/prescripteur");

    // Rooms
    // Room categories
    static const QString WS_ROOM_CATEGORIES = QStringLiteral("/rooms/categories");
    // Room types
    static const QString WS_ROOM_TYPES = QStringLiteral("/rooms/type");
    // Rooms
    static const QString WS_ROOMS = QStringLiteral("/rooms");
    // Rooms availability
    static const QString WS_ROOM_AVAILABILITIES = QStringLiteral("/rooms/availabilities?dateStart=%1&dateEnd=%2");

    // Products
    static const QString WS_POS_GROUP_PRODUCTS = QStringLiteral("/products/groups");
    static const QString WS_POS_PRODUCTS = QStringLiteral("/products/pos");

    // Families
    static const QString WS_FAMILIES = QStringLiteral("/families");
    static const QString WS_SUB_FAMILIES = QStringLiteral("/families/sub-families");

    // Vat & Service
    static const QString WS_VAT = QStringLiteral("/vat");

    // Orders
    static const QString WS_POS_ORDERS = QStringLiteral("/notes/pos/header");
    static const QString WS_POS_ORDER_DETAILS = QStringLiteral("/notes/pos/details");
    static const QString WS_POST_ORDER_CHECKOUT = QStringLiteral("/cashing/pos");

    // Activities
    static const QString WS_ACTIVITIES = QStringLiteral("/sections/activities");

    // Cashing mode
    static const QString WS_CASHING_MODE = QStringLiteral("/cashing/mode");

    // Top UP
    static const QString WS_CUISSON = QStringLiteral("/products/cuisson");
    static const QString WS_GARNITURE = QStringLiteral("/products/accompagnement");

    // Device
    static const QString WS_CODE_DEVICE_CONFIRMATION = QStringLiteral("/devices/activate?activation-code=%1");

    enum WSEndpoint {
        USERS = 0,
        SETTING,
        LOGIN,
        BOOKING_POST,
        BOOKING_PUT,
        BOOKING_ROOM_REPARTITION_GET,
        STAY,
        SEASONS,
        SUB_SEASONS,
        RATE_GRID,
        CLIENTS,
        CLIENT_TYPES,
        SEGMENTATION,
        PRESCRIPTEUR,
        ROOM_CATEGORIES,
        ROOM_TYPES,
        ROOMS,
        ROOM_AVAILABILITIES,
        POS_GROUP_PRODUCTS,
        POS_PRODUCTS,
        FAMILIES,
        SUB_FAMILIES,
        VAT,
        ORDER_GET,
        ORDER_POST,
        ORDER_DETAIL_POST,
        ORDER_CHECKOUT_POST,
        ACTIVITIES,
        CASHING_MODE,
        CUISSON,
        GARNITURE,
        CODE_DEVICE_CONFIRMATION,
        UNKNOWN,
    };


    enum HttpStatusCode {
        OK = 200,
        Created  = 201,
        BadRequest = 400,
        Unauthorized = 401,
        NotFound = 404,
        InternalServerError = 501,
        HostNotFound = 503,
        UnknownError,
    };

    enum Module {
        Unknown =  -1,
        POS_TRADITIONAL = 0,
        RECEP = 1,
        RESA = 2,
        HOUSEKEEPING = 3,
        POS_COLLECTIVITE = 4
    };

    static const int UNDEFINED_INT = -1;

    static const int SYNC_CLOUD_INTERVAL = 8000; // 2 secs
}
