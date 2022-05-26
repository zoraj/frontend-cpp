import QtQuick 2.15
import QtQuick.Controls 2.15

LoginViewForm {

    // Business Component Initialization
    Connections {
        target: _signinViewController
        function onValidatePinCodeTriggeredFinished(result, module) {
            if (result) {
                gModule = 2 // POS = 0; RECEP = 1, RESA = 2, HOUSEKEEPING = 3, COLLECTIVITE = 4
                gIsConnected = true
                switch(gModule) {
                case 0:
                    gMainStackView.replace(null, "qrc:/UI/View/PosActivitiesView.qml", StackView.Immediate)
                    break
                case 1:
                    gMainStackView.replace(null, "qrc:/UI/View/PlanningRecepView.qml", StackView.Immediate)
                    break
                case 2:
                    gMainStackView.replace(null, "qrc:/UI/View/BookingPlanningView.qml", StackView.Immediate)
                    break
                default:
                    break
                }
            }
            else {

            }
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

    // User function
    function nextFocusOrValidate() {
        // TODO This function can be better written without the multiple if
        if (t0.text !== "") t1.focus = true
        if (t1.text !== "") t2.focus = true
        if (t2.text !== "") t3.focus = true
        var code = t0.text + t1.text + t2.text + t3.text
        if (code.length === 4) {
            _signinViewController.validatePinCodeTriggered(code)
        }
    }

}
