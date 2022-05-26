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
        qDebug() << "status: " << status;
        if (status == constant::HttpStatusCode::OK) {
            bookings_ = builder::booking::createList(response);
            qDebug() << "Booking found: " << bookings_.size();
            emit viewDidLoadFinished();
        }
        bookingService->deleteLater();
    });

    // Fetch rooms
    auto roomService = new RoomService(APP_CONTEXT_API_KEY, APP_CONTEXT_TOKEN);
    roomService->fetchRooms();
    QObject::connect(roomService, &RoomService::fetchRoomsFinished, [=] (const QByteArray &response, int status){
        if (status == constant::HttpStatusCode::OK) {
            rooms_ = builder::room::create(response);
            roomListModel_->setList(rooms_);
        }
        roomService->deleteLater();
    });

    auto bookingRoomRepartitionsService = new BookingService(APP_CONTEXT_API_KEY, APP_CONTEXT_TOKEN);
    bookingRoomRepartitionsService->fetchRoomRepartitions();
    QObject::connect(bookingRoomRepartitionsService, &BookingService::fetchRoomRepartitionsFinished, [=] (const QByteArray &response, int status){
        if (status == constant::HttpStatusCode::OK) {
            bookingRoomRepartitions_ = builder::booking_room::createList(response);
        }
        bookingRoomRepartitionsService->deleteLater();
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

// Public methods - end


