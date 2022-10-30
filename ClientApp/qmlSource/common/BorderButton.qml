import QtQuick 2.0

Item {
    width: 150
    height: 50

    property alias bg: background
    property alias content: content

    signal clicked()

    Rectangle {
        id: background
        anchors.fill: parent
        color: "GREEN"
        border {
            width: 2
            color: "BLACK"
        }
        radius: 10
    }

    Text {
        id: content
        anchors.centerIn: parent
        text: "DoSth"
        font.pixelSize: 18
        color: "WHITE"
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            clicked()
        }
    }
}
