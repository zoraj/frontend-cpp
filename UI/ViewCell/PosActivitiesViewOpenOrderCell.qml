import QtQuick 2.15
import QtQuick.Controls 2.15

import "qrc:/."

Item {
    property string numNote
    property string numTable
    property double orderAmout: 0.0
    property int nbCouvert
    property int cellWidth
    property int cellHeight
    Row {
        Rectangle {
            width: 2; height: cellHeight - 4
            color: "red"
        }
        Rectangle {
            width: cellWidth - 64; height: cellHeight - 4
            Row {
                x: P._MARGIN_CONTAINER
                anchors.verticalCenter: parent.verticalCenter;
                Label {
                    text: numTable
                    font.pointSize: P._TITLE_FONT_SIZE
                    width: cellWidth - 164
                }
                Label {
                    text: orderAmout + "€"
                }
            }
        }
        Rectangle {
            width: 22; height: cellHeight - 4
            Image {
                source: "qrc:/Assets/Image/forward.png"
                width: 20; height: 20
                asynchronous: true
                anchors.verticalCenter: parent.verticalCenter
            }
        }
    }
}
