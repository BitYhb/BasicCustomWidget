import QtQuick 2.0
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
AbstractDialog {
    id: icondialog
    width: 374
    height: 200
    //virtual middleItem
    middItem:Item{
        id:_contenItem
        Rectangle{
            anchors.fill: parent
            color: "#242527"
        }
        Rectangle{
            color: "transparent"
            anchors.top:parent.top
            anchors.topMargin: 40
            anchors.horizontalCenter: parent.horizontalCenter

            height: infoLabel.implicitHeight

            width: iconImage.implicitWidth + infoLabel.width
            RowLayout{
                id: textAndIconLayout
                spacing: 7
                Image{
                    id: iconImage
                    height: 16
                    width: 16
                    Layout.fillWidth: true
                    source: "qrc:/resource/tip_info.svg"
                    sourceSize: Qt.size(width,height)
                    Layout.alignment: Qt.AlignTop
                    Layout.topMargin: 3
                }
                Label{
                    id: infoLabel
                    text: "iconDialog.infoText,infoText,infoText,infoText,infoText,infoText"
                    Layout.fillWidth: true
                    Layout.maximumWidth: 300
                    wrapMode:Text.WrapAnywhere
                    color: "#FFFFFF"
                    font.pixelSize: 15
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
            }
        }
    }
    foolterItem:Item{
        id: _footer
        implicitWidth: parent.width
        implicitHeight: 66
        Rectangle{
            anchors.fill: parent
            color: "#242527"
        }

        Rectangle{
            anchors.horizontalCenter: parent.horizontalCenter
            border.width: 1
            border.color: "red"
            width: acceptBtn.width + cancelBtn.width
            RowLayout{
                anchors.fill: parent
                spacing: 32
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 36
                Button{
                    id:acceptBtn
                    Layout.preferredWidth: 132
                    Layout.preferredHeight: 32
                    text: "确认"
                    background:Rectangle{
                        color: "#23E5C5"
                        opacity: 0.8
                    }
                    onClicked: {
                        close();
                    }
                }
                Button{
                    id:cancelBtn
                    Layout.preferredWidth: 132
                    Layout.preferredHeight: 32
                    background:Rectangle{
                        color: "gray"
                        opacity: 0.8
                    }
                    text: "取消"
                    onClicked: {
                        close()
                    }
                }
            }
        }
    }
}
