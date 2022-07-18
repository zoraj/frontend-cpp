#include "BookingPlanningViewController.h"

// Private methods - start
void BookingPlanningViewController::loadData()
{
    currentDate_ = ApplicationManager::getInstance()->getAppContext()->currentDate;

    // Date planning
    for(int i =0; i < constant::BOOKING_PLANNING_DATE_INTERVAL; i++) {
        PlanningDate *item = new PlanningDate();
        item->index = 0;
        item->date = currentDate_.addDays(i);
        item->isWeekEnd = true;
        planningDates_.append(item);
        qDebug() << "Date: " << item->date;
    }
    planningDateListModel_->setList(planningDates_);

    // Fetch bookings
    auto bookingService = new BookingService(APP_CONTEXT_API_KEY, APP_CONTEXT_TOKEN);
    bookingService->fetchBookings();
    QObject::connect(bookingService, &BookingService::fetchBookingsFinished, [=] (const QByteArray &response, int status){
        if (status == constant::HttpStatusCode::OK) {
            bookings_ = builder::booking::createList(response);
            qDebug() << "Booking found: " << bookings_.size();

        }
        bookingService->deleteLater();
    });

    // Fetch existing rooms in the hotel
    auto roomService = new RoomService(APP_CONTEXT_API_KEY, APP_CONTEXT_TOKEN);
    roomService->fetchRooms();
    QObject::connect(roomService, &RoomService::fetchRoomsFinished, [=] (const QByteArray &response, int status){
        if (status == constant::HttpStatusCode::OK) {
            rooms_ = builder::room::create(response);
            roomListModel_->setList(rooms_);
        }
        roomService->deleteLater();

    });

    // Fetch Booking Room Repartitions
    auto bookingRoomRepartitionsService = new BookingService(APP_CONTEXT_API_KEY, APP_CONTEXT_TOKEN);
    bookingRoomRepartitionsService->fetchRoomRepartitions();
    QObject::connect(bookingRoomRepartitionsService, &BookingService::fetchRoomRepartitionsFinished, [=] (const QByteArray &response, int status){
        if (status == constant::HttpStatusCode::OK) {
            bookingRoomRepartitions_ = builder::booking_room::createList(response);
        }
        bookingRoomRepartitionsService->deleteLater();
        emit viewDidLoadFinished();
    });
}
// Private methods - end

// Public methods - start
BookingPlanningViewController::BookingPlanningViewController(QObject *parent) : BaseViewController(parent)
{
    roomListModel_ = new RoomListModel(this);
    planningDateListModel_ = new PlanningDateListModel(this);
}

void BookingPlanningViewController::viewDidLoad()
{
    loadData();
    //emit viewDidLoadFinished();
}

void BookingPlanningViewController::viewDidUnload()
{

}

/*
 * This must return 14 bookings.
 * If there is no booking at a giving date, it will return an undefined booking
*/
QList<Booking *> BookingPlanningViewController::getBookings(QDate fromArrival, int roomId)
{
    QList<Booking *> bookings;
    for (int i = 0; i < constant::BOOKING_PLANNING_DATE_INTERVAL; i++) {
        const QDate arrivalDate = fromArrival.addDays(i);
        bool isBookingFound = false;
        for (Booking *booking: bookings_) {
            for(BookingRoom *bookingRoom: bookingRoomRepartitions_) {
                if (bookingRoom->reservationId == booking->id && bookingRoom->chambreId == roomId && booking->dateArrivee == arrivalDate) {
                    isBookingFound = true;
                    bookings.append(booking);
                }
            }
        }
        if (!isBookingFound) {
            Booking *undefinedBooking = new Booking();
            undefinedBooking->nomReservation = "UNDEFINED";
            bookings.append(undefinedBooking);
        }

    }
    qDebug() << "Booking Count for roomId " << roomId << " " << bookings.count();
    return bookings;
}
/*

QList<Booking *>BookingPlanningViewController::getBookings(int roomId)
{

    for (Booking *booking: bookings_) {
        for(BookingRoom *bookingRoom: bookingRoomRepartitions_) {
            if (bookingRoom->chambreId == roomId && booking->dateArrivee == dateRef) {
                return booking;
            }
        }
    }
    return nullptr;
}*/

// Public methods - end


