import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import "qrc:/."
import "qrc:/UI/ViewCell"

Flickable {
    property alias activitiesListView: activitiesListView
    property alias tablePlanGridView: tablePlanGridView
    property alias openOrderListView: openOrderListView
    /* Rectangle containing Activities ListView */
    Rectangle {
        id: topRect
        x: P._MARGIN_CONTAINER; y: P._MARGIN_CONTAINER
        width: 300; height: parent.height - P._MARGIN_CONTAINER * 2
        ListView {
            id: activitiesListView
            anchors.fill: parent; anchors.topMargin: P._MARGIN_CONTAINER; anchors.leftMargin: P._MARGIN_CONTAINER
            clip: true
            spacing: P._SPACE_COMPONENT
            delegate: PosActivitiesViewActivityCell {
                width: 200; height: 200
                activityId: _id
                activityName: libelle
                iconName: iconImg
                isTablePlan: isGestionTable
            }
        }
    }
    /* --- Main Rectangle Containing Tables plan and open order--- */
    Rectangle {
        id: mainRect
        color: "transparent"
        width: parent.width - topRect.width - P._MARGIN_CONTAINER * 3; height: parent.height - P._MARGIN_CONTAINER * 2
        anchors.left: topRect.right; anchors.top: topRect.top; anchors.leftMargin: P._MARGIN_CONTAINER
        Column {
            anchors.fill: parent; anchors.leftMargin: P._MARGIN_CONTAINER; anchors.topMargin: P._MARGIN_CONTAINER
            spacing: P._MARGIN_CONTAINER
            /* --- Grid For Tables --- */
            GridView {
                id: tablePlanGridView
                leftMargin: 30
                width: mainRect.width - P._MARGIN_CONTAINER * 2; height: mainRect.height - P._MARGIN_CONTAINER * 3
                cellWidth: 160
                cellHeight: 160
                clip: true
                visible: false
                delegate: PosActivitiesViewTableCell {
                    cellWidth: tableNoteGridView.cellWidth - 10
                    cellHeight: tableNoteGridView.cellHeight - 10
                    numTable: tableNum
                    isAvail: isAvailable
                    orderId: _orderId
                    // @disable-check M223
                    onClicked: {
                        // @disable-check M222
                        tableCellSelected(_orderId, tableNum)
                    }
                }
            }
            /* --- Open Order List view --- */
            ListView {
                id: openOrderListView
                width: mainRect.width - P._MARGIN_CONTAINER * 2; height: mainRect.height - P._MARGIN_CONTAINER * 3
                clip: true

                delegate: PosActivitiesViewOpenOrderCell {
                    width: mainRect.width; height: 84
                    cellWidth: mainRect.width; cellHeight: 84
                    numTable: numeroTable
                    orderAmout: nbCouvert
                    MouseArea {
                        anchors.fill: parent
                        // @disable-check M223
                        onClicked: {
                            // @disable-check M222
                            openNoteSelected(_id)
                        }
                    }
                }
            }
        }
    }
}
