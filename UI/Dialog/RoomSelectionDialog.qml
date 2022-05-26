import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Window 2.15
import "qrc:/."
import "qrc:/UI/Component"

Dialog {
    id: dialog
    width: parent.width / 2
    height: parent.height / 2
    x: (parent.width - width) / 2
    y: (parent.height - height) / 2
    property int roomRepartitionIndex: 0

    modal: true
    title: "Sélection chambre"
    standardButtons: Dialog.Ok | Dialog.Cancel

    /* Business Logic */
    Connections {
        target: _bookingDetailViewController
    }

    Component.onCompleted: {

    }

    onAccepted: {
        console.log("roomCombo.currentValue:" + roomCombo.currentValue)
        _bookingDetailViewController.roomSelectionDialogValidate_Clicked(roomTypeCombo.currentValue, roomCombo.currentValue, roomRepartitionIndex)
    }
    onRejected: {
        //
    }

    /* UI Logic */
    Column {
        anchors.centerIn: parent
        spacing: P._MARGIN_COMPONENT
        MatComboBox {
            id: roomTypeCombo
            title: "Type"
            width: dialog.width - P._MARGIN_CONTAINER * 2
            model: _bookingDetailViewController.roomTypeListModel
            textRole: "libelle"
            valueRole: "id"
            onCurrentIndexChanged: {
                _bookingDetailViewController.roomTypeComboBoxChanged(currentIndex)
            }
        }
        MatComboBox {
            id: roomCombo
            title: "Numéro"
            width: dialog.width - P._MARGIN_CONTAINER * 2
            model: _bookingDetailViewController.roomListProxyModel
            textRole: "numeroChambre"
            valueRole: "_id"
        }
    }
}
