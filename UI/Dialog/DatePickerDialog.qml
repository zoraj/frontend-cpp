import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.12
import QtQuick.Controls 1.4

Dialog {
    id: datepickerDialog

    x: (parent.width - width) / 2
    y: (parent.height - height) / 2
    parent: Overlay.overlay

    modal: true
    title: "Calendrier"
    standardButtons: Dialog.Close

    property Item caller: null
    property string subtitle
    property date defautDate : new Date()

    Column {
        spacing: 20
        anchors.fill: parent
        Label {
            text: "Choix de date"
        }
        Calendar {
            id: calendarComponent
            selectedDate: defautDate
            weekNumbersVisible: true
            //frameVisible:true
            minimumDate: new Date(2022, 0, 1)
            maximumDate: new Date(2030, 11, 3)
        }
    }
    onClosed: {
        caller.text = Qt.formatDate(calendarComponent.selectedDate, "dd/MM/yyyy")
        caller.value = Qt.formatDate(calendarComponent.selectedDate, "yyyy-MM-dd")
    }
}
