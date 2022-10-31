import QtQuick 2.0
import QtQml 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import "../common"

Item {
    width: parent.width
    height: 50
    // anchors.verticalCenter: parent.verticalCenter
    property alias skillImg: skillImg.source
    property alias skillName: skill.text
    property int skillPoint: 0//.item.text
    property alias evaluateImg: evaluateImg.source
    RowLayout {
        anchors.fill: parent
        anchors.margins: 5
        anchors.verticalCenter: parent.verticalCenter
        // Nulo {

        // }

        Image {
            // Nulo {

            // }

            // Layout.fillHeight: true
            id: skillImg
            property int id: 0
            Layout.fillWidth: true
            Layout.preferredWidth: 0.15
            source: "../../imageSource/Star.png"
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
            Layout.fillWidth: true
            Layout.preferredWidth: 0.2
            sourceComponent: textField

            // horizontalAlignment: Text.AlignHCenter
            // verticalAlignment: Text.AlignVCenter

            // text: "-/-"
            // font.pixelSize: 18
        }


        Image {
            // Nulo {

            // }

            // Layout.fillHeight: true
            id: evaluateImg
            Layout.fillWidth: true
            Layout.preferredWidth: 0.15
            source: "../../imageSource/Star.png"
        }
    }

    Component {
        id: textField
        TextField {
            // Layout.fillHeight: true
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter

            text: point + "/5"
            font.pixelSize: 18
        }
    }

    Component {
        id: text
        Text {
            // Layout.fillHeight: true
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter

            text: point + "/5"
            font.pixelSize: 18
        }
    }


}
