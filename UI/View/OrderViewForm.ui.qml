import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls.Material 2.15

import "qrc:/."
import "qrc:/UI/Component"
import "qrc:/UI/ViewCell"

Flickable {
    property alias checkoutButton: checkoutButton
    property alias productSearchButton: productSearchButton
    property alias topUpButton: topUpButton
    property alias quitButton: quitButton
    property alias nTableText: nTableText
    property alias ticketButton: ticketButton
    property alias invoiceButton: invoiceButton
    property alias nbCouvertText: nbCouvertText
    property alias groupProductListView: groupProductListView
    property alias orderDetailListView: orderDetailListView
    property alias productGrid: productGrid
    property alias numKeys: numKeys
    property alias grossTotalText: grossTotalText
    property alias vatTotalText: vatTotalText
    property alias netTotalText: netTotalText

    /* --- Header Note + Detail Order Rectangle --- */
    Rectangle {
        id: leftRect
        x: P._MARGIN_CONTAINER; y: P._MARGIN_CONTAINER
        width: 300; height: parent.height - P._MARGIN_CONTAINER * 2
        Column {
            x: P._MARGIN_CONTAINER; y: P._MARGIN_CONTAINER
            spacing: P._MARGIN_COMPONENT
            Row {
                spacing: P._MARGIN_COMPONENT
                MatTextField {
                    id: nTableText
                    title: "N° Table"
                    horizontalAlignment: Text.AlignHCenter
                }
                MatSpinBox {
                    id: nbCouvertText
                    title: "Nb Couvert"
                }
            }
            Row {
                spacing: P._MARGIN_COMPONENT
                MatTextField {
                    title: "% Remise"
                    horizontalAlignment: Text.AlignHCenter
                }
                MatTextField {
                    title: "€ Remise"
                    horizontalAlignment: Text.AlignHCenter
                }
            }
            Row {
                spacing: P._MARGIN_COMPONENT
                MatTextField {
                    title: "Cpte PEC"
                    horizontalAlignment: Text.AlignHCenter
                }
                MatTextField {
                    title: "N° Chambre"
                    horizontalAlignment: Text.AlignHCenter
                }
            }
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
                    text: "Rem."
                }
                Label {
                    text: "Total"
                }
            }
            MatSeparator {
                width: leftRect.width - P._MARGIN_CONTAINER * 2
            }

            /* --- List view of order detail --- */
            ListView {
                id: orderDetailListView
                width: leftRect.width; height: leftRect.height - 450
                clip: true
                spacing: P._SPACE_COMPONENT
                delegate: OrderViewOrderDetailCell {
                    width: orderDetailListView.width - P._MARGIN_CONTAINER * 2; height: 50
                    qty: qte
                    product: prestationLibelle
                    isVAE: isVAE
                    isOffert: isOffert
                    total: totalLine
                    up: pu
                    opacity: .8
                    radius: 5
                    MouseArea {
                        z: 1
                        hoverEnabled: false
                        anchors.fill: parent
                        // @disable-check M223
                        onClicked: {
                            // @disable-check M222
                            detailOrderSelected(prestationId)
                            orderDetailListView.currentIndex = index
                        }
                    }
                }
                highlight: Rectangle {
                    width: orderDetailListView.width - P._MARGIN_CONTAINER * 2; height: 50
                    color: "#06a8c4"
                    radius: 5
                }
            }
            MatSeparator {
                width: leftRect.width - P._MARGIN_CONTAINER * 2
            }
            Row {
                Text {
                    text: qsTr("Total")
                }
                Text {
                    id: grossTotalText
                    width: leftRect.width
                    text: "0.00€"
                    horizontalAlignment: Text.Right
                }
            }
            Row {
                Text {
                    text: qsTr("TVA")
                }
                Text {
                    id: vatTotalText
                    width: leftRect.width
                    text: "0.00€"
                    horizontalAlignment: Text.Right
                }
            }
            Row {
                Text {
                    text: qsTr("Net")
                    font.pointSize: P._SUBTITLE_FONT_SIZE
                }
                Text {
                    id: netTotalText
                    width: leftRect.width
                    text: "0.00€"
                    horizontalAlignment: Text.Right
                    font.pointSize: P._SUBTITLE_FONT_SIZE
                }
            }
            MatSeparator {
                width: leftRect.width - P._MARGIN_CONTAINER * 2
            }
            Row {
                spacing: P._MARGIN_COMPONENT
                Column {
                    spacing: P._MARGIN_COMPONENT
                    Button {
                        id: invoiceButton
                        width: 100
                        text: "Facture"
                    }
                    Button {
                        id: ticketButton
                        width: 100
                        text: "Ticket"
                    }
                }
                Button {
                    id: checkoutButton
                    width: 160; height: 110
                    text: "ENCAISSER"
                    highlighted: true
                    Material.background: Material.Green
                }
            }
        }
    }
    /* --- Product Grid --- */
    Rectangle {
        id: centerRect
        width: parent.width - leftRect.width - P._MARGIN_CONTAINER * 4 - rightRect.width; height: parent.height - P._MARGIN_CONTAINER * 2
        anchors.left: leftRect.right; anchors.top: leftRect.top; anchors.leftMargin: P._MARGIN_CONTAINER
        Column {
            GridView { /* Product Grid */
                id: productGrid
                width: centerRect.width
                height: centerRect.height - 200
                clip: true
                cellHeight: 120
                cellWidth: 120
                delegate: OrderViewProductCell {
                    text: libelle
                    productId: _id
                    color: couleur
                    // @disable-check M223
                    onClicked: {
                        // @disable-check M222
                        productCellSelected(productId)
                    }
                }
            }
            Row {
                spacing: P._MARGIN_COMPONENT
                Button {
                    width: 120; height: 80
                    id: productSearchButton
                    text: "Liste \nPrestation"
                    highlighted: true
                    Material.background: Material.Purple
                }
                Button {
                    width: 120; height: 80
                    text: "Commande"
                }
                Button {
                    width: 120; height: 80
                    id: topUpButton
                    text: "Garniture"
                }
            }
            Row {
                spacing: P._MARGIN_COMPONENT
                Button {
                    width: 160; height: 80
                    text: "QUITTER"
                    id: quitButton
                    highlighted: true
                    Material.background: Material.Pink
                }
                Button {
                    text: "-"
                    visible: false
                }
                Button {
                    text: "-"
                    visible: false
                }
            }
        }
    }
    /* --- Group product Rectangle Container --- */
    Rectangle {
        id: rightRect
        color: "transparent"
        width: 200; height: parent.height - P._MARGIN_CONTAINER * 2
        anchors.left: centerRect.right; anchors.top: centerRect.top; anchors.leftMargin: P._MARGIN_CONTAINER
        Column {
            spacing: P._MARGIN_CONTAINER
            ListView {
                id: groupProductListView
                width: rightRect.width; height: rightRect.height - 300
                clip: true
                spacing: 5
                delegate: OrderViewProductGroupCell {
                    groupName: libelle
                    imageName: iconeImg
                    width: groupProductListView.width ; height: 60
                    MouseArea {
                        anchors.fill: parent
                        // @disable-check M223
                        onClicked: {
                            // @disable-check M222
                            groupProductSelected(_id)
                        }
                    }
                }
            }
            MatNumKeys {
                id: numKeys
            }
        }
    }
}
