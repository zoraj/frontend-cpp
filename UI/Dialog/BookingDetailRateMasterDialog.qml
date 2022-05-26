import QtQuick 2.15
import QtQuick.Controls 2.15
import "qrc:/."
import "qrc:/UI/Component"

Dialog {
    width: parent.width / 2; height: parent.height / 2
    anchors.centerIn: parent
    modal: true
    title: "Tarif"
    standardButtons: Dialog.Ok | Dialog.Cancel

    /* Business Logic */
    onAccepted: {

    }

    onRejected: {

    }

    /* UI Logic */
    Column {
        anchors.centerIn: parent
        spacing: P._MARGIN_COMPONENT

        Text {
            id: name
            text: qsTr("Type de chambre - #201")
        }
        MatTextField {
            title: "Nom"
        }
        MatTextField {
            title: "Adulte"
        }
        MatTextField {
            title: "Enfant"
        }
        MatDatePicker {
            title: "Début (inclus)"
        }
        MatDatePicker {
            title: "Fin (inclus)"
        }

    }
}
