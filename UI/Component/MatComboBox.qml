import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
/*
ColumnLayout {
    property string title
    property int textWidth: 200
    property var comboBoxModel
    property string role
    property int  currentIndex: comboBox.currentIndex

    implicitHeight: 200
    implicitWidth: 200
    Text {
        text: title
        color: "#374866" //"#06a8c4"
    }
    ComboBox {
        editable: true
        id: comboBox
        Layout.preferredWidth: textWidth
        model: comboBoxModel
        textRole: role
    }
}

*/


ComboBox {
    property string title
    property int textWidth: 200
    property string role
    //property int  currentIndex: comboBox.currentIndex

    editable: true
    Layout.preferredWidth: 200
    textRole: role

    Text {
        text: title
        color: "#374866" //"#06a8c4"
    }
}
