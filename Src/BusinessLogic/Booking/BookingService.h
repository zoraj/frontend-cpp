#pragma once

#include "Src/Application/Base/BaseService.h"
#include "Booking.h"
#include "BookingBuilder.h"

class BookingService : public BaseService
{
    Q_OBJECT
public:
    BookingService(const QString &apiKey, const QString &token);

    void fetchBookings();
    void postBookingHeader(const Booking &booking);
    void updateBooking(const Booking &booking);
    void fetchRoomRepartitions();
    void fetchRoomRepartition(int bookingId);
    void postRoomRepartitions(const Booking &booking);

    void callback(constant::WSEndpoint endpoint, const QByteArray &response, int status) override;
signals:
    void fetchBookingsFinished(const QByteArray &payload, int status);
    void postBookingHeaderFinished(const QByteArray &payload, int status);
    void updateBookingFinished(const QByteArray &payload, int status);
    void fetchRoomRepartitionsFinished(const QByteArray &payload, int status);
    void fetchRoomRepartitionFinished(const QByteArray &payload, int status);
    void postRoomRepartitionsFinished(const QByteArray &payload, int status);
};
