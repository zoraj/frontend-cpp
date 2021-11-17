pragma Singleton

import QtQuick 2.15

QtObject {
    readonly property int _TITLE_FONT_SIZE: 20
    readonly property int _SUBTITLE_FONT_SIZE: 16
    readonly property int _STANDARD_FONT_SIZE: 12

    readonly property int _MARGIN_CONTAINER: 20
    readonly property int _MARGIN_COMPONENT: 10
    readonly property int _SPACE_COMPONENT: 2
    readonly property int _TABBAR_HEIGHT: 50
    readonly property int _ACTION_BUTTON_CONTAINER_HEIGHT: 80

    readonly property color _TOAST_COLOR: "black"
    readonly property real _TOAST_OPACITY: 0.5
    readonly property int _TOAST_INTERVAL: 2500

    readonly property color _LOADING_COLOR: "black"
    readonly property real _LOADING_OPACITY: 0.1

    readonly property color _DIALOG_COLOR: "#f2dede"
    readonly property color _DIALOG_TEXT_COLOR: "#a94442"
    readonly property real _DIALOG_OPACITY: 1.0

}
