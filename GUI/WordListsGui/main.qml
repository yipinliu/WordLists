import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.3
import QtQuick.Dialogs 1.0

import libbackend 1.0


ApplicationWindow{
    title:"WordListsGui"
    width: 640
    height: 480
    visible: true

    BackEnd{
        id:backend
    }

    RowLayout{
        x : 50; y : 35
        width: 558
        spacing: 10
        height:410
        ColumnLayout{
            spacing: 10
            TextArea{
                id: text
                placeholderText: qsTr("Input words...")
                placeholderTextColor: "green"
                width: 560
                height:400
                textFormat: Text.PlainText
                wrapMode: Text.WrapAnywhere
                clip: false
                opacity: 1
                verticalAlignment: Text.AlignVCenter
                onTextChanged: backend.words = placeholderText
            }

        }
        ColumnLayout{
            spacing:8
            RowLayout{
                RadioButton{
                    id:w
                    text: qsTr("最多单词")
                    checked: true

                }
                RadioButton{
                    id:c
                    text: qsTr("最多字符")
                }
            }
            RowLayout{
                Label{
                    text: qsTr("首字符")
                }

                TextField{
                    id:h
                    placeholderText:  qsTr("type the head char")
                    placeholderTextColor: "green"
                    onTextChanged: backend.h = placeholderText
                }
            }
            RowLayout{
                Label{
                    text: qsTr("尾字符")
                }
                TextField{
                    id: t
                    placeholderText: qsTr("type the tail char")
                    placeholderTextColor: "green"
                    onTextChanged: backend.t = placeholderText
                }
            }
            RowLayout{
                Label{
                    text: qsTr("单词数")

                }
                SpinBox{
                    id: n
                    wheelEnabled: false
                    editable: true
                    value: 0
                    from:0

                }
            }
            RowLayout{
                FileDialog{
                    id:fileDialog
                    title:"Please choose a file"
                    onAccepted: backend.file = fileUrl
                    onRejected: {
                        console.log("Canceled")
                    }
                }
                Button{
                    text: qsTr("导入文件")
                    onClicked: fileDialog.open()
                }
                Button{
                   text: qsTr("输出")
                   onClicked: {
                       console.log("success")
                   }
                }
            }
        }

    }
}
