import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.12
import QtGraphicalEffects 1.12

Flickable {
    contentHeight: mainRectangle.height
    flickableDirection: Flickable.AutoFlickIfNeeded
    // Main Rectangle
    property alias t0: t0
    property alias t1: t1
    property alias t2: t2
    property alias t3: t3
    property alias t4: t4
    property alias t5: t5
    property alias resultText: resultText

    RectangularGlow {
        anchors.fill: mainRectangle
        glowRadius: 15
        spread: 0.1
        color: "lightsteelblue"
        cornerRadius: mainRectangle.radius + glowRadius
    }
    Rectangle {
        id: mainRectangle
        color: "white"
        width: gMainWindow.width
        height: 300
        clip: true
        radius: 2
        anchors.horizontalCenter: parent.horizontalCenter
        y: gMainWindow.height / 2 - mainRectangle.height / 2
        Label {
            anchors.horizontalCenter: parent.horizontalCenter
            text: "Saisissez le code reçu par email"
            font.pointSize: 24
            y: 10
        }

        Row {
            spacing: 20
            //anchors.horizontalCenter: parent.horizontalCenter
            anchors.centerIn: parent
            TextField {
                id: t0
                width: 80
                height: 80
                horizontalAlignment: Text.AlignHCenter
                font.pointSize: 32
                validator: IntValidator {
                    bottom: 0
                    top: 9
                }
            }
            TextField {
                id: t1
                width: 80
                height: 80
                horizontalAlignment: Text.AlignHCenter
                font.pointSize: 32
                validator: IntValidator {
                    bottom: 0
                    top: 9
                }
            }
            TextField {
                id: t2
                width: 80
                height: 80
                horizontalAlignment: Text.AlignHCenter
                font.pointSize: 32
                validator: IntValidator {
                    bottom: 0
                    top: 9
                }
            }
            TextField {
                id: t3
                width: 80
                height: 80
                horizontalAlignment: Text.AlignHCenter
                font.pointSize: 32
                validator: IntValidator {
                    bottom: 0
                    top: 9
                }
            }
            TextField {
                id: t4
                width: 80
                height: 80
                horizontalAlignment: Text.AlignHCenter
                font.pointSize: 32
                validator: IntValidator {
                    bottom: 0
                    top: 9
                }
            }
            TextField {
                id: t5
                width: 80
                height: 80
                horizontalAlignment: Text.AlignHCenter
                font.pointSize: 32
                validator: IntValidator {
                    bottom: 0
                    top: 9
                }
            }
            Text {
                id: resultText
                width: 80
                height: 80
                opacity: 0
                text: "✓"
                font.pointSize: 40
                color: "#06a8c4"
            }

        }
    }
}
