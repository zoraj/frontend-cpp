#include "RoomService.h"

RoomService::RoomService(const QString &apiKey, const QString &token): BaseService(apiKey, token)
{

}

void RoomService::fetchRoomCategories()
{
    endpoint = constant::WSEndpoint::ROOM_CATEGORIES;
    HttpRequest req {fullPath(constant::WS_ROOM_CATEGORIES),
        "GET",
        nullptr,
        apiKey,
        bearerToken
    };
    executeRequest(req);
}

void RoomService::fetchRoomTypes()
{
    endpoint = constant::WSEndpoint::ROOM_TYPES;
    HttpRequest req {fullPath(constant::WS_ROOM_TYPES),
        "GET",
        nullptr,
        apiKey,
        bearerToken
    };
    executeRequest(req);
}

void RoomService::fetchRooms()
{
    endpoint = constant::WSEndpoint::ROOMS;
    HttpRequest req {fullPath(constant::WS_ROOMS),
        "GET",
        nullptr,
        apiKey,
        bearerToken
    };
    executeRequest(req);
}

void RoomService::fetchAvailabilities(const QDate &start, const QDate &end)
{
    endpoint = constant::WSEndpoint::ROOM_AVAILABILITIES;
    QString url = constant::WS_ROOM_AVAILABILITIES.arg(start.toString("yyyy-MM-dd"), end.toString("yyyy-MM-dd"));
    HttpRequest req {fullPath(url),
        "GET",
        nullptr,
        apiKey,
        bearerToken
    };
    executeRequest(req);
}

// Main callback methods
void RoomService::callback(constant::WSEndpoint endpoint, const QByteArray &response, int status)
{
    switch (endpoint) {
        case constant::WSEndpoint::ROOM_CATEGORIES:
            emit fetchRoomCategoriesFinished(response, status);
            break;
        case constant::WSEndpoint::ROOM_TYPES:
            emit fetchRoomTypesFinished(response, status);
            break;
        case constant::WSEndpoint::ROOMS:
            emit fetchRoomsFinished(response, status);
            break;
        case constant::WSEndpoint::ROOM_AVAILABILITIES:
            emit fetchAvailabilitiesFinished(response, status);
            break;
    }
}
