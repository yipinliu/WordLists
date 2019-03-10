import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.3
import QtQuick.Dialogs 1.0


ApplicationWindow{
    title:"WordListsGui"
    width: 640
    height: 480
    visible: true

    RowLayout{
        x : 50; y : 35
        width: 558
        spacing: 10
        height:410
        ColumnLayout{
            spacing: 10
            TextArea{
                placeholderText: qsTr("Input words...")
                placeholderTextColor: "green"
                width: 560
                height:400
                textFormat: Text.PlainText
                wrapMode: Text.WrapAnywhere
                clip: false
                opacity: 1
                verticalAlignment: Text.AlignVCenter
            }

        }
        ColumnLayout{
            spacing:8
            RowLayout{

                RadioButton{
                    text: qsTr("最多单词")
                    checked: true
                }
                RadioButton{
                    text: qsTr("最多字符")
                }
            }
            RowLayout{
                Label{
                    text: qsTr("首字符")
                }

                TextField{
                    placeholderText: qsTr("type the head char")
                    placeholderTextColor: "green"
                }
            }
            RowLayout{
                Label{
                    text: qsTr("尾字符")
                }
                TextField{
                    placeholderText: qsTr("type the tail char")
                    placeholderTextColor: "green"
                }
            }
            RowLayout{
                Label{
                    text: qsTr("单词数")

                }
                SpinBox{
                    wheelEnabled: false
                    editable: true
                    value: 0
                    from:0
                }
            }
        }
        ColumnLayout{
            FileDialog{
                id:fileDialog
                title:"Please choose a file"
                onAccepted: {
                    console.log("You choose: "+fileDialog.fileUrl)
                    Qt.quit()
                }
                onRejected: {
                    console.log("Canceled")
                    Qt.quit()
                }
            }
            Button{
                text: qsTr("导入文件")
                onClicked: fileDialog.open()
            }
            Button{
               text: qsTr("输出")
               onClicked: fileDialog.open()
            }
        }
    }
}
