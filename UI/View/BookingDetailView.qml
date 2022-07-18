import QtQuick 2.15
import QtQml 2.15
import "qrc:/UI/Script/Countries.js" as CountryJS
import "qrc:/UI/Dialog"

import cloud.mat.frontend 1.0

BookingDetailViewForm {
    property Booking booking: Booking {}
    property Component roomSelectionDialogComponent
    Connections {
            target: _bookingDetailViewController
            function onViewDidLoadFinished() {
                rateGridComboBox.model = _bookingDetailViewController.rateGridListModel
                clientComboBox.model = _bookingDetailViewController.clientListModel_
                clientTypeComboBox.model = _bookingDetailViewController.clientTypeListModel
                segmentationComboBox.model = _bookingDetailViewController.segmentationListModel
                prescripteurComboBox.model = _bookingDetailViewController.prescripteurListModel
                //roomTypeComboBox.model = _bookingDetailViewController.roomTypeListModel
                nationComboBox.model = CountryJS.getCountries();
                countryComboBox.model = CountryJS.getCountries();
            }

            function onBookingChanged(bookingData) {
                /*booking = bookingData

                // Show it visually
                arrivalText.text = bookingData.dateArrivee.toLocaleDateString(Qt.locale(), "ddd d MMM yy")
                departureText.text = bookingData.dateDepart.toLocaleDateString(Qt.locale(), "ddd d MMM yy")
                nameText.text = bookingData.nomReservation
                nbRoomText.text = bookingData.nbChambre
                nbPaxText.text = bookingData.nbPax
                nbChildText.text = bookingData.nbEnfant


                //gViewTitle = "Réservation N° : " + bookingData.numeroReservation*/

                // Room repartition
                //ventilationList.model = _bookingDetailViewController.bookingRoomListModel
                //ventillationList.forceLayout()
            }

            function onSubmitBookingDataFinished(result, pBooking) {
                //if (result && bookingId !== -1) {
                booking = pBooking
                if (result) {
                    console.log("Numero:" + booking.numeroReservation)
                    gViewTitle = "Réservation N° : " + booking.numeroReservation
                    //booking.id = bookingId
                    gMainToast.start("Réservation enregistrée avec succès")
                }
                else {
                    gMainToast.start("Une erreur s'est produite lors de l'enregistrement de la réservation")
                }
            }
        }

    // START - Booking Room Selection Dialog
    function roomVentilationListSelected(index) {
        let roomSelectionDialog = roomSelectionDialogComponent.createObject(parent,{popupType: 1, roomRepartitionIndex: index});
        roomSelectionDialog.open()
    }
    // END - Booking Room Selection Dialog

    // Rate Master Selection Dialog - Start
    BookingDetailRateMasterDialog {
        id: bookingDetailRateMasterDialog
    }

    function rateMasterListSelected(index) {
        bookingDetailRateMasterDialog.open()
    }

    // Rate Master Selection Dialog - End

    // Rate Detail Selection Dialog - Start
    BookingDetailRateDetailDialog {
        id: bookingDetailRateDetailDialog
    }

    function rateDetailListSelected(index) {
        bookingDetailRateDetailDialog.open()
    }
    // Rate Detail Selection Dialog - Start

    // Arrhes Insertion Dialog - Start
    BookingDetailArrhesInsertDialog {
        id: bookingDetailArrhesInsertDialog
    }
    // Arrhes Insertion Dialog - End

    // Arrhes Reload Dialog - Start
    BookingDetailArrhesReloadDialog {
        id: bookingDetailArrhesReloadDialog
    }
    // Arrhes Insertion Dialog - End

    Component.onCompleted: {
        gCurrentVisibleScreen = "SCREEN_BOOKING_DETAIL"
        gFooterTabBar.visible = false
        _bookingDetailViewController.viewDidLoad()
        roomSelectionDialogComponent = Qt.createComponent("qrc:/UI/Dialog/RoomSelectionDialog.qml");
        gViewTitle = "Nouvelle réservation"

        gDatepickerBookingDialog.arrivalCaller = arrivalText
        gDatepickerBookingDialog.departureCaller = departureText

        ventilationList.model = _bookingDetailViewController.bookingRoomListModel
    }

    Component.onDestruction: {
        gFooterTabBar.visible = true
    }

    validateButton.onClicked: {
        // First tab - Ventilation
        let dateArrivee = Date.fromLocaleString(Qt.locale(), arrivalText.value, "dd/MM/yyyy")
        let dateDepart = Date.fromLocaleString(Qt.locale(), departureText.value, "dd/MM/yyyy")
        booking.dateArrivee = dateArrivee
        booking.dateDepart = dateDepart
        booking.mmcClientId = clientComboBox.valueAt(clientComboBox.currentIndex)
        booking.mmcSegmentClientId = segmentationComboBox.valueAt(segmentationComboBox.currentIndex)
        booking.mmcTypeClientId = clientTypeComboBox.valueAt(clientTypeComboBox.currentIndex)
        booking.nationalite = nationComboBox.valueAt(nationComboBox.currentIndex)
        booking.nbChambre = nbRoomText.text
        booking.nbEnfant = nbChildText.text
        booking.nbPax = nbPaxText.text
        booking.nom = nameText.text
        booking.nomReservation = nameText.text
        booking.pmsPrescripteurId = prescripteurComboBox.valueAt(prescripteurComboBox.currentIndex)
        booking.pmsTarifGrilleId = rateGridComboBox.valueAt(rateGridComboBox.currentIndex)
        booking.signature = signatureText.text
        booking.observation = obsText.text
        booking.reservationType = bookingTypeSwitch.checked ? "GROUPE" : "INDIV"

        // Second tab - Tarification

        // Third tab - Infos Compl.
        booking.civilite = genreComboBox.valueAt(genreComboBox.currentIndex)
        booking.adresse1 = adresse1TextField.text
        booking.adresse2 = adresse2TextField.text
        booking.cp = cpTextField.text
        booking.ville = cityTextField.text
        booking.pays = countryComboBox.valueAt(countryComboBox.currentIndex)
        booking.tel = telTextField.text
        booking.email = emailTextField.text
        booking.prenom = firstNameTextField.text

        _bookingDetailViewController.setBooking(booking)
        _bookingDetailViewController.validateButton_Clicked(actionTabBar.currentIndex)
    }
}
