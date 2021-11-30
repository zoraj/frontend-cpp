import QtQuick 2.15
import QtQuick.Controls 2.15

import "qrc:/."
import "qrc:/UI/Component"

Flickable {
    property alias newBookingButton: newBookingButton
    property alias roomsListView: roomsListView
    Rectangle {
        id: topRect
        x: P._MARGIN_CONTAINER; y: P._MARGIN_CONTAINER
        width: parent.width - P._MARGIN_CONTAINER * 2; height: P._ACTION_BUTTON_CONTAINER_HEIGHT
        Row {
            spacing: P._MARGIN_COMPONENT
            Button {
                text: "<<"
            }
            Button {
                text: "<"
            }

            MatTextField {

            }

            Button {
                text: ">"
            }
            Button {
                text: ">>"
            }
        }
    }

    Rectangle {
        id: centerRect
        width: parent.width - P._MARGIN_CONTAINER * 2; height: parent.height - topRect.height - P._MARGIN_CONTAINER * 3
        anchors.top: topRect.bottom; anchors.topMargin: P._MARGIN_CONTAINER; anchors.left: topRect.left
        Column {
            ListView { /* Date */
                width: centerRect.width; height: 80
                x: 100
                orientation: Qt.Horizontal
                clip: true
                delegate: Rectangle {
                    width: 40; height: 40
                    Text {
                        id: topText
                        text: qsTr("Lun")
                    }
                    Text {
                        anchors.top: topText.bottom; anchors.topMargin: P._SPACE_COMPONENT
                        text: qsTr("19")
                        font.pointSize: 15
                    }
                }
                model: 20
            }
            ListView { /* Rooms */
                id: roomsListView
                width: centerRect.width; height: centerRect.height
                clip: true
                delegate: Rectangle {
                    id: rect
                    width: centerRect.width; height: 40
                    Text {
                        id: roomText
                        text: qsTr("201 - Twin")
                    }
                    Rectangle {
                        height: 1; width: centerRect.width
                        color: 'lightgrey'
                        anchors.top: roomText.bottom
                    }
                    // @disable-check M223
                    Component.onCompleted: {
                    }
                }
                model: 50
            }
        }
    }

    RoundButton {
        x: parent.width - 100; y: parent.height - 100
        //text: "\u2713" // Unicode Character 'CHECK MARK'
        text: "+"
        id: newBookingButton
    }
}
