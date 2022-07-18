import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

TextField {
    id: textField
    property string title
    property bool isMandatory: false
    property int textWidth: 200

    Layout.preferredWidth: textWidth
    color: "#364764"
    font.pointSize: 11

    Text {
        topPadding: -10
        text: title
        color: "#374866" //"#06a8c4"
    }

    Button {
        x: parent.width - 45 ; y: -10
        visible: textField.text !== ""
        width: 40
        height: 40
        icon.source: "qrc:/Assets/Image/Common/textfield-reset-action-icon.png"
        icon.color: "transparent"
        icon.width: 40
        icon.height: 40
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
            textField.clear()
        }
    }
}
