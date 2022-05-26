import QtQuick 2.15

PosActivitiesViewForm {

    // UI Events
    function openNoteButtonClicked(activityId) {
        gViewTitle = qsTr("OPEN_NOTES_LIST") // Liste des notes ouvertes
        tablePlanGridView.visible = false
        openOrderListView.visible = true

        _activitiesViewController.openNoteButton_Clicked(activityId)
    }

    function newNoteButtonClicked(activityId) {
        _activitiesViewController.newNoteButton_Clicked(activityId)
        gMainStackView.push(null, "qrc:/UI/View/OrderView.qml", {"orderId": -1, "numTable": 0}) // -1 means it's a new order
    }

    function pushToOrderView() {

    }

    function tablePlanButtonClicked(activityId) {
        tablePlanGridView.visible = true
        openOrderListView.visible = false
        gViewTitle = qsTr("TABLE_PLAN")
        _activitiesViewController.tablePlanButton_Clicked(activityId)
    }

    function showTableNote() {
        tablePlanGridView.visible = true
        openOrderListView.visible = false
        gViewTitle = qsTr("TABLE_PLAN") // "Plan des tables"
    }

    function toggleService(service) {
        _activitiesViewController.toggleService(service)
    }

    function tableCellSelected(orderId, numTable) {
        gMainStackView.push(null, "qrc:/Views/Resto/OrderView.qml", {"orderId": orderId, "tableNum": numTable})
    }
    function openNoteSelected(orderId) {
        gMainStackView.push(null, "qrc:/Views/Resto/OrderView.qml", {"orderId": orderId, "tableNum": 0})
    }


    // UI
    Connections {
        target: _activitiesViewController
        function onViewDidLoadFinished(username) {
            gUserName = username
            activitiesListView.model =_activitiesViewController.activityListModel
            openOrderListView.model =_activitiesViewController.openOrderListModel
            tablePlanGridView.model = _activitiesViewController.tablePlanListModel
        }
    }

    Component.onCompleted: {
        gShouldServiceChoicePOSVisible = true
        _activitiesViewController.viewDidLoad()
        // TODO : When no open order, table should be shown automatically
        //showOpenNoteList()
    }
    onVisibleChanged: {
        gShouldServiceChoicePOSVisible = visible
    }
}
