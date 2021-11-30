import QtQuick 2.15
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.15
import QtQuick.Controls.Material 2.15
import "qrc:/."

Popup {
    id: popup
    closePolicy: Popup.NoAutoClose
    bottomMargin: 24 // isLandscape? 24 : 80
    x: (parent.width - width) / 2
    y: (parent.height - height)
    background: Rectangle{
        color: P._TOAST_COLOR
        radius: 24
        opacity: P._TOAST_OPACITY
    }
    Timer {
        id: toastTimer
        interval: P._TOAST_INTERVAL
        repeat: false
        onTriggered: {
            popup.close()
        }
    }
    Label {
        id: toastLabel
        leftPadding: 16
        rightPadding: 16
        font.pixelSize: 16
        color: "white"
    }
    onAboutToShow: {
        toastTimer.start()
    }
    function start(toastText) {
        toastLabel.text = toastText
        if(!toastTimer.running) {
            open()
        } else {
            toastTimer.restart()
        }
    }
}
