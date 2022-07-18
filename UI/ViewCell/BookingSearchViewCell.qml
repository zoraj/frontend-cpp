import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.12
import "qrc:/."

Rectangle {
    property int bookingId
    property string bookingRef
    property bool isGrouped
    property string bookingName
    property date arrival
    property date departure
    property int nbPax

    color: "white"
    Row {
        spacing: P._SPACE_COMPONENT
        leftPadding: P._MARGIN_COMPONENT; topPadding: P._LISTVIEW_CELL_HEIGHT / 4
        Label {
            text: bookingRef
        }
        Label {
            leftPadding: 50
            text: bookingName
        }
        Label {
            leftPadding: 50
            text: arrival
        }
        Label {
            leftPadding: 50
            text: departure
        }
        Label {
            text: {
                let pers = nbPax < 4 ?  "👤".repeat(nbPax) : "(" + nbPax + ") x👤"
                return pers
            }
        }

        Rectangle {
            width: 100; height: 20
            color: "yellow"
            Text {
                text: "Confirmé"
            }
        }
        Label {
            leftPadding: 50
            text: nbPax + " pers."
        }
        Image {
            x: parent.parent.parent.width - 50
            width: 45; height: 45
            source: "qrc:/Assets/Image/Common/arrow-right-listview.png"
        }

    }
}
