import QtQuick 2.15

ListModel {
    ListElement {title: "-"; type: "separator"; source: "qrc:/"}
    ListElement {title: "Restaurant"; type: "menu"; source: "qrc:/UI/View/PosActivitiesView.qml"}
    ListElement {title: "Reservation"; type: "menu"; source: "qrc:/UI/View/ResaPlanningView.qml"}
    ListElement {title: "Réception"; type: "menu"; source: "qrc:/UI/View/RecepPlanningView.qml"}
}
