import QtQuick 2.15
import QtQuick.Controls 2.15
import "qrc:/."
import "qrc:/UI/Component"

import cloud.multimicro.mmc.frontend 1.0

Dialog {
    id: dialog
    property Booking booking: Booking {}

    width: parent.width / 2; height: parent.height
    anchors.centerIn: parent
    modal: true
    title: "Booking"

    function validateButtonClicked() {
        booking.dateArrivee = Date.fromLocaleString(Qt.locale(), arrivalDatePicker.value, "yyyy-MM-dd")
        booking.dateDepart = Date.fromLocaleString(Qt.locale(), departureDatePicker.value, "yyyy-MM-dd")
        booking.nomReservation = nameTextField.text
        booking.nom = nameTextField.text
        booking.nbChambre = nbRoomSpinBox.value
        booking.nbPax = nbPaxSpinBox.value
        booking.nbEnfant = nbChildSpinBox.value
        booking.reservationType = bookingTypeSwitch.checked ? "GROUPE" : "INDIV"
        close()
    }

    function cancelButtonClicked() {
        dialog.width += overBookingListView.width
        overBookingListView.visible = true
        close()
    }

    // UI
    Row {
        x: P._MARGIN_CONTAINER; y: P._MARGIN_CONTAINER
        Column {
            x: P._MARGIN_CONTAINER; y: P._MARGIN_CONTAINER
            spacing: P._MARGIN_CONTAINER
            Row {
                spacing: P._MARGIN_COMPONENT
                MatDatePicker {
                    id: arrivalDatePicker
                    title: "Arrivée le"
                }
                MatSpinBox {
                    id: nbNightSpinBox
                    title: "Nombre de nuité"
                }
            }
            MatDatePicker {
                id: departureDatePicker
                title: "Départ le"
            }
            MatTextField {
                id: nameTextField
                title: "Nom"
                width: parent.width - 50
            }
            Row {
                spacing: P._MARGIN_COMPONENT * 2
                MatSpinBox {
                    id: nbRoomSpinBox
                    title: "Nb chambre"
                }
                MatSpinBox {
                    id: nbPaxSpinBox
                    title: "Nb pax"
                }
            }
            MatSpinBox {
                id: nbChildSpinBox
                title: "Dont enfant"
            }
            Switch {
                id: bookingTypeSwitch
                text: "Réservation Groupée ?"
            }
            Row {
                spacing: P._MARGIN_COMPONENT * 2
                Button {
                    id: headerValidateButton
                    onClicked: validateButtonClicked()
                    text: "Valider"
                }
                Button {
                    id: headerCancelButton
                    onClicked: cancelButtonClicked()
                    text: "Annuler"
                }
            }
        }
        ListView {
            id: overBookingListView
            width: 100; height: parent.height
            delegate: Rectangle {
                width: 100; height: 20
                color: "red"
            }
            model: 10
            visible: false
        }
    }
}
