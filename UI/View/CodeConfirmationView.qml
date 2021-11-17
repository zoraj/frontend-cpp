import QtQuick 2.15
import QtQuick.Controls 2.15

CodeConfirmationViewForm {

    // Business Component Initialization
    Connections {
        target: _codeConfirmationViewController
        function onValidateCodeTriggeredFinished(result) {
            if (result) {
                timer.running = true // After 2 sec, push the login view
            }
            else {

            }
        }
    }

    // UI Component Initialization
    Timer {
        id: timer
        interval: 2000; running: false; repeat: false
        onTriggered: {
            console.log("Triggered")
            gMainStackView.replace(null, "qrc:/UI/View/LoginView.qml", StackView.Immediate)
        }
    }
    // View Load
    Component.onCompleted: {
        t0.focus = true
    }
    // Event Logic

    t0.onTextEdited: {
        if (t0.text !== "")
            nextFocusOrValidate()
    }
    t1.onTextEdited: {
        if (t1.text !== "")
            nextFocusOrValidate()
    }
    t2.onTextEdited: {
        if (t2.text !== "")
            nextFocusOrValidate()
    }
    t3.onTextEdited: {
        if (t3.text !== "")
            nextFocusOrValidate()
    }
    t4.onTextEdited: {
        if (t4.text !== "")
            nextFocusOrValidate()
    }
    t5.onTextEdited: {
        if (t5.text !== "")
            nextFocusOrValidate()
    }

    // User function
    function nextFocusOrValidate() {
        // TODO This function can be better written without the multiple if
        if (t0.text !== "") t1.focus = true
        if (t1.text !== "") t2.focus = true
        if (t2.text !== "") t3.focus = true
        if (t3.text !== "") t4.focus = true
        if (t4.text !== "") t5.focus = true
        var code = t0.text + t1.text + t2.text + t3.text + t4.text + t5.text
        if (code.length === 6) {
            _codeConfirmationViewController.validateCodeTriggered(code)
        }
    }

}
