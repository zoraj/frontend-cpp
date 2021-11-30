import QtQuick 2.15

ListModel {
    ListElement {title: "Planning"; type: "separator"; source: "qrc:/Views/Resa/PlanningView.qml"}
    ListElement {title: "Rechercher"; type: "menu"; source: "qrc:/Views/Resa/SearchView.qml"}
    ListElement {title: "Preaffectation"; type: "menu"; source: "qrc:/Views/Resa/PreaffectationView.qml"}
    ListElement {title: "Notification"; type: "menu"; source: "qrc:/Views/Common/NotificationView.qml"}
}
