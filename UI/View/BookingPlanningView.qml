import QtQuick 2.15

BookingPlanningViewForm {
    Connections {
        target: _bookingPlanningViewController
        function onViewDidLoadFinished() {
            // Date list (x-axis)
            dateListView.model = _bookingPlanningViewController.planningDateListModel_
            // Room lists (y-axis)
            roomsListView.model = _bookingPlanningViewController.roomListModel_
        }
    }

    Component.onCompleted: {
        gModule = 2 // Reservation Module
        _bookingPlanningViewController.viewDidLoad()
        gViewTitle = "Planning Réservation"
    }
}
