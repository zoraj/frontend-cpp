import QtQuick 2.15
import QtQuick.Controls 2.15
import "qrc:/."

Rectangle {
    property int cashingId
    property string label
    property string iconName
    color: "white"
    Row {
        x: 30
        spacing: P._MARGIN_CONTAINER
        Image {
            source: "qrc:/Assets/Image/Pos/CashingMode/carte.png"
            asynchronous: true
            width: 90; height: 90
            anchors.verticalCenter: parent.verticalCenter
        }
        Text {
            text: label
            font.pointSize: P._STANDARD_FONT_SIZE
            anchors.verticalCenter: parent.verticalCenter
        }
    }
}
