import QtQuick 2.15

ListModel {
    ListElement {title: "Calendrier"; type: "separator"; source: "qrc:/Views/HK/CalendarView.qml"}
    ListElement {title: "Etat des chambres"; type: "menu"; source: "qrc:/Views/HK/RoomsStatusView.qml"}
    ListElement {title: "Inspection"; type: "menu"; source: "qrc:/Views/HK/RoomReportView.qml"}
}
