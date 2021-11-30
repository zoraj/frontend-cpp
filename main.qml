import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

import "qrc:/UI/ListModel"
import "qrc:/UI/Component"

ApplicationWindow {
    id: gMainWindow
    width: 1024
    height: 768
    visible: true
    readonly property int gScreenWidth: width
    readonly property int gScreenHeight: height
    property bool gIsConnected: false
    property int gModule: 0 // POS = 0; RECEP = 1, RESA = 2, HOUSEKEEPING = 3, COLLECTIVITE = 4
    property string gUserName
    property  bool gShouldServiceChoicePOSVisible: false
    property string gViewTitle

    title: qsTr("APP_TITLE")

    /* Component Initilization - Start */
    Component.onCompleted: {
        gMainStackView.replace(null, "qrc:/UI/View/SplashView.qml", StackView.Immediate)
    }
    /* Component Initilization - End */


    /* Rectangle background during signin and signup */
    Rectangle {
        id: gBackgroundGradientRectangle
        anchors.fill: parent
        gradient: Gradient
        {
            GradientStop {position: 0.000;color: "#a1c4fd";}
            GradientStop {position: 1.000;color: "#c2e9fb";}
        }
        visible: !gIsConnected
    }

    /* Header - Start */
    /* List Model Declaration */
    ResaTabBarListModel {
        id: resaTabBarListModel
    }
    ResaDrawerListModel {
        id: resaDrawerListModel
    }

    RecepTabBarListModel {
        id: recepTabBarListModel
    }
    RecepDrawerListModel {
        id: recepDrawerListModel
    }

    PosDrawerListModel {
        id: posDrawerListModel
    }

    HouseKeepingTabBarListModel {
        id: houseKeepingTabBarListModel
    }
    HouseKeepingDrawerListModel {
        id: houseKeepingDrawerListModel
    }

    Drawer {
        id: gMainDrawer
        width: 300
        height: gMainWindow.height
        Column {
            spacing: P._MARGIN_CONTAINER
            anchors.horizontalCenter: parent.horizontalCenter
            Rectangle {
                width: gMainDrawer.width; height: 200
                color: "lightgrey"
                Column {
                    anchors.horizontalCenter: parent.horizontalCenter
                    Image {
                        source: "qrc:/Assets/Image/Pos/Drawer/cook.png"
                        width: 150; height: 150
                        fillMode: Image.PreserveAspectFit
                        asynchronous: true
                    }
                    Text {
                        id: userNameText
                        font.pointSize: P._SUBTITLE_FONT_SIZE
                        text: gUserName
                    }
                }
            }
            Rectangle {
                id: menuDRect
                width: gMainDrawer.width; height: gMainDrawer.height - 350
                ListView {
                    id: menuListView
                    width: gMainDrawer.width; height: menuDRect.height
                    clip: true
                    delegate: Rectangle {
                        width: menuListView.width; height: 50
                        Label {
                            x: P._MARGIN_CONTAINER; y: P._MARGIN_CONTAINER
                            text: title
                        }
                        MouseArea {
                            anchors.fill: parent
                            onClicked: {
                                gMainDrawer.close()
                                gMainStackView.replace(null, source, StackView.Immediate)
                            }
                        }
                    }
                    model: switch(gModule) {
                       case 0: // Resto
                           return posDrawerListModel
                       case 1: // Recep
                           return recepDrawerListModel
                       case 2: // Resa
                           return resaDrawerListModel
                       case 3:  // HouseKeeping
                           return houseKeepingDrawerListModel
                       case 4: // Resto
                           return posDrawerListModel
                       default: // By Default, Reservation
                           return resaDrawerListModel
                    }
                }
            }
            Rectangle {
                width:gMainDrawer.width; height: 1
                color: "lightgrey"
            }

            Rectangle {
                id: rect
                width: gMainDrawer.width; height: 50
                color: "white"
                Row {
                    //anchors.verticalCenter: parent.verticalCenter
                    anchors.centerIn: parent
                    Image {
                        source: "qrc:/Assets/Image/Pos/Drawer/logout.png"
                        width: 50; height: 50
                        fillMode: Image.PreserveAspectFit
                        asynchronous: true
                    }
                    Label {
                        anchors.verticalCenter: parent.verticalCenter
                        text: "Se déconnecter"
                    }
                }
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        gIsConnected = false
                        gMainDrawer.close()
                        gMainStackView.replace(null, "qrc:/Views/Common/LoginView.qml", StackView.Immediate)
                    }
                }
            }
        }
    }
    /* UI Action */
    Action {
        id: navigationAction
        icon.name: gMainStackView.depth > 1 ? "back" : "drawer"
        onTriggered: {
            if (gMainStackView.depth > 1) {
                gMainStackView.pop()
            }
            else {
                gMainDrawer.open()
            }
        }
    }
    Action {
        id: optionsRecepPlanningAction
        icon.name: "menu"
        onTriggered: {
            optionsRecepPlanningMenu.open()
        }
    }
    Action {
        id: optionsResaPlanningAction
        icon.name: "menu"
        onTriggered: {
            optionsResaPlanningMenu.open()
        }
    }
    Action {
        id: optionsPOSServiceAction
        icon.name: "menu"
        onTriggered: {
            servicePOSMenu.open()
        }
    }
    header: ToolBar {
        id: headerToolBar
        visible: gIsConnected
        RowLayout {
            spacing: 20
            anchors.fill: parent

            ToolButton {
                action: navigationAction
            }

            Label {
                id: titleLabel
                text: gViewTitle
                color: "white"
                font.pixelSize: P._TITLE_FONT_SIZE
                elide: Label.ElideRight
                horizontalAlignment: Qt.AlignHCenter
                verticalAlignment: Qt.AlignVCenter
                Layout.fillWidth: true
            }
            Label {
                id: servicePOSLabel
                text: "☀"
                color: "white"
                font.pixelSize: P._TITLE_FONT_SIZE * 2
                elide: Label.ElideRight
                horizontalAlignment: Qt.AlignHCenter
                verticalAlignment: Qt.AlignVCenter
            }
            ToolButton {
                id: servicePOSTool
                action: optionsPOSServiceAction
                opacity: gShouldServiceChoicePOSVisible ? 1.0 : 0.0
                Menu {
                    id: servicePOSMenu
                    x: parent.width - width
                    transformOrigin: Menu.TopRight
                    Action {
                        text: "Service Midi"
                        onTriggered: {
                            // A hack solution, TODO: find a better way, this toggleService function is only valid when ActivitiesView is the currentItem
                            gMainStackView.currentItem.toggleService('M')
                            servicePOSLabel.text = "☀";
                            servicePOSLabel.font.pixelSize = P._TITLE_FONT_SIZE * 2 - 4
                        }
                    }
                    Action {
                        text: "Service Soir"
                        onTriggered: {
                            // A hack solution, TODO: find a better way,
                            gMainStackView.currentItem.toggleService('S')
                            servicePOSLabel.text = "🌙";
                            servicePOSLabel.font.pixelSize = P._TITLE_FONT_SIZE
                        }
                    }
                }
            }

            ToolButton {
                action: optionsRecepPlanningAction
                visible: gModule === 1 && gFooterTabBar.currentIndex === 0 && gMainStackView.depth === 1
                Menu {
                    id: optionsRecepPlanningMenu
                    x: parent.width - width
                    transformOrigin: Menu.TopRight
                    Action {
                        text: "Tout le planning"
                        onTriggered: {
                        }
                    }
                    Action {
                        text: "Chambre libre"
                        onTriggered: {
                        }
                    }
                    Action {
                        text: "Chambre présente"
                        onTriggered: {
                        }
                    }
                    Action {
                        text: "Chambre en départ"
                        onTriggered: {
                        }
                    }
                    Action {
                        text: "Chambre en arrivée"
                        onTriggered: {
                        }
                    }
                    Action {
                        text: "Présent-arrivée-départ"
                        onTriggered: {
                        }
                    }
                    Action {
                        text: "Chambres soldées"
                        onTriggered: {
                        }
                    }
                }
            }
            ToolButton {
                action: optionsResaPlanningAction
                visible: gModule === 2 && gFooterTabBar.currentIndex === 0 && gMainStackView.depth === 1
                Menu {
                    id: optionsResaPlanningMenu
                    x: parent.width - width
                    transformOrigin: Menu.TopRight
                    Action {
                        text: "Tout le planning"
                        onTriggered: {
                        }
                    }
                    Action {
                        text: "Planning du jour"
                        onTriggered: {
                        }
                    }
                    Action {
                        text: "Planning mois"
                        onTriggered: {
                        }
                    }
                    Action {
                        text: "Planning / Type"
                        onTriggered: {
                        }
                    }
                    Action {
                        text: "Planning / Chambre"
                        onTriggered: {
                        }
                    }
                    Action {
                        text: "Planning / Segment"
                        onTriggered: {
                        }
                    }
                }
            }
        }
    }
    /* Header - End */

    /* Body - Start */
    StackView {
        id: gMainStackView
        anchors.fill: parent
    }
    /* Body - End */

    /* Footer - Start */
    footer: TabBar {
        id: gFooterTabBar
        width: gMainWindow.width
        visible: gIsConnected
        Repeater {
            model: {
                switch(gModule) {
                case 0: // Resto
                    return null
                case 1: // Recep
                    return recepTabBarListModel
                case 2: // Resa
                    return resaTabBarListModel
                case 3:  // HouseKeeping
                    return houseKeepingTabBarListModel
                case 4: // Collectivité
                    return null
                default: // By Default, Reservation
                    return resaTabBarListModel
                }
            }
            TabButton {
                text: title
                onClicked: {
                    gMainStackView.replace(null, source, StackView.Immediate)
                }
            }
        }
    }
    /* Footer - End */


    /* */

    /* Global Toast for User notification - End */
    MatToast {
        id: gMainToast
        onAboutToHide: {
            //resetFocus()
        }
    }
    /* Global Toast for User notification - Start */

}
