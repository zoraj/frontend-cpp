import QtQuick 2.15

ListModel {
    ListElement {title: "Planning"; type: "separator"; source: "qrc:/Views/Recep/PlanningView.qml"}
    ListElement {title: "Restaurant"; type: "menu"; source: "qrc:/UI/View/PosActivitiesView.qml"}
    ListElement {title: "Réception"; type: "menu"; source: "qrc:/UI/View/RecepPlanningView.qml"}
    ListElement {title: "Gouvernante"; type: "menu"; source: "qrc:/UI/View/HouseKeepingCalendarView.qml"}
}
