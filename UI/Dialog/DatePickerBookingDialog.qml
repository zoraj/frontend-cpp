import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.12
import QtQuick.Controls 1.4
import "qrc:/UI/Component"

Dialog {
    x: (parent.width - width) / 2
    y: (parent.height - height) / 2
    parent: Overlay.overlay

    modal: true
    title: "Calendrier"
    standardButtons: Dialog.Close

    property Item arrivalCaller: null
    property Item departureCaller: null
    property string subtitle
    property date defautDate : new Date()

    Column {
        spacing: 20
        anchors.fill: parent
        Label {
            text: "Choix des dates"
        }
        Row {
            spacing: 100
            Calendar {
                id: arrivalCalendar
                selectedDate: defautDate
                weekNumbersVisible: true
                //frameVisible:true
                minimumDate: new Date(2022, 0, 1)
                maximumDate: new Date(2030, 11, 3)
            }
            MatSpinBox {
                id: nuiteeSpinBox
                title: "Nuitée"
                onValueModified: {
                    let departureDate = new Date(arrivalCalendar.selectedDate);
                    departureDate.setDate(departureDate.getDate() + nuiteeSpinBox.value)
                    departureCalendar.selectedDate = departureDate
                }
            }
            Calendar {
                id: departureCalendar
                selectedDate: defautDate
                weekNumbersVisible: true
                //frameVisible:true
                minimumDate: new Date(2022, 0, 1)
                maximumDate: new Date(2030, 11, 3)
            }
        }
    }
    onClosed: {
        arrivalCaller.value = Qt.formatDate(arrivalCalendar.selectedDate, "dd/MM/yyyy")
        departureCaller.value = Qt.formatDate(departureCalendar.selectedDate, "dd/MM/yyyy")
    }
}
