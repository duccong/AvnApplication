import QtQuick 2.0
import QtQml 2.12

Item {
    id: container
    property int  totalIndex: 360//TotalIndex
    property real start: -0.5
    property real end: -0.5 // -0.5 -> 1.5
    property color bgColor: "#00FF00"
    property int size: width / 4
    property alias isAnimation: timer3s.running
    property int duration: 3000
    property real loop: duration/60
    property real step: 2 / loop
    visible: isAnimation
    property bool drawPie: false
    property bool isFill: false
    property bool isRepeat: false

    // opacity: isAnimation ? 1 : 0
    // Behavior on opacity {PropertyAnimation {duration: container.duration/2}}

    function startAnimation() {
        console.log("Start animation: " + isAnimation)
        if (!isAnimation) {
            end = start
            isAnimation = true
        }
    }

    Timer {
        id: timer3s
        repeat: true
        interval: loop
        // running: isAnimation

        property int count: -1
        onRunningChanged: {
            console.log("running: " + running)
            if (running) {
                count = 0
            }
        }

        onTriggered: {
            count++
            if (count > loop - 1) {
                count = -1
                // container.end = container.start
                if (!isRepeat) {
                    timer3s.stop()
                }

            }
            container.end += step
            if (drawPie) {
                container.start = container.end - step
            }

            canvas.requestPaint()
        }
    }

    onEndChanged: {
        if (!isAnimation) {
            return;
        }

        // canvas.requestPaint()
        // var red = ((end-totalIndex/3)/(totalIndex*2))*255
        // bgColor = rgbToHex(red, 255 - red, 0)
//        if (end <= start + totalIndex*2/3) {
//            state = "slow"
//        } else if (end <= start + totalIndex*4/3) {
//            state = "normal"
//        } else {
//            state = "fast"
//        }
    }

    Canvas {
        id: canvas
        anchors.fill: parent
        onPaint: {
            var ctx = getContext("2d");
            ctx.reset();

            var centreX = width / 2
            var centreY = height / 2

            ctx.beginPath();
            // ctx.strokeStyle = bgColor
            // ctx.lineWidth = 10
            // ctx.beginPath()
            // ctx.moveTo(centreX, centreY)
            ctx.arc(centreX, centreY, size, Math.PI * start, Math.PI * end, false)
            // ctx.arc(centreX, centreY, size, 0, Math.PI * end, false)
            if (drawPie) {
                ctx.lineTo(centreX, centreY)
            }

            ctx.stroke()
            if (isFill) {
                ctx.fillStyle = bgColor
                ctx.fill()
            }
        }
    }

//    states: [
//        State {
//            name: "slow"
//            PropertyChanges { target: container; bgColor: "#c0e218"}
//        },
//        State {
//            name: "normal"
//            PropertyChanges { target: container; bgColor: "#f37121"}
//        },
//        State {
//            name: "fast"
//            PropertyChanges { target: container; bgColor: "#c70039"}
//        }
//    ]
    function rgbToHex(r, g, b) {
      return "#" + ((1 << 24) + (r << 16) + (g << 8) + b).toString(16).slice(1);
    }
}
