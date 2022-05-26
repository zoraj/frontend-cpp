#include "BookingService.h"


// Public methods
BookingService::BookingService(const QString &apiKey, const QString &token): BaseService(apiKey, token)
{

}

void BookingService::fetchBookings()
{
    endpoint = constant::WSEndpoint::BOOKING_GET;
    HttpRequest req {
        fullPath(constant::WS_BOOKING_LIST),
        "GET",
        nullptr,
        apiKey,
        bearerToken
    };
    executeRequest(req);
}

void BookingService::postBookingHeader(const Booking &booking)
{
    endpoint = constant::WSEndpoint::BOOKING_POST;
    QJsonObject payload = builder::booking::serialize(booking);
    HttpRequest req {fullPath(constant::WS_BOOKING),
        "POST",
        &payload,
        apiKey,
        bearerToken
    };
    executeRequest(req);
}

void BookingService::updateBooking(const Booking &booking)
{
    endpoint = constant::WSEndpoint::BOOKING_PATCH;
    QJsonObject payload = builder::booking::serialize(booking);
    HttpRequest req {fullPath(constant::WS_BOOKING),
        "PATCH",
        &payload,
        apiKey,
        bearerToken
    };
    executeRequest(req);
}

void BookingService::fetchRoomRepartitions()
{
    endpoint = constant::WSEndpoint::BOOKING_ROOM_REPARTITIONS_GET;
    //HttpRequest req {fullPath(constant::WS_BOOKING_ROOM_REPARTITIONS.arg(bookingId)),
    HttpRequest req {fullPath(constant::WS_BOOKING_ROOM_REPARTITIONS),
        "GET",
        nullptr,
        apiKey,
        bearerToken
    };
    executeRequest(req);
}

void BookingService::fetchRoomRepartition(int bookingId)
{
    endpoint = constant::WSEndpoint::BOOKING_ROOM_REPARTITION_GET;
    HttpRequest req {fullPath(constant::WS_BOOKING_ROOM_REPARTITIONS.arg(bookingId)),
        "GET",
        nullptr,
        apiKey,
        bearerToken
    };
    executeRequest(req);
}

void BookingService::postRoomRepartitions(const Booking &booking)
{
    endpoint = constant::WSEndpoint::BOOKING_ROOM_REPARTITIONS_POST;
    QJsonObject payload = builder::booking::serializeRoomRepartitions(booking);
    HttpRequest req {fullPath(constant::WS_BOOKING_ROOM_REPARTITIONS),
        "POST",
        &payload,
        apiKey,
        bearerToken
    };
    executeRequest(req);
}


void BookingService::callback(constant::WSEndpoint endpoint, const QByteArray &response, int status)
{
    switch (endpoint) {
    case constant::WSEndpoint::BOOKING_GET:
        emit fetchBookingsFinished(response, status);
    case constant::WSEndpoint::BOOKING_POST:
        emit postBookingHeaderFinished(response, status);
        break;
    case constant::WSEndpoint::BOOKING_PATCH:
        emit updateBookingFinished(response, status);
        break;
    case constant::WSEndpoint::BOOKING_ROOM_REPARTITIONS_GET:
        emit fetchRoomRepartitionsFinished(response, status);
        break;
    case constant::WSEndpoint::BOOKING_ROOM_REPARTITION_GET:
        emit fetchRoomRepartitionFinished(response, status);
        break;
    case constant::WSEndpoint::BOOKING_ROOM_REPARTITIONS_POST:
        emit postRoomRepartitionsFinished(response, status);
        break;
    }
}
