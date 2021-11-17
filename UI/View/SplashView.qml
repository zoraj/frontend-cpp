import QtQuick 2.15
import QtQuick.Controls 2.15

SplashViewForm {
    /* Component Initilization - Start */
    Connections {
        target: _splashViewController
        function onViewDidLoadFinished(hasAPIKeyAndUUIDDevice, reason) {
            if (hasAPIKeyAndUUIDDevice)
                gMainStackView.replace(null, "qrc:/UI/View/LoginView.qml", StackView.Immediate)
            else
                gMainStackView.replace(null, "qrc:/UI/View/SignupView.qml", StackView.Immediate)
        }
    }

    Component.onCompleted: {
        timer.start()
    }
    /* Component Initilization - End */

    Timer {
        id: timer
        // Show the splash during 2 sec
        interval: 2000; running: false; repeat: false
        onTriggered: {
            _splashViewController.viewDidLoad()
        }
    }
}
