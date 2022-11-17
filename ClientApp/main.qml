import QtQuick.Window 2.12
import QtQuick 2.12
import QtQml 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import "qmlSource/common"

Window {
    width: 1080
    height: 810
    visible: true
    title: qsTr("AVN applications")
    property bool isAdmin: false // TODO: move it to model
    property string permissionCmd: isAdmin ? "admin" : "user" // TODO: move it to model

    ColumnLayout {
        width: 540
        height: 810
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
        // visible: false
        anchors.fill: parent
        color: "BLUE"
        opacity: 0.6
        Column {
            BorderButton {
                content.text: "START"
                onMouseClicked: {
                    loadingScreen.visible = false
                }
            }

            // BorderButton {
                // content.text: "ADMIN"
                // onMouseClicked: {
                    // isAdmin = true
                    // loadingScreen.visible = false
                // }
            // }
        }

    }

    Rectangle {
        id: mapView
        clip: true
        width: 540
        height: 810
        anchors.right: parent.right

        DrawArc {
            id: hightlightView
            // Nulo {

            // }

            opacity: 0.5
            anchors.centerIn: parent
            height: parent.height *2
            width: height *2
            size: height * 3
            totalIndex: 360
            start: 0
            end: 30 * 2

            RotationAnimation {
                id: animationHightLight
                target: hightlightView
                duration: 3000
                running: true
                from: 0
                to: 360
                loops: Animation.Infinite
                // direction: RotationAnimation.Counterclockwise
            }
        }

        Repeater {
            Nulo {

            }
            anchors.fill: parent
            model: profileListModel
            // model: filteredModel//profileListModel
            delegate: Text {
                id: item
                width: 70
                height: 70
                font.pixelSize: 12
                text: model.name
                x: getRand(mapView.width - item.width)
                y: getRand(mapView.height - item.height)
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        container.itemClicked(index)
                    }
                }
            }
        }
    }

    function getRand(max) {
        return Math.floor(Math.random() * max)
    }
}
