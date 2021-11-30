import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Controls.Material 2.15
import "qrc:/."

Button {
    property int numTable
    property bool isAvail
    property int nbCouvert
    property int orderId

    property int cellWidth
    property int cellHeight
    highlighted: true
    Material.background: orderId === -1 ? Material.Cyan :  Material.BlueGrey // Material.Cyan : Material.BlueGrey
    width: cellWidth
    height: cellHeight
    text: numTable
    font.pointSize: P._TITLE_FONT_SIZE
}
