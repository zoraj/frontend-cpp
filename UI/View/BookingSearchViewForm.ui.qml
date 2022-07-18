import QtQuick 2.15
import QtQuick.Controls 2.15

import "qrc:/."
import "qrc:/UI/Component"
import "qrc:/UI/ViewCell"

Flickable {
    property alias bookingListView: bookingListView
    Rectangle {
        id: topRect
        x: P._MARGIN_CONTAINER; y: P._MARGIN_CONTAINER
        width: parent.width - P._MARGIN_CONTAINER * 2; height: P._ACTION_BUTTON_CONTAINER_HEIGHT
        Row {
            spacing: P._MARGIN_COMPONENT
            anchors.centerIn: parent
            MatTextField {
                width: topRect.width - 100
                horizontalAlignment: TextInput.AlignHCenter
            }
            Image {
                source: "qrc:/Assets/Image/PMS/button-find-icon.png"
                width: 30; height: 30
                fillMode: Image.PreserveAspectFit
                MouseArea {
                    anchors.fill: parent
                    /*
                    onClicked: {
                       console.info("image clicked!")
                    }*/
                }
            }
        }
    }
    ListView {
        id: bookingListView
        width: topRect.width; height: parent.height - topRect.height - P._MARGIN_CONTAINER * 3
        anchors.top: topRect.bottom; anchors.topMargin: P._SPACE_COMPONENT; anchors.left: topRect.left
        clip: true
        spacing: P._SPACE_COMPONENT
        delegate: BookingSearchViewCell {
            width: ListView.view.width; height: P._LISTVIEW_CELL_HEIGHT
            bookingId: 1
            bookingRef: "20220202255220001"
            bookingName: "Zo Rajaonarivony"
            nbPax: 2
            arrival: new Date()
            departure: new Date()
            MouseArea {
                anchors.fill: parent
                // @disable-check M223
                onClicked: {
                    // @disable-check M222
                    bookingSelected(index)
                }
            }
        }
        model: 20
    }
}
