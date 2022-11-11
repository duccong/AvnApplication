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
        Loader {
            id: loaderName
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.preferredHeight: 0.2
            sourceComponent: isAdmin ? textField : text
        }

        ListView {
            id: listSkills
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.preferredHeight: 0.7
            clip: true

            model: detailProfileModel.skillList
            delegate: DetailSkills {
                width: listSkills.width
                skillId: model.id
                skillName: model.name
                skillPoint: model.point
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
            text: detailProfileModel.name//"Your name!!!"
        }
    }

    Component.onCompleted: {
        console.log("listView: onCompleted")
    }
}
