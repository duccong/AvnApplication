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

    ColumnLayout {
        Nulo {

        }
        anchors.fill: parent
        Loader {
            id: loaderDetail
            source: "qrc:/qmlSource/components/DetailProfile.qml"
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.preferredHeight: 0.6
            onLoaded: {
                console.log("DetailComponent is loaded")
            }
        }

        Loader {
            id: loaderListMember
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.preferredHeight: 0.4
            source: "qrc:/qmlSource/components/ListViewWithSearch.qml"
            onLoaded: {
                console.log("ListMemberComponent is loaded")
                item.anchors.fill = loaderListMember
            }
        }
    }

}
