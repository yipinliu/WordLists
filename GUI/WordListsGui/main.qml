import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.3
import QtQuick.Dialogs 1.0

import libbackend 1.0


ApplicationWindow{
    title:"WordListsGui"
    id:root
    width: 640
    height: 480
    visible: true

    BackEnd{
        id:backend
    }
    Popup{
        id: output
        width:400
        height: 300
        anchors.centerIn: parent
        closePolicy: Popup.CloseOnEscape|Popup.CloseOnReleaseOutside|Popup.CloseOnPressOutsideParent
        ColumnLayout{
            anchors.fill: parent
            spacing: 1
            ColumnLayout{
                Rectangle{
                    border.color: "black"
                    anchors.fill: parent
                    TextArea{
                        anchors.fill: parent
                        id:output_text
                        placeholderTextColor: "black"
                        placeholderText: backend.result
                    }
               }
            }
            ColumnLayout{
                RowLayout{
                    Label{
                        text: qsTr("文件名")
                    }

                    TextField {
                        id: filePath
                        text: dirPath+"/a.txt"
                    }
                }

                RowLayout{
                    Button{
                        text: qsTr("退出")
                        onClicked: output.close()
                    }
                    Button{
                        text: qsTr("保存")
                        onClicked: {


                        }
                    }
                }
            }

        }
        /*
        Popup{
            id:svFile
            closePolicy: Popup.CloseOnEscape|Popup.CloseOnReleaseOutside
            RowLayout{
                Label{
                    text: qsTr("输入文件名")
                }

                Button{
                    text: qsTr("保存")
                    onClicked: {

                    }
                }
            }
        }
        */

    }

    RowLayout{
        x : 50; y : 35
        width: 558
        spacing: 10
        height:410
        ColumnLayout{
            Rectangle{
                id: rectangle
                anchors.fill: parent

                border.color:"black"
                TextArea{
                    id: text
                    anchors.fill: parent
                    placeholderText: backend.words
                    placeholderTextColor: "green"
                    textFormat: Text.PlainText
                    wrapMode: Text.WrapAnywhere
                    clip: false
                    opacity: 1
                    //verticalAlignment: Text.AlignVCenter
                    onTextChanged: backend.words = placeholderText
                }
            }
        }
        ColumnLayout{
            spacing:8
            RowLayout{
                RadioButton{
                    id:w
                    text: qsTr("最多单词")
                    checked: backend.isw

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
                    placeholderText:  backend.h
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
                    placeholderText: backend.t
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
                       backend.doJob();
                       output.open();
                   }
                }
            }
        }


}
}
