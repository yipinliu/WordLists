import QtQuick 2.0

Rectangle {
    id:btn
    width:100
    height:62
    color: "teal"
    border.color: "aqua"
    border.width: 3
    Text {
        id:label
        anchors.centerIn: parent
        text: qsTr("text")
        font.pointSize: 16
    }

}
