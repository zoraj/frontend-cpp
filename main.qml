import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    id: gMainWindow
    width: 1024
    height: 768
    visible: true
    property bool gIsConnected: false
    property int gModule: 0 // POS = 0; RECEP = 1, RESA = 2, HOUSEKEEPING = 3, COLLECTIVITE = 4

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

    /* Body - Start */
    StackView {
        id: gMainStackView
        anchors.fill: parent
    }
    /* Body - End */
}
