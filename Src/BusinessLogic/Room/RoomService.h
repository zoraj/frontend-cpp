#pragma once

#include "Src/Application/Base/BaseService.h"

class RoomService : public BaseService
{
    Q_OBJECT
public:
    RoomService(const QString &apiKey, const QString &token);

    void fetchRoomCategories();
    void fetchRoomTypes();
    void fetchRooms();
    void fetchAvailabilities(const QDate &start, const QDate &end);

    void callback(Constant::WSEndpoint endpoint, const QByteArray& response, int status) override;
signals:
    void fetchRoomCategoriesFinished(const QByteArray &, int);
    void fetchRoomTypesFinished(const QByteArray &, int);
    void fetchRoomsFinished(const QByteArray &, int);
    void fetchAvailabilitiesFinished(const QByteArray &response, int status);
};
