import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls.Material 2.15
import "qrc:/."
import "qrc:/UI/Component"
import "qrc:/UI/ViewCell"
import "qrc:/UI/Dialog"

Flickable {
    property alias arrivalText: arrivalText
    property alias departureText: departureText
    property alias nameText: nameText
    property alias nbRoomText: nbRoomText
    property alias nbPaxText: nbPaxText
    property alias nbChildText: nbChildText
    property alias rateGridComboBox: rateGridComboBox
    property alias clientComboBox: clientComboBox
    property alias clientTypeComboBox: clientTypeComboBox
    property alias segmentationComboBox: segmentationComboBox
    property alias prescripteurComboBox: prescripteurComboBox
    property alias nationComboBox: nationComboBox
    property alias validateButton: validateButton
    property alias signatureText: signatureText
    property alias obsText: obsText
    property alias ventilationList: ventilationList
    property alias insertArrhesButton: insertArrhesButton
    property alias reloadArrhesButton: reloadArrhesButton
    property alias bookingTypeSwitch: bookingTypeSwitch
    property alias adresse1TextField: adresse1TextField
    property alias adresse2TextField: adresse2TextField
    property alias countryComboBox: countryComboBox
    property alias telTextField: telTextField
    property alias emailTextField: emailTextField
    property alias genreComboBox: genreComboBox
    property alias cpTextField: cpTextField
    property alias cityTextField: cityTextField
    property alias actionTabBar: actionTabBar
    property alias firstNameTextField: firstNameTextField

    /* --- Top left rectangle --- */
    Rectangle {
        id: topLeftRect
        x: P._MARGIN_CONTAINER; y: P._MARGIN_CONTAINER
        width: 400; height: 150
        Row {
            anchors.centerIn: parent
            spacing: P._MARGIN_COMPONENT
            MatDatePickerBooking {
                id: arrivalText
                title: "Arrivée le"
            }
            Column {
                Label {
                    width: 100
                    text: ""
                    font.pixelSize: 25
                    horizontalAlignment: Text.AlignHCenter
                }
                Image {
                    width: 100
                    height: 30
                    source: "qrc:/Assets/Image/forward.png"
                    fillMode: Image.PreserveAspectFit
                    asynchronous: true
                }
            }
            MatDatePickerBooking {
                id: departureText
                title: "Départ le"
            }
        }
    }

    /* --- Top right rectangle --- */
    Rectangle {
        id: topRightRect
        y: P._MARGIN_CONTAINER
        anchors.left: topLeftRect.right; anchors.leftMargin: P._MARGIN_CONTAINER
        width: parent.width - topLeftRect.width - P._MARGIN_CONTAINER * 3; height: topLeftRect.height
        Row {
            id: row1
            x: P._MARGIN_CONTAINER; y: P._MARGIN_CONTAINER
            spacing: P._MARGIN_COMPONENT
            MatTextField {
                id: nameText
                title: "Nom"
                width: 200
                iconAction: "cardex-icon.png"
            }
            MatTextField {
                id: cardexText
                title: "Cardex"
                width: 150
            }
            Button {
                id: validateButton
                width: 100; height: 50
                text: "<font color='#fff'>Valider</font>"
                Material.background: Material.Cyan
            }
        }
        Row {
            x: P._MARGIN_CONTAINER
            anchors.top: row1.bottom; anchors.topMargin: P._MARGIN_CONTAINER
            spacing: P._MARGIN_COMPONENT
            MatTextField {
                id: nbRoomText
                title: "Nb chbre"
                horizontalAlignment: Text.AlignHCenter
                width: 50
            }
            MatTextField {
                id: nbPaxText
                title: "Nb pax"
                horizontalAlignment: Text.AlignHCenter
                width: 50
            }
            MatTextField {
                id: nbChildText
                title: "Dont enf."
                horizontalAlignment: Text.AlignHCenter
                width: 50
            }
            Switch {
                id: bookingTypeSwitch
                text: "Réserv. Groupée ?"
            }

        }
    }
    /* --- Tab bar --- */
    TabBar {
        id: actionTabBar
        width: parent.width
        anchors.top: topRightRect.bottom; anchors.topMargin: P._MARGIN_CONTAINER

        TabButton {
            text: qsTr("Ventilation")
        }
        TabButton {
            text: qsTr("Tarification")
        }
        TabButton {
            text: qsTr("Infos compl.")
        }
        TabButton {
            text: qsTr("Arrhes globales")
        }
    }

    StackLayout {
        id: stackLayout
        x: P._MARGIN_CONTAINER
        width: parent.width - P._MARGIN_CONTAINER * 2 ; height: parent.height - topLeftRect.height - P._MARGIN_CONTAINER * 4 - 50  // This 50 is really strange thing for me
        anchors.top: actionTabBar.bottom; anchors.topMargin: P._MARGIN_CONTAINER
        currentIndex: actionTabBar.currentIndex
        Layout.fillWidth: false
        Layout.fillHeight: false

        /* --- Ventilation - Start --- */
        Rectangle {
            id: ventilationRect
            color: "transparent"
            /* --- ComboxBox Rectangle - Start --- */
            Rectangle {
                id: combosRect
                width: topLeftRect.width; height: parent.height
                Column {
                    spacing: P._MARGIN_COMPONENT
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.topMargin: P._MARGIN_CONTAINER
                    MatComboBox {
                        id: clientComboBox
                        title: "Compte client"
                        textRole: "nom"
                        valueRole: "id"
                        width: combosRect.width - P._MARGIN_CONTAINER * 2
                    }
                    MatComboBox {
                        id: rateGridComboBox
                        title: "Grille tarif"
                        textRole: "nom"
                        valueRole: "id"
                        width: combosRect.width - P._MARGIN_CONTAINER * 2
                    }
                    MatComboBox {
                        id: clientTypeComboBox
                        title: "Type client"
                        textRole: "libelle"
                        valueRole: "id"
                        width: combosRect.width - P._MARGIN_CONTAINER * 2
                    }
                    MatComboBox {
                        id: segmentationComboBox
                        title: "Segmentation"
                        textRole: "libelle"
                        valueRole: "id"
                        width: combosRect.width - P._MARGIN_CONTAINER * 2
                    }
                    MatComboBox {
                        id: prescripteurComboBox
                        title: "Prescripteur"
                        textRole: "libelle"
                        valueRole: "id"
                        width: combosRect.width - P._MARGIN_CONTAINER * 2
                    }
                    MatComboBox {
                        id: nationComboBox
                        title: "Nationalité"
                        textRole: "name"
                        valueRole: "code"
                        width: combosRect.width - P._MARGIN_CONTAINER * 2
                    }
                }
            }
            /* --- ventilation --- */
            Rectangle {
                width: topRightRect.width; height: parent.height
                anchors.left: combosRect.right; anchors.leftMargin: P._MARGIN_CONTAINER
                Text {
                    id: roomRepartitionText
                    x: P._MARGIN_CONTAINER; y: P._MARGIN_CONTAINER
                    text: "Ventilation Type/Chambre"
                }
                ListView {
                    id: ventilationList
                    x: P._MARGIN_CONTAINER;
                    anchors.top: roomRepartitionText.bottom; anchors.topMargin: P._MARGIN_COMPONENT
                    width: parent.width - P._MARGIN_CONTAINER * 2; height: parent.height - 200
                    clip: true
                    spacing: 1
                    //model: _bookingDetailViewController.bookingRoomListModel
                    delegate: BookingDetailRoomCell {
                        roomType: typeChambreLibelle
                        roomNumber: numeroChambre
                        cellWidth: ventilationList.width; cellHeight: 50
                        width: ventilationList.width; height: 52
                        MouseArea {
                            anchors.fill: parent
                            // @disable-check M223
                            onClicked: {
                                // @disable-check M222
                                roomVentilationListSelected(index)
                            }
                        }
                    }
                }
                Row {
                    id: rowSignObs
                    width: parent.width
                    x: P._MARGIN_CONTAINER
                    anchors.top: ventilationList.bottom; anchors.topMargin: P._MARGIN_CONTAINER;
                    spacing: P._MARGIN_CONTAINER
                    MatTextField {
                        id: signatureText
                        width: parent.width / 2 - P._MARGIN_CONTAINER * 3
                        title: "Signature"
                    }
                    MatTextField {
                        id: obsText
                        width: parent.width / 2 - P._MARGIN_CONTAINER * 3
                        title: "Observation"
                    }
                }
            }
        }
        /* --- Tarification - Start --- */
        Rectangle {
            id: tarifRect
            Row {
                id: titleMasterListRow
                x: P._MARGIN_CONTAINER; y:  P._MARGIN_CONTAINER;
                spacing: 10
                Text {
                    text: qsTr("Nb Chb")
                }
                Text {
                    text: qsTr("Type chb")
                }
                Text {
                    text: qsTr("# Chb")
                }
                Text {
                    text: qsTr("Adult.")
                }
                Text {
                    text: qsTr("Enf.")
                }
                Text {
                    text: qsTr("Tarif")
                }
                Text {
                    text: qsTr("Base")
                }
                Text {
                    text: qsTr("Montant")
                }
            }

            ListView {
                id: rateMasterList
                x: P._MARGIN_CONTAINER; y:  P._MARGIN_CONTAINER;
                width: parent.width - P._MARGIN_CONTAINER * 2; height: parent.height / 2;
                clip: true
                model: 20
                anchors.top: titleMasterListRow.bottom; anchors.topMargin: P._MARGIN_CONTAINER
                delegate: BookingDetailRateMasterCell {
                    //roomType: typeChambreLibelle
                    //roomNumber: numeroChambre
                    cellWidth: ventilationList.width; cellHeight: 50
                    width: ventilationList.width; height: 52
                    MouseArea {
                        anchors.fill: parent
                        // @disable-check M223
                        onClicked: {
                            // @disable-check M222
                            rateMasterListSelected(index)
                        }
                    }
                }
            }

            Row {
                id: titleDetailListRow
                x: P._MARGIN_CONTAINER;
                anchors.top: rateMasterList.bottom; anchors.topMargin: P._MARGIN_CONTAINER
                spacing: 1
                Text {
                    text: qsTr("Prestation")
                }
                Text {
                    text: qsTr("Qte")
                }
                Text {
                    text: qsTr("P.U")
                }
                Text {
                    text: qsTr("Remise")
                }
                Text {
                    text: qsTr("Promot.")
                }
                Text {
                    text: qsTr("Commis.")
                }
                Text {
                    text: qsTr("Early Book")
                }
                Text {
                    text: qsTr("O-N-G")
                }
                Text {
                    text: qsTr("Extra")
                }
                Text {
                    text: qsTr("REC.")
                }
                Text {
                    text: qsTr("Total")
                }
            }
            ListView {
                id: rateDetailList
                x: P._MARGIN_CONTAINER;
                anchors.top: titleDetailListRow.bottom
                width: parent.width - P._MARGIN_CONTAINER * 2; height: parent.height - titleMasterListRow.height - rateMasterList.height - titleDetailListRow.height - P._MARGIN_CONTAINER * 4 ;
                clip: true
                model: 20
                delegate: BookingDetailRateMasterCell {
                    //roomType: typeChambreLibelle
                    //roomNumber: numeroChambre
                    cellWidth: ventilationList.width; cellHeight: 50
                    width: ventilationList.width; height: 52
                    MouseArea {
                        anchors.fill: parent
                        // @disable-check M223
                        onClicked: {
                            // @disable-check M222
                            rateDetailListSelected(index)
                        }
                    }
                }
            }
        }
        Rectangle {
            id: infosComplRect
            color: "transparent"
            /* --- Payment Rectangle - Start --- */
            Rectangle {
                id: paymentRect
                width: topLeftRect.width; height: parent.height
                Column {
                    spacing: P._MARGIN_COMPONENT
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.topMargin: P._MARGIN_CONTAINER
                    MatComboBox {
                        id: cardComboBox
                        title: "CB"
                        model: ["Nationale", "Visa", "Master Card", "American Express", "Diners Club", "Discover", "Autre"]
                        width: paymentRect.width - P._MARGIN_CONTAINER * 2
                    }
                    MatTextField {
                        title: "N°"
                        width: paymentRect.width - P._MARGIN_CONTAINER * 2
                    }
                    MatTextField {
                        title: "Expire fin"
                        width: combosRect.width - P._MARGIN_CONTAINER * 2
                    }
                    MatTextField {
                        title: "Titulaire"
                        width: combosRect.width - P._MARGIN_CONTAINER * 2
                    }
                }
            }
            /* --- Payment Rectangle - End --- */
            /* --- Personal Data - Start --- */
            Rectangle {
                id: personalDataRect
                width: topRightRect.width; height: parent.height
                anchors.left: paymentRect.right; anchors.leftMargin: P._MARGIN_CONTAINER
                Column {
                    spacing: P._MARGIN_COMPONENT
                    x: P._MARGIN_CONTAINER; y: P._MARGIN_CONTAINER
                    Row {
                        spacing: P._MARGIN_COMPONENT
                        MatComboBox {
                            id: genreComboBox
                            title: "Genre"
                            model: ["MR", "MME", "MME", "STE", "."]
                        }
                        MatTextField {
                            title: "Nom"
                            id: nameTextField
                            width: personalDataRect.width - genreComboBox.width - P._MARGIN_CONTAINER * 3
                        }
                    }
                    MatTextField {
                        id: firstNameTextField
                        title: "Prénom"
                        width: personalDataRect.width - P._MARGIN_CONTAINER * 2
                    }

                    Row {
                        spacing: P._MARGIN_COMPONENT
                        MatTextField {
                            id: adresse1TextField
                            title: "Adresse"
                            width: personalDataRect.width / 2 - P._MARGIN_CONTAINER * 3
                        }
                        MatTextField {
                            id: adresse2TextField
                            title: ""
                            width: personalDataRect.width / 2 - P._MARGIN_CONTAINER * 3
                        }
                    }

                    Row {
                        spacing: P._MARGIN_COMPONENT
                        MatTextField {
                            id: cpTextField
                            title: "CP"
                            width: genreComboBox.width
                        }
                        MatTextField {
                            id: cityTextField
                            title: "Ville"
                            width: nameTextField.width
                        }
                    }
                    MatComboBox {
                        id: countryComboBox
                        title: "Pays"
                        textRole: "name"
                        valueRole: "code"
                        width: personalDataRect.width - P._MARGIN_CONTAINER * 2
                    }

                    Row {
                        spacing: P._MARGIN_COMPONENT
                        MatTextField {
                            id: telTextField
                            title: "Tél"
                            width: personalDataRect.width / 2 - P._MARGIN_CONTAINER * 3
                        }
                        MatTextField {
                            id: emailTextField
                            title: "Mail"
                            width: personalDataRect.width / 2 - P._MARGIN_CONTAINER * 3
                        }
                    }
                }
            }
        }
        Rectangle {
            id: arrhesRect
            ListView {
                id: arrhesList
                x: P._MARGIN_CONTAINER; y: P._MARGIN_CONTAINER
                width: parent.width - P._MARGIN_CONTAINER * 2; height: parent.height - 100
                clip: true
                spacing: 1
                model: 20
                delegate: BookingDetailArrhesCell {
                    //roomType: typeChambreLibelle
                    //roomNumber: numeroChambre
                    cellWidth: arrhesList.width; cellHeight: 50
                    width: arrhesList.width; height: 52
                    MouseArea {
                        anchors.fill: parent
                        // @disable-check M223
                        onClicked: {
                            // disable-check M222
                            //roomVentilationListSelected(index)
                        }
                    }
                }
            }
            Row {
                x: P._MARGIN_CONTAINER
                width: parent.width
                spacing: P._MARGIN_COMPONENT
                anchors.top: arrhesList.bottom; anchors.topMargin: P._MARGIN_CONTAINER
                Button {
                    id: insertArrhesButton
                    width: 100; height: 50
                    text: "<font color='#fff'>Insérer</font>"
                    Material.background: Material.Cyan
                }
                Button {
                    id: reloadArrhesButton
                    width: 100; height: 50
                    text: "Reprendre"
                }
            }

        }
    }

    /* --- Tarification Rectangle --- */
}
