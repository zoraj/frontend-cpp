import QtQuick 2.15

Rectangle {
    Image {
        anchors.fill: parent
        anchors.centerIn: parent
        asynchronous: true
        fillMode: Image.PreserveAspectFit
        source: "qrc:/Assets/Image/Common/logomat-centered.png"
    }
}
