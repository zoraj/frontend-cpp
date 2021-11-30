import QtQuick 2.15
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4

import "qrc:/."

Flickable {
    Rectangle {
        x: P._MARGIN_CONTAINER; y: P._MARGIN_CONTAINER
        width: parent.width - P._MARGIN_CONTAINER * 2; height: parent.height - P._MARGIN_CONTAINER * 2
        Calendar {
            anchors.fill: parent
            weekNumbersVisible: true

            style: CalendarStyle {
                    gridVisible: true
                    dayDelegate: Rectangle {
                        // @disable-check M222
                        color: isToday(styleData.date) ? "#F4F7FA" : "white"
                        Label {
                            // @disable-check M222
                            text: styleData.date.getDate()
                            x: 5
                            y : 5
                            // @disable-check M223
                            color: {
                                // @disable-check M222
                                if (isToday(styleData.date)) return "#98B2C3";
                                // @disable-check M222
                                if (isDateWeekend(styleData.date) && styleData.visibleMonth) return "#E33235";
                                if (styleData.visibleMonth && styleData.valid) return "black";
                                return "lightgrey"
                            }

                            font.pointSize: 24
                        }
                        Rectangle {
                            width: parent.width / 2
                            height: 14
                            x: parent.width / 2
                            color: "#E9FAF0"

                            Label {
                                x: 2
                                y: 2
                                font.pointSize: 8
                                color: "#21D267"
                                // @disable-check M222
                                text: getMaidList(styleData.date)
                            }
                        }

                        Rectangle {
                            width: parent.width
                            height: 1
                            color: "transparent"
                            anchors.bottom: parent.bottom
                        }

                        Rectangle {
                            width: 1
                            height: parent.height
                            color: "transparent"
                            anchors.right: parent.right
                        }
                    }
                }
        }
    }
}
