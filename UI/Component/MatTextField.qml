import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

TextField {
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
}
