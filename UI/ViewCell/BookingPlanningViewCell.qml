import QtQuick 2.15
import QtQuick.Controls 2.15
import "qrc:/."
import "qrc:/UI/Component"
import "qrc:/UI/ViewCell"

import "qrc:/UI/Script/Date.js" as DateJS
Rectangle {
    color: "white"
    property int roomId: -1
    property string roomNumber: ""
    property string roomTypeLabel: ""
    property string bookingName: ""
    property date currentDate

    property variant bookings
    property variant bookingRoomRepartitions
    Row {

        spacing: 3
        Text {
            id: roomDetailText
            x: P._SPACE_COMPONENT
            text: "<b>" + roomNumber + "</b>" + " / " + roomTypeLabel
            width: 150
        }

        /* Zo - BookingPlanningItemCell is hardcoded to be 14, we cannot display more than this number for now (v1) */
        /* 14 maximum booking during 2 weeks per room */
        Rectangle { /* Booking 0 at Date t */
            id: bookingItem0Rect
            width: 80
            height: 30
            Text {
                text: {
                    if (bookings[0]["nomReservation"] !== "UNDEFINED") {
                        bookingItem0Rect.width = 150
                        return bookings[0]["nom"]
                    }
                    else {
                        bookingItem0Rect.color = "grey"
                        return ""
                    }
                }
            }
            color: "red"
        }
        Rectangle { /* Booking 1 at Date t + 1 */
            id: bookingItem1Rect
            width: 80
            height: 30
            Text {
                text: {
                    if (bookings[1]["nomReservation"] !== "UNDEFINED") {
                        return bookings[1]["nom"]
                    }
                    else {
                        bookingItem1Rect.color = "grey"
                        return ""
                    }
                }
            }
            color: "blue"


        }
        Rectangle { /* Booking 3 at Date t + 2 */
            id: bookingItem2Rect
            width: 80
            height: 30
            Text {
                text: {
                    if (bookings[2]["nomReservation"] !== "UNDEFINED") {
                        return bookings[2]["nom"]
                    }
                    else {
                        bookingItem2Rect.color = "grey"
                        return ""
                    }
                }
            }
            color: "yellow"
        }
        Rectangle { /* Booking 3 at Date t + 3 */
            id: bookingItem3Rect
            width: 80
            height: 30
            Text {
                text: {
                    if (bookings[3]["nomReservation"] !== "UNDEFINED") {
                        bookingItem3Rect.width = 200
                        return bookings[3]["nom"]
                    }
                    else {
                        bookingItem3Rect.color = "grey"
                        return ""
                    }
                }
            }
            color: "magenta"
        }
        Rectangle { /* Booking 5  at Date t + 4 */
            id: bookingItem4Rect
            width: 80
            height: 30
            Text {
                text: {
                    if (bookings[4]["nomReservation"] !== "UNDEFINED") {
                        return bookings[4]["nom"]
                    }
                    else {
                        bookingItem4Rect.color = "grey"
                        return ""
                    }
                }
            }
            color: "grey"
        }
        Rectangle { /* Booking 3*/
            id: bookingItem5Rect
            width: 80
            height: 30
            Text {
                text: {
                    if (bookings[5]["nomReservation"] !== "UNDEFINED") {
                        return bookings[5]["nom"]
                    }
                    else {
                        bookingItem5Rect.color = "grey"
                        return ""
                    }
                }
            }
            color: "red"
        }
        Rectangle { /* Booking 3*/
            id: bookingItem6Rect
            width: 80
            height: 30
            Text {
                text: {
                    if (bookings[6]["nomReservation"] !== "UNDEFINED") {
                        return bookings[6]["nom"]
                    }
                    else {
                        bookingItem6Rect.color = "grey"
                        return ""
                    }
                }
            }
            color: "lightgrey"
        }
        Rectangle { /* Booking 3*/
            id: bookingItem7Rect
            width: 80
            height: 30
            Text {
                text: {
                    if (bookings[7]["nomReservation"] !== "UNDEFINED") {
                        return bookings[7]["nom"]
                    }
                    else {
                        bookingItem7Rect.color = "grey"
                        return ""
                    }
                }
            }
            color: "red"
        }
        Rectangle { /* Booking 3*/
            id: bookingItem8Rect
            width: 80
            height: 30
            Text {
                text: {
                    if (bookings[8]["nomReservation"] !== "UNDEFINED") {
                        return bookings[8]["nom"]
                    }
                    else {
                        bookingItem8Rect.color = "grey"
                        return ""
                    }
                }
            }
            color: "red"
        }
        Rectangle { /* Booking 3*/
            id: bookingItem9Rect
            width: 80
            height: 30
            Text {
                text: {
                    if (bookings[9]["nomReservation"] !== "UNDEFINED") {
                        return bookings[9]["nom"]
                    }
                    else {
                        bookingItem9Rect.color = "grey"
                        return ""
                    }
                }
            }
            color: "red"
        }
        Rectangle { /* Booking 3*/
            id: bookingItem10Rect
            width: 80
            height: 30
            Text {
                text: {
                    if (bookings[10]["nomReservation"] !== "UNDEFINED") {
                        return bookings[10]["nom"]
                    }
                    else {
                        bookingItem10Rect.color = "grey"
                        return ""
                    }
                }
            }
            color: "red"
        }
        Rectangle { /* Booking 3*/
            id: bookingItem11Rect
            width: 80
            height: 30
            Text {
                text: {
                    if (bookings[11]["nomReservation"] !== "UNDEFINED") {
                        return bookings[11]["nom"]
                    }
                    else {
                        bookingItem11Rect.color = "grey"
                        return ""
                    }
                }
            }
            color: "red"
        }
        Rectangle { /* Booking 3*/
            id: bookingItem12Rect
            width: 80
            height: 30
            Text {
                text: {
                    if (bookings[12]["nomReservation"] !== "UNDEFINED") {
                        return bookings[12]["nom"]
                    }
                    else {
                        bookingItem12Rect.color = "grey"
                        return ""
                    }
                }
            }
            color: "red"
        }
        Rectangle { /* Booking 3*/
            id: bookingItem13Rect
            width: 80
            height: 30
            Text {
                text: {
                    if (bookings[13]["nomReservation"] !== "UNDEFINED") {
                        return bookings[13]["nom"]
                    }
                    else {
                        bookingItem13Rect.color = "grey"
                        return ""
                    }
                }
            }
            color: "red"
        }
    }
}
