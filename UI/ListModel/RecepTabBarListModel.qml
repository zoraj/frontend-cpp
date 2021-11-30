import QtQuick 2.15

ListModel {
    ListElement {title: "Planning"; type: "separator"; source: "qrc:/Views/Recep/PlanningView.qml"}
    ListElement {title: "Rechercher"; type: "menu"; source: "qrc:/Views/Recep/SearchView.qml"}
    ListElement {title: "Note en attente"; type: "menu"; source: "qrc:/Views/Recep/PendingNoteView.qml"}
    ListElement {title: "Notification"; type: "menu"; source: "qrc:/Views/Common/NotificationView.qml"}
}
