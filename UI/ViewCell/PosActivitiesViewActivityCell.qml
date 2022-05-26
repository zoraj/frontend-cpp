import QtQuick 2.15
import QtQuick.Controls 2.15
import "qrc:/."

Item {
    property int activityId: 0
    property string activityName
    property string iconName
    property bool isTablePlan
    Row {
        spacing: P._MARGIN_CONTAINER
        Column {
            width: 130
            spacing: P._MARGIN_CONTAINER
            Image {
                source: "qrc:/Assets/Image/Pos/Activite/" + iconName
                asynchronous: true
                width: 70; height: 70
                anchors.horizontalCenter: parent.horizontalCenter
            }
            Text {
                text: activityName
                font.pointSize: P._SUBTITLE_FONT_SIZE
                anchors.horizontalCenter: parent.horizontalCenter
            }
        }

        Column {
            Button {
                width: 120
                text: qsTr("OPEN_NOTE")
                onClicked: {
                    openNoteButtonClicked(activityId)
                }
            }
            Button {
                width: 120
                text: qsTr("TABLE_PLAN")
                enabled: isTablePlan
                onClicked: {
                    tablePlanButtonClicked(activityId)
                    //_activitiesViewController.tablePlanButtonClicked(activityId)
                    //showTableNote()
                }
            }
            Button {
                width: 120
                text: qsTr("NEW_NOTE")
                onClicked: {
                    newNoteButtonClicked(activityId)
                }
            }
        }
    }
}
