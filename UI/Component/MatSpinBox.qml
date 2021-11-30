import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

SpinBox {
    property string title
    //value: startValue
    editable: true
    width: 150

    Text {
        topPadding: -10
        text: title
        color: "#374866"
    }
}
