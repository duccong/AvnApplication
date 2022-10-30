import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
Item {
    id: container
    width: 540
    height: 810

    signal editTextChanged(var text)

    Nulo {

    }

    RowLayout {
        anchors.fill: parent
        anchors.margins: 10
        Text {
            Nulo {

            }

            text: "Search Name:"
            Layout.fillWidth: true
            Layout.preferredWidth: 0.3

            font.pixelSize: 18
        }

        TextField {
            Nulo {

            }
            Layout.fillWidth: true
            Layout.preferredWidth: 0.7
            // Layout.rightMargin: 15
            placeholderText: "Input string..."
            font.pixelSize: 18
            color: "BLACK"

            onTextChanged: {
                console.log("Text: " + text)
                editTextChanged(text)
            }
        }
    }

}
