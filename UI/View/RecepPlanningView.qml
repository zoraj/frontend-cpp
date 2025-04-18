import QtQuick 2.15

RecepPlanningViewForm {
    ListModel {
        id: bookingListModel
        ListElement {name: "Amanda"; arrival: "2021-02-11"; departure: "2021-02-13"; room: "201"}
        ListElement {name: "Zo"; arrival: "2021-02-15"; departure: "2021-02-16"; room: "301"}
        ListElement {name: "Elinah"; arrival: "2021-02-14"; departure: "2021-02-16"; room: "203"}
    }

    ListModel {
        id: roomListModel
    }

    ListModel {
        id: dateListModel
    }

    Component.onCompleted: {
        gModule = 1 // Checkin Module
    }

    /*
    newNoteButton.onClicked: {
        gMainStackView.push(null, "qrc:/Views/Recep/NoteDetailView.qml")
    }*/
}
