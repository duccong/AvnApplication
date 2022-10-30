import QtQuick 2.12
import QtQml 2.12
import "../common"

Item {
    id: container
    width: 360
    height: 540
    Nulo {

    }

    Component.onCompleted: {
        console.log("listView: onCompleted")
    }
}
