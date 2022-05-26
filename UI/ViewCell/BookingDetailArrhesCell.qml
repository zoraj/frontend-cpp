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
            color: "steelblue"
        }
        Rectangle {
            height: cellHeight; width: cellWidth * 2 / 3 - 41
            color: gMainWindow.color
            Text {
                text: " REPRISES ARRHES "
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
            height: cellHeight; width: 60
            color: gMainWindow.color
            Text {
                text: "X"
                anchors.centerIn: parent;
            }
        }
    }
}
