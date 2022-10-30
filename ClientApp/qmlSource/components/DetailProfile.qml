import QtQuick 2.12
import QtQml 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import "../common"
import "../delegates"

Item {
    id: container
    width: 540
    height: 810

    ColumnLayout {
        width: parent.width * 0.8
        height: parent.height
        anchors.centerIn: parent
        Nulo {

        }

        Text {
            Nulo {

            }

            id: txtName
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.preferredHeight: 0.2

            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font {
                bold: true
                pixelSize: 24
            }

            text: "Your name!!!"
        }

        ListView {
            Nulo {

            }

            id: listSkills
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.preferredHeight: 0.7
            clip: true

            model: 10
            delegate: DetailSkills {

            }
        }

        BorderButton {
            Layout.alignment: Qt.AlignHCenter
            Layout.fillHeight: true
            // Layout.fillWidth: true
            Layout.preferredHeight: 0.1

            content.text : "REFESH"
            content.font.bold: true
        }

    }


    Component.onCompleted: {
        console.log("listView: onCompleted")
    }
}
