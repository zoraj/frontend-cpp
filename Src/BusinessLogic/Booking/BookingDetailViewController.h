#pragma once

#include <QDebug>
#include <QSortFilterProxyModel>

#include "Src/Application/Base/BaseViewController.h"
#include "BookingService.h"
#include "Src/BusinessLogic/Room/RoomService.h"

#include "Booking.h"
#include "Src/BusinessLogic/Rate/RateGrid.h"
#include "Src/BusinessLogic/Client/Client.h"

#include "Src/BusinessLogic/Rate/RateGridListModel.h"
#include "Src/BusinessLogic/Client/ClientListModel.h"
#include "Src/BusinessLogic/Segmentation/ClientTypeListModel.h"
#include "Src/BusinessLogic/Segmentation/SegmentationListModel.h"
#include "Src/BusinessLogic/Segmentation/PrescripteurListModel.h"
#include "Src/BusinessLogic/Room/RoomTypeListModel.h"
#include "Src/BusinessLogic/Room/RoomListModel.h"
#include "Src/BusinessLogic/Booking/BookingRoomListModel.h"
#include "Src/BusinessLogic/Booking/Booking.h"

#include "Src/BusinessLogic/Rate/RateGridCache.h"
#include "Src/BusinessLogic/Client/ClientCache.h"
#include "Src/BusinessLogic/Segmentation/ClientTypeCache.h"
#include "Src/BusinessLogic/Segmentation/SegmentationCache.h"
#include "Src/BusinessLogic/Segmentation/PrescripteurCache.h"
#include "Src/BusinessLogic/Room/RoomTypeCache.h"
#include "Src/BusinessLogic/Room/RoomCache.h"

#include "Src/BusinessLogic/Room/RoomRepartitionBuilder.h"

class BookingDetailViewController : public BaseViewController
{
    Q_OBJECT
    Q_PROPERTY(RateGridListModel *rateGridListModel MEMBER rateGridListModel)
    Q_PROPERTY(ClientListModel *clientListModel_ MEMBER clientListModel_)
    Q_PROPERTY(ClientTypeListModel *clientTypeListModel MEMBER clientTypeListModel)
    Q_PROPERTY(SegmentationListModel *segmentationListModel MEMBER segmentationListModel)
    Q_PROPERTY(PrescripteurListModel *prescripteurListModel MEMBER prescripteurListModel)
    Q_PROPERTY(RoomTypeListModel *roomTypeListModel MEMBER roomTypeListModel CONSTANT)
    Q_PROPERTY(RoomListModel *roomListModel MEMBER roomListModel CONSTANT)
    Q_PROPERTY(Booking *booking_ MEMBER booking_ NOTIFY bookingChanged)
    Q_PROPERTY(BookingRoomListModel *bookingRoomListModel MEMBER bookingRoomListModel NOTIFY bookingChanged)
    Q_PROPERTY(QSortFilterProxyModel *roomListProxyModel MEMBER roomListProxyModel CONSTANT)

    QList<RoomType *> roomTypes_;
    QList<Room *> rooms_;

    RateGridListModel *rateGridListModel;
    ClientListModel *clientListModel_;
    ClientTypeListModel *clientTypeListModel;
    SegmentationListModel *segmentationListModel;
    PrescripteurListModel *prescripteurListModel;
    RoomTypeListModel *roomTypeListModel;
    RoomListModel *roomListModel;
    BookingRoomListModel *bookingRoomListModel;

    RoomService *roomService;

    Booking *booking_;
    QList<BookingRoom *> bookingRooms_;

    QSortFilterProxyModel *roomListProxyModel;
    void loadData();
    void persistData();
    void fetchRoomsRepartition();
    void submitBookingData();
    void submitBookingRoomRepartitionData();
    void submitBookingInfosComplData();
    QString getRoomTypeNameById(int id);
    QString getRoomNameById(int id);
public:
    BookingDetailViewController(QObject *parent = nullptr);

    Q_INVOKABLE
    void viewDidLoad() override;
    Q_INVOKABLE
    void viewDidUnload() override;

    Q_INVOKABLE
    void setBooking(Booking *booking);

    Q_INVOKABLE
    void roomTypeComboBoxChanged(int roomTypeIndex);
    Q_INVOKABLE
    void roomSelectionDialogValidate_Clicked(int roomTypeId, int roomId, int index);

signals:
    void viewDidLoadFinished();
    void bookingChanged(Booking *booking);
    void roomListProxyModelChanged();
    void submitBookingDataFinished(bool result, Booking *booking);
public slots:
    void validateButton_Clicked(int tabIndex);
    void roomCount_Changed(int roomCount);
};

