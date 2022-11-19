import QtQuick.Window 2.11
import QtQuick 2.11
import QtQml 2.11
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.11
import "qmlSource/common"

Window {
    property real ratio: 0.8
    width: 1080 * ratio
    height: 810 * ratio
    visible: true
    title: qsTr("AVN applications")
    property bool isAdmin: false // TODO: move it to model
    property string permissionCmd: isAdmin ? "admin" : "user" // TODO: move it to model
    property int durationAnimation: 3600

    function skillIdToImg(id) {
        return "qrc:/imageSource/icons" + id + ".png"
    }

    ColumnLayout {
        width: 540 * ratio
        height: 810 * ratio
        Loader {
            id: loaderDetail
            source: "qrc:/qmlSource/components/DetailProfile.qml"
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.preferredHeight: 0.4
            active: !loadingScreen.visible
            asynchronous: true
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
            asynchronous: true
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
        Nulo {
        }
        id: mapView
        clip: true
        height: 810 * ratio / 2
        width: height//540 * ratio / 2
        anchors.right: parent.right

        Repeater {
            anchors.fill: parent
            model: profileListModel
            // model: filteredModel//profileListModel
            delegate: Image {
                // Layout.fillHeight: true
                id: item
                property int skillId: model.id % 5
                width: 15
                height: 15
                x: getRand(mapView.width - item.width)
                y: getRand(mapView.height - item.height)
                source: skillIdToImg(skillId)//"qrc:/../imageSource/Star.png"
                // opacity: 0.2
                Timer {
                    id: timerLocation
                    interval: durationAnimation / 10
                    repeat: true
                    // running: true
                    onTriggered: {
                        x = getRand(mapView.width - item.width)
                        y = getRand(mapView.height - item.height)
                    }
                }
            }
            // delegate: Text {
                // width: 70
                // height: 70
                // font.pixelSize: 12
                // text: model.name
                // x: getRand(mapView.width - item.width)
                // y: getRand(mapView.height - item.height)
                // opacity: 0.1
            // }
        }

        DrawArc {
            id: hightlightView

            opacity: 0.5
            anchors.centerIn: parent
            height: parent.height// *2
            width: height// *2
            size: height / 2
            totalIndex: 360
            start: 0
            end: 30 * 2
            rotation: 0
            bgColor: "GREEN"

            Timer {
                id: timer1
                interval: durationAnimation / (360)
                repeat: true
                // running: true
                onTriggered: {
                    if (hightlightView.rotation >= 360) {
                        hightlightView.rotation = 0
                    } else {
                        hightlightView.rotation += 1
                    }
                }
            }

            Timer {
                id: timer2
                interval: durationAnimation / (360)
                repeat: true
                // running: true
                onTriggered: {
                    // if (hightlightView.rotation >= 360) {
                        // hightlightView.rotation = 0
                    // } else {
                        // hightlightView.rotation += 1
                    // }
                    if (_rotation.angle>= 360) {
                        _rotation.angle = 0
                    } else {
                        _rotation.angle += 1
                    }
                }
            }


            NumberAnimation {
                id: numberAnimation
                target: hightlightView
                property: "rotation"
                duration: durationAnimation
                from: 0
                to: 360
                loops:  Animation.Infinite
            }

            RotationAnimator {
                id: animationHightLight
                target: hightlightView
                duration: durationAnimation
                // running: true
                from: 0
                to: 360
                loops: Animation.Infinite
            }

            transform: Rotation {
                id: _rotation
                origin.x: hightlightView.width/2
                origin.y: hightlightView.height/2
                // angle: () * 180
            }
        }

    }

    ListView {
        anchors.top: mapView.bottom
        anchors.left: mapView.left
        width: mapView.width
        height: width
        // orientation: ListView.Horizontal
        model: 4
        delegate: BorderButton {
            // width: mapView.width / 4
            width: mapView.width
            content.text: {
                switch (index) {
                case 0:
                    return "Rotation: " + timer1.running
                case 1:
                    return "Transform: " + timer2.running
                case 2:
                    return "NumberAnimation: " + numberAnimation.running
                case 3:
                    return "RotationAnimator: " + animationHightLight.running
                }

            }
            onMouseClicked: {
                // loadingScreen.visible = false
                console.log("clicked: " + index)
                hightlightView.rotation = 0
                _rotation.angle = 0
                if (index === 0) {
                    if (timer1.running) {
                        timer1.stop()
                        return
                    }
                    timer1.start()
                }
                if (index === 1) {
                    if (timer2.running) {
                        timer2.stop()
                        return
                    }
                    timer2.start()
                }
                if (index === 2) {
                    if (numberAnimation.running) {
                        numberAnimation.stop()
                        return
                    }
                    numberAnimation.start()
                }
                if (index === 3) {
                    if (animationHightLight.running) {
                        animationHightLight.stop()
                        return
                    }
                    animationHightLight.start()
                }

            }
        }
    }


    function getRand(max) {
        return Math.floor(Math.random() * max)
    }
}
