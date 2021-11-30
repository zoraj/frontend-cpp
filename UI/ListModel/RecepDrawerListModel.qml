import QtQuick 2.15

ListModel {
    ListElement {title: "Vente comptant"; type: "menu"; source: "qrc:/Views/ActivitiesView.qml"}
    ListElement {title: "Transfert note"; type: "menu"; source: "qrc:/Views/ActivitiesView.qml"}
    ListElement {title: "Restaurant"; type: "menu"; source: "qrc:/UI/View/PosActivitiesView.qml"}
    ListElement {title: "Reservation"; type: "menu"; source: "qrc:/UI/View/ResaPlanningView.qml"}
    ListElement {title: "Gouvernante"; type: "menu"; source: "qrc:/UI/View/HouseKeepingCalendarView.qml"}
}
