import QtQuick 2.15

BookingSearchViewForm {
    ListModel {
        id: bookingListModel
        ListElement {name: "Amanda"; arrival: "2021-02-11"; departure: "2021-02-13"; room: "201"}
        ListElement {name: "Zo"; arrival: "2021-02-15"; departure: "2021-02-16"; room: "301"}
        ListElement {name: "Elinah"; arrival: "2021-02-14"; departure: "2021-02-16"; room: "203"}
    }

    Connections {

    }

    function bookingSelected(index) {
        gMainStackView.push(null, "qrc:/UI/View/BookingDetailView.qml")
    }

    Component.onCompleted: {
        gViewTitle = "Recherche réservation"
    }
}
