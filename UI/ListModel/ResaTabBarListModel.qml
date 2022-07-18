import QtQuick 2.15

ListModel {
    ListElement {title: "Planning"; type: "replace"; source: "qrc:/UI/View/BookingPlanningView.qml"; iconPath: "qrc:/Assets/Image/TabBar/tab-planning-booking-icon.png"}
    ListElement {title: "Rechercher"; type: "replace"; source: "qrc:/UI/View/BookingSearchView.qml"; iconPath: "qrc:/Assets/Image/TabBar/tab-search-icon2.png"}
    ListElement {title: ""; type: "push"; source: "qrc:/UI/View/BookingDetailView.qml"; iconPath: "qrc:/Assets/Image/TabBar/tab-plus-icon1.png"}
    ListElement {title: "Preaffectation"; type: "replace"; source: "qrc:/UI/View/BookingPreaffectationView.qml"; iconPath: "qrc:/Assets/Image/TabBar/tab-folder-checked-icon.png"}
    ListElement {title: "Notification"; type: "replace"; source: "qrc:/UI/View/NotificationView.qml"; iconPath: "qrc:/Assets/Image/TabBar/tab-bell-icon.png"}
}
