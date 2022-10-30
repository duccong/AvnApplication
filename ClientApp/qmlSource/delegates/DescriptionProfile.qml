import QtQuick 2.12
import QtQml 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import "../common"
import "../delegates"

Item {
    id: container
    width: parent.width
    height: 70

    property bool isSelected: false
    Rectangle {
        anchors.fill: rowData
        color: "BLUE"
        visible: isSelected
    }

    RowLayout {
        id: rowData
        Nulo {

        }

        anchors.fill: parent
        anchors.leftMargin: 30
        anchors.rightMargin: 30
        Text {
            id: txtName
            Layout.fillWidth: true
            Layout.preferredWidth: 0.7

            // horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font {
                bold: isSelected
                pixelSize: 18
            }

            text: "Your name!!!"
            color: isSelected ? "WHITE" : "BLACK"
        }

        Text {
            id: txtAverange
            Layout.fillWidth: true
            Layout.preferredWidth: 0.3

            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font {
                bold: isSelected
                pixelSize: 18
            }

            text: "---"
            color: isSelected ? "WHITE" : "BLACK"
        }
    }
}
