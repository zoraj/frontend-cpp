import QtQuick 2.15
import QtQuick.Controls 2.15
import "qrc:/."
import "qrc:/UI/Component"
import "qrc:/UI/ViewCell"


Row {
    property int roomId: -1
    property string roomNumber: ""
    property string roomTypeLabel: ""
    property string bookingName: ""
    property variant bookings
    property variant bookingRoomRepartitions
    property date currentDate
    spacing: 1
    Text {
        x: P._SPACE_COMPONENT
        text: "<b>" + roomNumber + "</b>" + " / " + roomTypeLabel
    }
    /* Zo - BookingPlanningItemCell is hardcoded to be 14, we cannot display more than this number for now (v1) */
    BookingPlanningItemCell {
        bookingName: {
            console.log("Booking Length :" + bookings.length)
            console.log("Current Date :" + currentDate)
            console.log("Arrival " + bookings[0]["dateArrivee"])
            console.log("ID :" + roomId)
            for (let i = 0; i < bookings.length; i++) {
                if (bookings[0]["dateArrivee"] === currentDate)
                    return bookings[0]["nomReservation"]
            }
        }
        visible: bookingName !== ""
    }/*
    BookingPlanningItemCell {
        bookingName: {
            for (let i = 0; i < bookings.length; i++) {
                if (bookings[0]["dateArrivee"] === currentDate)
                    return bookings[0]["nomReservation"]
            }
        }
        visible: bookingName !== ""
    }
    BookingPlanningItemCell {
        bookingName: {
            for (let i = 0; i < bookings.length; i++) {
                if (bookings[0]["dateArrivee"] === currentDate)
                    return bookings[0]["nomReservation"]
            }
        }
        visible: bookingName !== ""
    }
    BookingPlanningItemCell {
        bookingName: {
            for (let i = 0; i < bookings.length; i++) {
                if (bookings[0]["dateArrivee"] === currentDate)
                    return bookings[0]["nomReservation"]
            }
        }
        visible: bookingName !== ""
    }
    BookingPlanningItemCell {
        bookingName: {
            for (let i = 0; i < bookings.length; i++) {
                if (bookings[0]["dateArrivee"] === currentDate)
                    return bookings[0]["nomReservation"]
            }
        }
        visible: bookingName !== ""
    }
    BookingPlanningItemCell {
        bookingName: {
            for (let i = 0; i < bookings.length; i++) {
                if (bookings[0]["dateArrivee"] === currentDate)
                    return bookings[0]["nomReservation"]
            }
        }
        visible: bookingName !== ""
    }
    BookingPlanningItemCell {
        bookingName: {
            for (let i = 0; i < bookings.length; i++) {
                if (bookings[0]["dateArrivee"] === currentDate)
                    return bookings[0]["nomReservation"]
            }
        }
        visible: bookingName !== ""
    }
    BookingPlanningItemCell {
        bookingName: {
            for (let i = 0; i < bookings.length; i++) {
                if (bookings[0]["dateArrivee"] === currentDate)
                    return bookings[0]["nomReservation"]
            }
        }
        visible: bookingName !== ""
    }
    BookingPlanningItemCell {
        bookingName: {
            for (let i = 0; i < bookings.length; i++) {
                if (bookings[0]["dateArrivee"] === currentDate)
                    return bookings[0]["nomReservation"]
            }
        }
        visible: bookingName !== ""
    }
    BookingPlanningItemCell {
        bookingName: {
            for (let i = 0; i < bookings.length; i++) {
                if (bookings[0]["dateArrivee"] === currentDate)
                    return bookings[0]["nomReservation"]
            }
        }
        visible: bookingName !== ""
    }
    BookingPlanningItemCell {
        bookingName: {
            for (let i = 0; i < bookings.length; i++) {
                if (bookings[0]["dateArrivee"] === currentDate)
                    return bookings[0]["nomReservation"]
            }
        }
        visible: bookingName !== ""
    }
    BookingPlanningItemCell {
        bookingName: {
            for (let i = 0; i < bookings.length; i++) {
                if (bookings[0]["dateArrivee"] === currentDate)
                    return bookings[0]["nomReservation"]
            }
        }
        visible: bookingName !== ""
    }
    BookingPlanningItemCell {
        bookingName: {
            for (let i = 0; i < bookings.length; i++) {
                if (bookings[0]["dateArrivee"] === currentDate)
                    return bookings[0]["nomReservation"]
            }
        }
        visible: bookingName !== ""
    }
    BookingPlanningItemCell {
        bookingName: {
            for (let i = 0; i < bookings.length; i++) {
                if (bookings[0]["dateArrivee"] === currentDate)
                    return bookings[0]["nomReservation"]
            }
        }
        visible: bookingName !== ""
    }*/

}
