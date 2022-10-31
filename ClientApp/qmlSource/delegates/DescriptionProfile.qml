import QtQuick 2.12
import QtQml 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import "../common"
import "../delegates"

Item {
    id: container
    width: 540//parent.width
    height: 50

    property bool isSelected: false
    Rectangle {
        anchors.fill: rowData
        color: Qt.lighter("#6bdce4", 0.8)
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

            text: model.name
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

            text: model.averange
            color: isSelected ? "WHITE" : "BLACK"
        }
    }
}
