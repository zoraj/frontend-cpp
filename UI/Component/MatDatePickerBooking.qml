import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

ColumnLayout {
    property string title
    property bool isMandatory: false
    property int textWidth: 120
    property string value

    implicitHeight: 200
    implicitWidth: 200

    Text {
        text: title
        color: "#364764"
    }
    RowLayout {
        TextField {
            id: textField
            Layout.preferredWidth: textWidth
            placeholderText: "jj/MM/AAAA"
            horizontalAlignment: Text.AlignLeft
            color: "#364764"
            font.pointSize: 11
            text: value
            Button {
                x: 85; y: -10
                width: 45
                height: 45
                icon.source: "qrc:/Assets/Image/Common/calendar-icon.png"
                icon.color: "transparent"
                icon.width: 45
                icon.height: 45
                padding: {
                    left: 0
                    right: 0
                    top: 0
                    bottom: 0
                }

                background: Rectangle {
                    implicitWidth: 40
                    implicitHeight: 40
                    border.width: 0
                }
                onClicked: {
                    gDatepickerBookingDialog.open()
                }
            }
        }
    }
}

