#include "BookingDetailViewController.h"



// Private methods
void BookingDetailViewController::loadData()
{
    // Load data from cache
    // Rate grid
    auto rateGrids = cache::rate_grid::getAll();
    rateGridListModel->list = rateGrids;
    // Clients
    auto clients = cache::client::getAll();
    clientListModel_->list = clients;
    // Client types
    auto clientTypes = cache::client_type::getAll();
    clientTypeListModel->list = clientTypes;
    // Segmentation
    auto segmentations = cache::segmentation::getAll();
    segmentationListModel->list = segmentations;
    // Prescripteur
    auto prescripteurs = cache::prescripteur::getAll();
    prescripteurListModel->list = prescripteurs;
    // Room types
    roomTypes_ = cache::room_type::getAll();
    roomTypeListModel->list = roomTypes_;
    // Rooms
    rooms_ = cache::room::getAll();
    roomListModel->setList(rooms_);
    roomListProxyModel->setSourceModel(roomListModel);
}

void BookingDetailViewController::persistData()
{
    qInfo() << "Persist data";
}

QString BookingDetailViewController::getRoomTypeNameById(int id) {
    foreach(RoomType *roomType, roomTypes_) {
        if (roomType->id == id) {
            return roomType->libelle;
        }
    }
    return ""; // TODO
}


QString BookingDetailViewController::getRoomNameById(int id) {
    foreach(Room *room, rooms_) {
        if (room->id == id) {
            return room->numeroChambre;
        }
    }
    return ""; // TODO
}


void BookingDetailViewController::submitBookingRoomRepartitionData() {
    auto bookingService = new BookingService(APP_CONTEXT_API_KEY, APP_CONTEXT_TOKEN);
    bookingService->postRoomRepartitions(*booking_);
    QObject::connect(bookingService, &BookingService::postRoomRepartitionsFinished, [=] (const QByteArray &response, int status){
        if (status == constant::HttpStatusCode::OK) {
            //booking_ = builder::booking::create(response);
            // After validating header, let's retrieve room repartition data
            //fetchRoomsRepartition();
        }
        bookingService->deleteLater();
        emit submitBookingDataFinished(status == constant::HttpStatusCode::OK, booking_);
    });
}

void BookingDetailViewController::submitBookingData() {
    auto bookingService = new BookingService(APP_CONTEXT_API_KEY, APP_CONTEXT_TOKEN);
    bookingService->postBookingHeader(*booking_);
    QObject::connect(bookingService, &BookingService::postBookingHeaderFinished, [=] (const QByteArray &response, int status){
        if (status == constant::HttpStatusCode::OK) {
            qDebug() << "BEFORE " << booking_->chambres.count();
            booking_ = builder::booking::create(response);
            booking_->chambres = bookingRooms_;
            qDebug() << "AFTER " << booking_->chambres.count();
            //fetchRoomsRepartition();
            submitBookingRoomRepartitionData();
        }
        bookingService->deleteLater();
        //emit validateButton_ClickedFinished(status == constant::HttpStatusCode::OK);
    });
}

void BookingDetailViewController::submitBookingInfosComplData() {
    auto bookingService = new BookingService(APP_CONTEXT_API_KEY, APP_CONTEXT_TOKEN);
    bookingService->updateBooking(*booking_);
    QObject::connect(bookingService, &BookingService::updateBookingFinished, [=] (const QByteArray &response, int status){
        if (status == constant::HttpStatusCode::OK) {
            //booking_ = builder::booking::create(response);
            //booking_->chambres = bookingRooms_;
        }
        bookingService->deleteLater();
        //emit validateButton_ClickedFinished(status == constant::HttpStatusCode::OK);
    });
}

// Public methods
BookingDetailViewController::BookingDetailViewController(QObject *parent) : BaseViewController(parent)
{
    //qDebug() << "PINCODE:" << ApplicationManager::getInstance()->getAppContext()->user->pinCode;
    // Services used to interact with remote server

    roomService = new RoomService(APP_CONTEXT_API_KEY, APP_CONTEXT_TOKEN);
    // List models used to populate data to listview
    rateGridListModel = new RateGridListModel();
    clientListModel_ = new ClientListModel();
    clientTypeListModel = new ClientTypeListModel();
    segmentationListModel = new SegmentationListModel();
    prescripteurListModel = new PrescripteurListModel();
    roomTypeListModel = new RoomTypeListModel();
    roomListModel = new RoomListModel();
    bookingRoomListModel = new BookingRoomListModel();

    // Proxy List Model used to filter data
    roomListProxyModel = new QSortFilterProxyModel(this);

    booking_ = new Booking();
}


void BookingDetailViewController::viewDidLoad()
{
    loadData();
    emit viewDidLoadFinished();
}

void BookingDetailViewController::viewDidUnload()
{
    delete booking_;
    booking_ = nullptr;
    delete roomListProxyModel;
    roomListProxyModel = nullptr;
}

void BookingDetailViewController::fetchRoomsRepartition()
{
    if (booking_->id != UNDEFINED_INT) {
        auto bookingService = new BookingService(APP_CONTEXT_API_KEY, APP_CONTEXT_TOKEN);
        bookingService->fetchRoomRepartition(booking_->id);
        QObject::connect(bookingService, &BookingService::fetchRoomRepartitionFinished, [=] (const QByteArray &response, int status) {
            if (status == constant::HttpStatusCode::OK) {
                auto roomRepartition = builder::room_repartition::create(response);
                booking_->chambres = roomRepartition;
            }
            else if (status == constant::HttpStatusCode::NotFound) { /* It means that there is not room partition yet, so let's create it ad set it by default value*/
                for(auto i = 0; i < booking_->nbChambre; i++) {
                    auto room = new BookingRoom();
                    room->reservationId = UNDEFINED_INT;
                    room->typeChambreId = UNDEFINED_INT;
                    room->chambreId = UNDEFINED_INT;
                    room->typeChambreLibelle = "N/A";
                    room->numeroChambre = "N/A";
                    booking_->chambres.append(room);
                }
            }
            bookingRoomListModel->setList(booking_->chambres);
            emit bookingChanged(booking_);
            bookingService->deleteLater();
        });
    }
}

// UI Invokable Methods
void BookingDetailViewController::setBooking(Booking *booking)
{
    booking_ = booking;
    booking_->chambres = bookingRooms_;
}



// UI Events
void BookingDetailViewController::validateButton_Clicked(int tabIndex)
{
    switch (tabIndex) {
    case 0: // Ventilation Tab
        // Call Create Booking endpoint
        submitBookingData();
        break;
    case 1: // Tarification Tab
        break;
    case 2: // Infos Compl. Tab
        submitBookingInfosComplData();
        break;
    case 3: // Arrhes Globales Tab
        break;
    default:
        break;
    }
    // Todo, test if booking is OK

    // Test if overbooking
    /*
    roomService->fetchAvailabilities(bookingData->dateArrivee, bookingData->dateDepart);
    QObject::connect(roomService.data(), &RoomService::fetchAvailabilitiesFinished, [=] (const QByteArray &response, int status) {
        if (status == constant::HttpStatusCode::OK) {

        }
    });*/
    /*
    // Call WS
    bookingService_->updateBooking(*booking_);
    QObject::connect(bookingService_, &BookingService::updateBookingFinished, [=] (const QByteArray &response, int status){
        if (status == constant::HttpStatusCode::OK) {
            booking_ = builder::booking::create(response);
            emit bookingChanged(booking_);

            // Ventillation

        }
    });
    */
}

void BookingDetailViewController::roomCount_Changed(int roomCount)
{
    // Let's set the booking rooms repartitions
    for(int i = 0; i < roomCount; i++) {
        BookingRoom *bookingRoom = new BookingRoom();
        bookingRoom->numeroChambre = "NON DEFINI";
        bookingRoom->typeChambreLibelle = "NON DEFINI";
        bookingRooms_.append(bookingRoom);
    }
    bookingRoomListModel->setList(bookingRooms_);
    // End - Booking rooms repartitions
}

/*
 * This will be invoked every time the user changes the room type
*/
void BookingDetailViewController::roomTypeComboBoxChanged(int roomTypeIndex)
{
    // Let's filter our rooms based on room type chosen
    int roomTypeId = roomTypeListModel->list.at(roomTypeIndex)->id;
    roomListProxyModel->setFilterRole(Qt::UserRole + 3); // Filter by room type id
    roomListProxyModel->setFilterFixedString(QString::number(roomTypeId));
}

void BookingDetailViewController::roomSelectionDialogValidate_Clicked(int roomTypeId, int roomId, int index)
{
    bookingRooms_.at(index)->typeChambreId = roomTypeId;
    bookingRooms_.at(index)->typeChambreLibelle = getRoomTypeNameById(roomTypeId);
    // Room number is not compulsory here
    bookingRooms_.at(index)->chambreId = roomId;
    bookingRooms_.at(index)->numeroChambre = getRoomNameById(roomId);
    bookingRoomListModel->setList(bookingRooms_);
    //emit bookingChanged(booking_);
}
