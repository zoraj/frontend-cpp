import QtQuick 2.15

ListModel {
    ListElement {title: "Z Caisse"; type: "menu"; source: "qrc:/"}
    ListElement {title: "Tirroir"; type: "menu"; source: "qrc:/"}
    ListElement {title: "-"; type: "separator"; source: "qrc:/"}
    ListElement {title: "Reservation"; type: "menu"; source: "qrc:/UI/View/ResaPlanningView.qml"}
    ListElement {title: "Réception"; type: "menu"; source: "qrc:/UI/View/RecepPlanningView.qml"}
    ListElement {title: "Gouvernante"; type: "menu"; source: "qrc:/UI/View/HouseKeepingCalendarView.qml"}
}
