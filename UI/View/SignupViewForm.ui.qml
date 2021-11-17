import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.12
import QtGraphicalEffects 1.12
import "qrc:/."
import "qrc:/UI/Component"
//import cloud.multimicro.mmc.frontend 1.0

Flickable {
    contentHeight: mainRectangle.height
    width: gMainWindow.width / 3
    flickableDirection: Flickable.AutoFlickIfNeeded
    property alias validateButton: validateButton
    property alias activateDeviceButton: activateDeviceButton
    property alias nameTextField: nameTextField
    property alias typeComboBox: typeComboBox
    property alias countryComboBox: countryComboBox
    property alias addressTextField: addressTextField
    property alias ownerFirstnameTextField: ownerFirstnameTextField
    property alias ownerLastnameTextField: ownerLastnameTextField
    property alias email1TextField: email1TextField
    property alias phoneTextField: phoneTextField

    Label {
        id: title1
        x: 100
        y: gMainWindow.height / 4
        color: "white"
        text: qsTr("SIGNUP_TITLE")
        font.bold: true
        font.pointSize: 36
        width: gMainWindow.width / 3 + 150
        clip: true
        elide: Text.ElideLeft
        wrapMode: Text.Wrap
    }
    Label {
        anchors.top: title1.bottom
        anchors.left: title1.left
        anchors.topMargin: 10
        color: "white"
        text: qsTr("SIGNUP_SUBTITLE")
        font.pointSize: 18
        width: title1.width
        clip: true
        elide: Text.ElideLeft
        wrapMode: Text.Wrap
    }

    RectangularGlow {
        anchors.fill: mainRectangle
        glowRadius: 15
        spread: 0.1
        color: "lightsteelblue"
        cornerRadius: mainRectangle.radius + glowRadius
    }
    // Main Rectangle
    Rectangle {
        id: mainRectangle
        //anchors.fill: parent
        color: "white"
        radius: 2
        width: gMainWindow.width / 3
        height: gMainWindow.height - 100
        x: gMainWindow.width - width - 100
        y: (gMainWindow.height - mainRectangle.height) / 2
        clip: true

        // Title
        Label {
            id: label1
            topPadding: 80
            width: parent.width
            wrapMode: Label.Wrap
            horizontalAlignment: Qt.AlignHCenter
            text: qsTr("CREATE_NEW_MAT_ACCOUNT")
            font.pointSize: 18
            color: "#374866"
        }

        // Form start
        Column {
            spacing: 10
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: label1.bottom
            topPadding: 100
            MatTextField {
                id: nameTextField
                anchors.horizontalCenter: parent.horizontalCenter
                title: qsTr("ESTABLISHMENT_NAME")
                textWidth: mainRectangle.width
                width: mainRectangle.width - P._MARGIN_CONTAINER * 2
            }
            MatComboBox {
                id: typeComboBox
                anchors.horizontalCenter: parent.horizontalCenter
                title: qsTr("ESTABLISHMENT_TYPE")
                textWidth: mainRectangle.width - 100
                width: mainRectangle.width - P._MARGIN_CONTAINER * 2
            }
            MatComboBox {
                id: countryComboBox
                anchors.horizontalCenter: parent.horizontalCenter
                title: qsTr("COUNTRY")
                textWidth: mainRectangle.width - 100
                width: mainRectangle.width - P._MARGIN_CONTAINER * 2
            }
            MatTextField {
                id: addressTextField
                anchors.horizontalCenter: parent.horizontalCenter
                title: qsTr("ADDRESS")
                textWidth: mainRectangle.width - 100
                width: mainRectangle.width - P._MARGIN_CONTAINER * 2
            }
            Row {
                spacing: P._MARGIN_CONTAINER
                anchors.horizontalCenter: parent.horizontalCenter
                MatTextField {
                    id: ownerFirstnameTextField
                    title: qsTr("FIRSTNAME")
                    textWidth: mainRectangle.width / 2 - 50
                    width:  mainRectangle.width / 2 - P._MARGIN_CONTAINER * 2
                }
                MatTextField {
                    id: ownerLastnameTextField
                    title: qsTr("LASTNAME")
                    textWidth: mainRectangle.width / 2 - 50
                    width:  mainRectangle.width / 2 - P._MARGIN_CONTAINER * 2
                }
            }
            Row {
                spacing: P._MARGIN_CONTAINER
                anchors.horizontalCenter: parent.horizontalCenter
                MatTextField {
                    id: email1TextField
                    title: qsTr("EMAIL")
                    textWidth: mainRectangle.width / 2 - 50
                    width:  mainRectangle.width / 2 - P._MARGIN_CONTAINER * 2
                }
                MatTextField {
                    id: phoneTextField
                    title: qsTr("PHONE")
                    textWidth: mainRectangle.width / 2 - 50
                    width:  mainRectangle.width / 2 - P._MARGIN_CONTAINER * 2
                }
            }
            Row {
                spacing: P._MARGIN_COMPONENT
                anchors.horizontalCenter: parent.horizontalCenter
                Button {
                    id: validateButton
                    text: qsTr("VALIDATE")
                    width: 80
                }

                Button {
                    id: activateDeviceButton
                    contentItem: Text {
                        font.pointSize: 12
                        font.underline: true
                        opacity: enabled ? 1.0 : 0.3
                        //color: "#06a8c4"
                        text: qsTr("YOU_ALREADY_HAVE_AN_ACCOUNT")
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        elide: Text.ElideRight
                        color: "#374866"
                    }

                    background: Rectangle {
                        implicitWidth: 80
                        implicitHeight: 60
                        opacity: enabled ? 1 : 0.3
                        border.width: 0
                        radius: 2
                        color: "transparent"
                    }
                }
            }

        }
    }
}
