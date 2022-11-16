import QtQuick 2.0

Item {
    id: container
    property int  totalIndex: objectStyler.kphTotalIndex
    property int start: totalIndex * 2/3
    property int end: totalIndex/3
    property color bgColor: "#FF000000"
    property int size: width / 2.5

    // onEndChanged: {
        // if (!isAnimation) {
            // return;
        // }

        // canvas.requestPaint()
        // var red = ((end-totalIndex/3)/(totalIndex*2))*255
        // bgColor = rgbToHex(red, 255 - red, 0)
    // }

    Canvas {
        id: canvas
        anchors.fill: parent
        onPaint: {
            var ctx = getContext("2d");
            ctx.reset();

            var centreX = 0; //width / 2;
            var centreY = 0; //height / 2;

            ctx.beginPath();
            ctx.fillStyle = bgColor;
            ctx.moveTo(centreX, centreY);
            ctx.arc(centreX, centreY, size, Math.PI * start/totalIndex, Math.PI * end/totalIndex, false);
            ctx.lineTo(centreX, centreY);
            ctx.fill();
        }
    }

    function rgbToHex(r, g, b) {
      return "#" + ((1 << 24) + (r << 16) + (g << 8) + b).toString(16).slice(1);
    }
}
