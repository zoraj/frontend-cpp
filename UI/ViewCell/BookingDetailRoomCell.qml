import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.12
import "qrc:/."

Item {
    property string roomType
    property string roomNumber
    property int cellWidth
    property int cellHeight
    Row {
        spacing: P._SPACE_COMPONENT
        Rectangle {
            height: cellHeight; width: 2
            color: roomType === "NON DEFINI" ? "lightcoral" : "steelblue"
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
                text: roomType
                anchors.verticalCenter: parent.verticalCenter; x: P._MARGIN_CONTAINER
            }
        }
        Rectangle {
            height: cellHeight; width: cellWidth * 1 / 3 - 31
            color: gMainWindow.color
            Text {
                text: roomNumber
                anchors.centerIn: parent;
            }
        }
        Rectangle {
            height: cellHeight; width: 30
            color: gMainWindow.color
            Image {
                id: name
                anchors.fill: parent
                fillMode: Image.PreserveAspectFit
                source: "qrc:/Assets/Image/Common/edit-list-icon.png"

            }
        }
    }
}
