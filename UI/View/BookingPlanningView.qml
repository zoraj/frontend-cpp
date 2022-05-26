import QtQuick 2.15

BookingPlanningViewForm {
    ListModel {
        id: bookingListModel
        ListElement {name: "Amanda"; arrival: "2021-02-11"; departure: "2021-02-13"; room: "201"}
        ListElement {name: "Zo"; arrival: "2021-02-15"; departure: "2021-02-16"; room: "301"}
        ListElement {name: "Elinah"; arrival: "2021-02-14"; departure: "2021-02-16"; room: "203"}
    }

    Connections {
        target: _bookingPlanningViewController
        function onViewDidLoadFinished() {
            roomsListView.model = _bookingPlanningViewController.roomListModel_
            dateListView.model = _bookingPlanningViewController.planningDateListModel_

            console.log(_bookingPlanningViewController.bookings_[0]["nomReservation"])
        }
    }

    Component.onCompleted: {
        gModule = 2 // Reservation Module
        _bookingPlanningViewController.viewDidLoad()
    }


    newBookingButton.onClicked: {
        gMainStackView.push(null, "qrc:/UI/View/BookingDetailView.qml")
    }
}
