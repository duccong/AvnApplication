import QtQuick 2.0
import QtQml 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import "../common"

Item {
    width: parent.parent.width
    height: 50
    // anchors.verticalCenter: parent.verticalCenter
    property alias skillId: skillImg.skillId
    property alias skillName: skill.text
    property int skillPoint: 0//.item.text
    property alias evaluateImg: evaluateImg.source

    function skillIdToImg(id) {
        return "qrc:/imageSource/icons" + id + ".png"
    }

    RowLayout {
        anchors.fill: parent
        anchors.margins: 5
        anchors.verticalCenter: parent.verticalCenter

        Image {
            // Layout.fillHeight: true
            id: skillImg
            property int skillId: 0
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.preferredWidth: 0.15
            source: skillIdToImg(skillId)//"qrc:/../imageSource/Star.png"
            // source: "qrc:/imageSource/icons8.png"
        }

        Text {
            // Layout.fillHeight: true
            id: skill
            Layout.fillWidth: true
            Layout.preferredWidth: 0.5
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter

            text: "Skill of " + model.name
            font.pixelSize: 18
        }

        Loader {
            id: pointLoader
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.preferredWidth: 0.2
            sourceComponent: isAdmin ? textField : text

            // horizontalAlignment: Text.AlignHCenter
            // verticalAlignment: Text.AlignVCenter

            // text: "-/-"
            // font.pixelSize: 18
        }


        Image {
            id: evaluateImg
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.preferredWidth: 0.15
            scale: 0.8
            source: skillPoint >= 3 ? "qrc:/imageSource/icons-done.png" : "qrc:/imageSource/icons-close.png"
        }
    }

    Component {
        id: textField
        Item {
            anchors.fill: parent
            TextField {
                id: editText
                anchors.verticalCenter: parent.verticalCenter
                width: parent.width/2
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter

                text: point
                font.pixelSize: 18
            }
            Text {
                height: editText.height
                anchors.left: editText.right
                anchors.verticalCenter: parent.verticalCenter
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                text: " /5"
                font.pixelSize: 18
            }
        }
    }

    Component {
        id: text
        Text {
            // Layout.fillHeight: true
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter

            text: point + " /5"
            font.pixelSize: 18
        }
    }


}
