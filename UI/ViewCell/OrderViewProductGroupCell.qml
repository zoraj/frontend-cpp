import QtQuick 2.15
import QtQuick.Controls 2.15

import "qrc:/."

Rectangle {
    property string groupName: "Bieres et boisson"
    property string imageName: ""
    property int cellWidth: width
    property int cellHeight: height
    color: "white"
    Row {
        spacing: P._SPACE_COMPONENT
        Image {
            source: "qrc:/Assets/Image/Pos/GroupProduct/" + imageName
            asynchronous: true
            width: 60; height: 60
        }
        Label {
            anchors.verticalCenter: parent.verticalCenter; x: P._MARGIN_CONTAINER
            text: groupName
        }
    }
}
