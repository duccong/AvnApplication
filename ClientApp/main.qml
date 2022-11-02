import QtQuick.Window 2.12
import QtQuick 2.12
import QtQml 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import "qmlSource/common"

Window {
    width: 540
    height: 810
    visible: true
    title: qsTr("AVN applications")
    property bool isAdmin: false // TODO: move it to model
    property string permissionCmd: isAdmin ? "admin" : "user" // TODO: move it to model

    ColumnLayout {
        anchors.fill: parent
        Loader {
            id: loaderDetail
            source: "qrc:/qmlSource/components/DetailProfile.qml"
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.preferredHeight: 0.4
            active: !loadingScreen.visible
            onLoaded: {
                console.log("DetailComponent is loaded")
            }
        }

        Loader {
            id: loaderListMember
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.preferredHeight: 0.6
            active: !loadingScreen.visible
            source: "qrc:/qmlSource/components/ListProfile.qml"
            onLoaded: {
                console.log("ListMemberComponent is loaded")
                item.anchors.fill = loaderListMember
            }
        }
    }

    Rectangle {
        id: loadingScreen
        anchors.fill: parent
        color: "BLUE"
        opacity: 0.6
        Column {
            BorderButton {
                content.text: "USER"
                onMouseClicked: {
                    loadingScreen.visible = false
                }
            }

            BorderButton {
                content.text: "ADMIN"
                onMouseClicked: {
                    isAdmin = true
                    loadingScreen.visible = false
                }
            }
        }

    }

}
