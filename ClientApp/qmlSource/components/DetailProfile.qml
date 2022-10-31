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
        Loader {
            id: loaderName
            Nulo {

            }
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.preferredHeight: 0.2
            sourceComponent: textField
        }

        ListView {
            Nulo {

            }

            id: listSkills
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.preferredHeight: 0.7
            clip: true

            model: detailProfileModel.skillList
            delegate: DetailSkills {
                skillName: model.id
            }
        }

        BorderButton {
            Layout.alignment: Qt.AlignHCenter
            Layout.fillHeight: true
            // Layout.fillWidth: true
            Layout.preferredHeight: 0.1

            content.text : "REFESH"
            content.font.bold: true
            onMouseClicked: {
                forceActiveFocus()
            }
        }

    }


    Component {
        id: textField
        TextField {
            id: txtName
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.preferredHeight: 0.2

            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font {
                pixelSize: 24
                bold: true
            }
            text: detailProfileModel.name
        }
    }

    Component {
        id: text
        Text {
            id: txtName
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.preferredHeight: 0.2

            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font {
                pixelSize: 24
                bold: true
            }
            text: "Your name!!!"
        }
    }

    Component.onCompleted: {
        console.log("listView: onCompleted")
    }
}
