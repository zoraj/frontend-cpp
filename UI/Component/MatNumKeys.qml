import QtQuick 2.15
import QtQuick.Controls 2.15

Column {
    property string value: valueText.text

    function clear() {
        valueText.clear()
    }

    MatTextField {
        id: valueText
        maximumLength: 9
        anchors.horizontalCenter: parent.horizontalCenter
        horizontalAlignment: Text.AlignHCenter
        font.pointSize: 16
    }
    Column {
        Row {
            spacing: 1
            Button {
                text: "1"
                onClicked: valueText.text += "1"

            }
            Button {
                text: "2"
                onClicked: valueText.text += "2"
            }
            Button {
                text: "3"
                onClicked: valueText.text += "3"
            }
        }
        Row {
            spacing: 1
            Button {
                text: "4"
                onClicked: valueText.text += "4"
            }
            Button {
                text: "5"
                onClicked: valueText.text += "5"
            }
            Button {
                text: "6"
                onClicked: valueText.text += "6"
            }
        }
        Row {
            spacing: 1
            Button {
                text: "7"
                onClicked: valueText.text += "7"
            }
            Button {
                text: "8"
                onClicked: valueText.text += "8"
            }
            Button {
                text: "9"
                onClicked: valueText.text += "9"
            }
        }
        Row {
            spacing: 1
            Button {
                text: "0"
                onClicked:
                    if (valueText.length > 0)
                        valueText.text += "0"

            }
            Button {
                text: "."
            }
            Button {
                text: "C"
                onClicked: valueText.clear()
            }
        }
    }
}
