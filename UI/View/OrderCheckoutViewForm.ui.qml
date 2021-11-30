import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls.Material 2.15

import "qrc:/."
import "qrc:/UI/ViewCell"
import "qrc:/UI/Component"

Flickable {
    property alias cashingModeGrid: cashingModeGrid
    property alias orderDetailListView: orderDetailListView
    property alias checkoutListView: checkoutListView
    property alias validateButton: validateButton
    property alias numKeys: numKeys
    property alias totalRecapCheckoutLabel: totalRecapCheckoutLabel

    /* --- Order List Rectangle --- */
    Rectangle {
        id: leftRect
        x: P._MARGIN_CONTAINER; y: P._MARGIN_CONTAINER
        width: parent.width / 3 ; height: parent.height - P._MARGIN_CONTAINER * 2
        Column {
            x: P._MARGIN_CONTAINER; y: P._MARGIN_CONTAINER
            spacing: P._MARGIN_COMPONENT
            MatSeparator {
                width: leftRect.width - P._MARGIN_CONTAINER * 2
            }
            Row {
                spacing: P._MARGIN_COMPONENT
                Label {
                    text: "Qte"
                }
                Label {
                    text: "Prestation"
                }
                Label {
                    text: "PU"
                }
                Label {
                    text: "Total"
                }
            }
            MatSeparator {
                width: leftRect.width - P._MARGIN_CONTAINER * 2
            }
            ListView {
                id: orderDetailListView
                width: leftRect.width  - P._MARGIN_CONTAINER * 2; height: leftRect.height - 250
                clip: true
                spacing: P._SPACE_COMPONENT
                delegate: OrderViewOrderDetailCell {
                    width: orderDetailListView.width; height: 50
                    qty: qte
                    product: prestationLibelle
                    isVAE: isVAE
                    isOffert: isOffert
                    total: totalLine
                    up: pu
                }
            }
            MatSeparator {
                width: leftRect.width - P._MARGIN_CONTAINER * 2
            }
            Row {
                Text {
                    text: "Sous total"
                }
                Text {
                    text: "Remise"
                }
                Text {
                    text: "Total Net TTC"
                }
            }
            MatSeparator {
                width: leftRect.width - P._MARGIN_CONTAINER * 2
            }
            Row {
                spacing: P._MARGIN_COMPONENT
                Column {
                    spacing: P._SPACE_COMPONENT
                    Button {
                        id: offerButton
                        width: (leftRect.width / 3) - (P._SPACE_COMPONENT * 4) - P._MARGIN_CONTAINER
                        Material.background: Material.DeepOrange
                        highlighted: true
                        text: "Offert"
                    }
                    Button {
                        width: offerButton.width
                        text: "Division"
                    }
                }
                Column {
                    spacing: P._SPACE_COMPONENT
                    Button {
                        width: offerButton.width
                        text: "Ticket"
                    }
                    Button {
                        width: offerButton.width
                        text: "Facture"
                    }
                }
                Button {
                    width: offerButton.width; height: 100
                    id: validateButton
                    text: "Valider"
                    highlighted: true
                    Material.background: Material.Green

                }
            }
        }
    }
    /* --- List of cashing mode rectangle --- */
    Rectangle {
        id: rightRect
        color: "transparent"
        width: parent.width - leftRect.width - P._MARGIN_CONTAINER * 3; height: parent.height - P._MARGIN_CONTAINER * 2
        anchors.left: leftRect.right; anchors.top: leftRect.top; anchors.leftMargin: P._MARGIN_CONTAINER
        Column {
            spacing: P._MARGIN_CONTAINER
            GridView { /* Cash mode Grid */
                id: cashingModeGrid
                width: rightRect.width; height: rightRect.height - 300
                cellHeight: 100; cellWidth: rightRect.width / 2
                clip: true
                delegate: OrderCheckoutCashingModeCell {
                    cashingId: _id
                    label: libelle
                    height: 96
                    width: (rightRect.width / 2) - P._SPACE_COMPONENT
                    MouseArea {
                        anchors.fill: parent
                        // @disable-check M223
                        onClicked: {
                            // @disable-check M222
                            cashingModeSelected(_id, numKeys.value)
                        }
                    }
                }
            }
            Row {
                spacing: P._MARGIN_CONTAINER
                Column {
                    spacing: P._MARGIN_CONTAINER
                    Label {
                        text: "Récapitulation encaissement"
                    }

                    /* --- List of checkout --- */
                    ListView {
                        id: checkoutListView
                        width: rightRect.width - 250; height: 200
                        clip: true
                        spacing: P._SPACE_COMPONENT
                        delegate: Rectangle {
                            width: checkoutListView.width; height: 50
                            Row {
                                anchors.verticalCenter: parent.verticalCenter
                                Label {
                                    x: P._MARGIN_CONTAINER
                                    width: checkoutListView.width - 50
                                    text: encaiss_lib
                                }
                                Label {
                                    text: montant + "€"
                                }
                            }
                        }
                    }
                    Row {
                        spacing: P._MARGIN_CONTAINER
                        Label {
                            text: "Total : "
                        }
                        Label {
                            id: totalRecapCheckoutLabel
                            text: "0.00€"
                        }
                    }
                }

                MatNumKeys {
                    id: numKeys
                }
            }
        }
    }
}
