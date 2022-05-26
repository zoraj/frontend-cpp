import QtQuick 2.15
import "qrc:/."

Item {
    property int cellWidth
    property int cellHeight
    Row {
        spacing: P._SPACE_COMPONENT
        Rectangle {
            height: cellHeight; width: 2
            color: "red"
        }
        Rectangle {
            height: cellHeight; width: 40
            color: gMainWindow.color
            Text {
                text: " 1 "
                anchors.centerIn: parent
            }
        }
        Rectangle {
            height: cellHeight; width: cellWidth * 2 / 3 - 41
            color: gMainWindow.color
            Text {
                text: "roomType"
                anchors.verticalCenter: parent.verticalCenter; x: P._MARGIN_CONTAINER
            }
        }
        Rectangle {
            height: cellHeight; width: cellWidth * 1 / 3 - 31
            color: gMainWindow.color
            Text {
                text: "roomNumber"
                anchors.centerIn: parent;
            }
        }
        Rectangle {
            height: cellHeight; width: 30
            color: gMainWindow.color
            Text {
                text: "..."
                anchors.centerIn: parent;
            }
        }
    }
}
