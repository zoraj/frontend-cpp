import QtQuick 2.15
import QtQuick.Controls 2.15
import "qrc:/."
import "qrc:/UI/Component"

Dialog {
    property int productSelectedId: -1
    id: dialog
    width: gScreenWidth * 4 / 5
    height: gScreenHeight * 2 / 3
    anchors.centerIn: parent
    modal: true
    title: qsTr("PRODUCT_SEARCH") //"Recherche de prestation"
    standardButtons: Dialog.Close
    Column {
        MatTextField {
            id: productSearchText
            width: dialog.width - P._MARGIN_CONTAINER * 2
            onTextChanged: {
                //_orderViewController.productSearchTextChanged(productSearchText.text)
            }
        }
        ListView {
            width: dialog.width - P._MARGIN_CONTAINER * 2; height: dialog.height - dialog.footer.height - productSearchText.height - dialog.header.height
            clip: true
            spacing: P._SPACE_COMPONENT
            delegate: Rectangle {
                width: dialog.width; height: 50
                color: "#f7f9fa"
                Row {
                    spacing: P._MARGIN_CONTAINER
                    anchors.verticalCenter: parent.verticalCenter
                    Text {
                        x: P._MARGIN_CONTAINER
                        width: dialog.width * 1 / 5
                        text: code
                    }
                    Text {
                        width: dialog.width * 3 / 5
                        text: libelle
                    }
                    Text {
                        width: dialog.width * 1 / 5
                        text: prix + "€"
                    }
                }
                MouseArea {
                    z: 1
                    hoverEnabled: false
                    anchors.fill: parent
                    onClicked: {
                        productSelectedId = _id
                        close()
                    }
                }
            }
            //model: _orderViewController.productSearchListProxyModel
        }
    }
}
