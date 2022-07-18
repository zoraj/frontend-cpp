#pragma once

#include "Src/Application/Base/BaseViewController.h"
#include "Src/BusinessLogic/Room/Room.h"
#include "Src/BusinessLogic/Booking/Booking.h"
#include "Src/BusinessLogic/Booking/BookingService.h"
#include "Src/BusinessLogic/Room/RoomService.h"
#include "Src/BusinessLogic/Room/RoomBuilder.h"
#include "Src/BusinessLogic/Room/RoomListModel.h"
#include "Src/BusinessLogic/Planning/PlanningDate.h"
#include "Src/BusinessLogic/Planning/PlanningDateListModel.h"
#include "Src/BusinessLogic/Booking/BookingRoomBuilder.h"

class BookingPlanningViewController : public BaseViewController
{
    Q_OBJECT
    Q_PROPERTY(RoomListModel *roomListModel_ MEMBER roomListModel_)
    Q_PROPERTY(PlanningDateListModel *planningDateListModel_ MEMBER planningDateListModel_)
    Q_PROPERTY(QList<Booking *> bookings_ MEMBER bookings_ CONSTANT)
    Q_PROPERTY(QList<BookingRoom *> bookingRoomRepartitions_ MEMBER bookingRoomRepartitions_)
    Q_PROPERTY(QDate currentDate_ MEMBER currentDate_ CONSTANT)

    QDate currentDate_;
    QList<PlanningDate *> planningDates_; // This will store the date that will be displayed on planning, by default a 30 days planning
    QList<Room *> rooms_;
    QList<Booking *> bookings_;
    QList<BookingRoom *> bookingRoomRepartitions_;
    RoomListModel *roomListModel_;
    PlanningDateListModel *planningDateListModel_;

    void loadData();
public:
    BookingPlanningViewController(QObject *parent = nullptr);

    Q_INVOKABLE
    void viewDidLoad() override;
    Q_INVOKABLE
    void viewDidUnload() override;
signals:
    void viewDidLoadFinished();
public slots:
    QList<Booking *>getBookings(QDate fromArrival, int roomId); // Index is the current index of the listview
    //QList<Booking *> getBookings(int roomId);
};

