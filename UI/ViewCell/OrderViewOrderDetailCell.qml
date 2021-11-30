import QtQuick 2.15
import "qrc:/."

Rectangle {
    property bool isVAE: false
    property bool isOffert: false
    property int qty: 1
    property double total: 0.0
    property string product: ""
    property double up: 0.0
    color: "#f7f9fa"
    Row {
        spacing: P._MARGIN_COMPONENT
        anchors.verticalCenter: parent.verticalCenter
        Text {
            text: qty
            verticalAlignment: Text.AlignVCenter
        }
        Text {
            text: product
            width: 200
            verticalAlignment: Text.AlignVCenter
        }
        Text {
            text: up
            verticalAlignment: Text.AlignVCenter
        }
        Text {
            text: total
            verticalAlignment: Text.AlignVCenter
        }
    }
}

