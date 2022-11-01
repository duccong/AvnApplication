import QtQuick 2.12
import QtQml 2.12
import "../common"
import "../delegates"


Item {
    id: container
    width: 540
    height: 810
    implicitWidth: 540

    signal itemClicked(var index)

    Column {
        anchors.fill: parent

        BorderButton {
            anchors.horizontalCenter: parent.horizontalCenter
            content.text : isAdmin ? "UPDATE" : "REFESH"
            content.font.bold: true
            onMouseClicked: {
                forceActiveFocus()
                circleProgress.startAnimation();
            }
        }

        SearchBar {
            id: searchBar
            width: parent.width
            height: 50
            onEditTextChanged: {
                console.log("Searching: " + text)
                filteredModel.setFilterString(text)
            }
        }

        ListView {
            id: tableView
            property var columnWidths: [540 * 0.7, 540 * 0.3]
            property int indexSelected: -1

            visible: !circleProgress.visible
            width : container.implicitWidth//parent.width
            height: parent.height - searchBar.height

            topMargin: columnsHeader.implicitHeight
            leftMargin: 15

            anchors.horizontalCenter: parent.horizontalCenter
            // columnWidthProvider: function (column) { return columnWidths[column]; }
            // rowHeightProvider: function (column) { return 70; }
            clip: true
            model: filteredModel//profileListModel
            // model: profileListModel

            delegate: DescriptionProfile {
                implicitWidth: tableView.width
                implicitHeight: 70
                isSelected: index === tableView.indexSelected
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        // console.log("Clicked: " + index)
                        forceActiveFocus()
                        container.itemClicked(index)
                        tableView.indexSelected = index
                        filteredModel.itemClicked(index)
                    }
                }
            }

            Rectangle { // mask the headers
                z: 2
                color: "#FFFFFF"
                width: tableView.width
                height: 50//tableView.height
            }


            Row {
                id: columnsHeader
                leftPadding: 15
                z: 3
                Repeater {
                    model: 2
                    Text {
                        width: tableView.columnWidths[modelData]
                        text: tableView.model.headerData(modelData, Qt.Horizontal)
                        color: "BLACK"
                        font.bold: true
                        font.pixelSize: 18
                        padding: 10
                        leftPadding: 30
                        verticalAlignment: Text.AlignVCenter
                    }
                }
            }
        }
    }

    CircleProgress {
        id: circleProgress
        width: 100
        height: 100
        anchors.centerIn: parent

        totalIndex: 360
        isAnimation: true
    }

    Component.onCompleted: {
        console.log("listView: onCompleted")
    }
}
