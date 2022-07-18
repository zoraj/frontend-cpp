import QtQuick 2.15
import QtQuick.Controls 2.15

import "qrc:/."
import "qrc:/UI/Component"
import "qrc:/UI/ViewCell"

Flickable {
    //property alias newBookingButton: newBookingButton
    property alias roomsListView: roomsListView
    property alias dateListView: dateListView

    Rectangle { /* Search input rectangle */
        id: topRect
        x: P._MARGIN_CONTAINER; y: P._MARGIN_CONTAINER
        width: parent.width - P._MARGIN_CONTAINER * 2; height: P._ACTION_BUTTON_CONTAINER_HEIGHT
        Row {
            spacing: P._MARGIN_COMPONENT
            anchors.centerIn: parent
            Image {
                source: "qrc:/Assets/Image/Common/arrow-left-icon.png"
                width: 50; height: 50
                fillMode: Image.PreserveAspectFit
                MouseArea {
                    anchors.fill: parent
                    /*
                    onClicked: {
                       console.info("image clicked!")
                    }*/
                }
            }
            MatDatePicker {

            }
            Image {
                source: "qrc:/Assets/Image/Common/arrow-right-icon.png"
                width: 50; height: 50
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

    Rectangle { /* Planning Rectangle */
        id: centerRect
        width: parent.width - P._MARGIN_CONTAINER * 2; height: parent.height - topRect.height - P._MARGIN_CONTAINER * 3
        anchors.top: topRect.bottom; anchors.topMargin: P._SPACE_COMPONENT; anchors.left: topRect.left
        color: "transparent"
        Column {
            ListView { /* Date Calendar */
                id: dateListView
                width: centerRect.width; height: 42
                x: 180
                orientation: Qt.Horizontal
                clip: true
                spacing: 2
                anchors.margins: 2
                delegate: Rectangle {
                    width: (dateListView.width - 150) / 16; height: 40
                    //color: "red"
                    Text {
                        id: topText
                        text: Qt.formatDate(date, "ddd");
                        anchors.horizontalCenter: parent.horizontalCenter
                    }
                    Text {
                        anchors.top: topText.bottom; anchors.topMargin: P._SPACE_COMPONENT
                        text: Qt.formatDate(date, "dd");
                        font.pointSize: 15
                        anchors.horizontalCenter: parent.horizontalCenter
                    }
                    Rectangle {
                        height: parent.height; width: 1
                        color: 'lightgrey'
                    }
                }
            }
            ListView { /* Rooms */
                id: roomsListView
                width: centerRect.width; height: centerRect.height
                spacing: 2
                clip: true
                delegate: BookingPlanningViewCell {
                    width: roomsListView.width; height: 40
                    roomId: _id
                    roomNumber: numeroChambre
                    roomTypeLabel: typeChambreLibelle
                    currentDate: _bookingPlanningViewController.currentDate_
                    // @disable-check M222
                    bookings: _bookingPlanningViewController.getBookings(_bookingPlanningViewController.currentDate_, _id)

                    //bookings: _bookingPlanningViewController.bookings_
                    //bookingRoomRepartitions: _bookingPlanningViewController.bookingRoomRepartitions_
                }
                    /*Column {
                    id: roomListColumn
                    //color: "red"
                    width: centerRect.width; height: 40
                    Text {
                        x: P._SPACE_COMPONENT
                        id: roomText
                        text: "<b>" + numeroChambre + "</b>" + " / " + typeChambreLibelle
                    }
                    /*
                    Rectangle {
                        height: 1; width: centerRect.width
                        color: 'lightgrey'
                        anchors.top: roomText.bottom
                    }
                    // @disable-check M223
                    Component.onCompleted: {
                        // @disable-check M223
                        for (var i = 0; i < 0; i++) {
                            // @disable-check M223
                            if (i === index) {
                                // @disable-check M222
                                Qt.createComponent("qrc:/UI/ViewCell/BookingPlanningItemCell.qml").createObject(roomListColumn,
                                                                                    {"x": 100,
                                                                                     "y": 1,
                                                                                     "bookingName": _bookingPlanningViewController.bookings_[0]["nomReservation"]
                                                                                    });
                            }
                       }
                    }
                }*/
            }
        }
    }
    /*
    RoundButton {
        x: parent.width - 100; y: parent.height - 100
        //text: "\u2713" // Unicode Character 'CHECK MARK'
        text: "+"
        id: newBookingButton
    }*/
}
