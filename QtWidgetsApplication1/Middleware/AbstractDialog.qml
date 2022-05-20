import QtQuick 2.0
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
Dialog {
    id: abstractDialog
    x: (rootWindow.width - width) / 2
    y: (rootWindow.height - height) / 2
    padding:0
    property Item headItem: head
    property Item middItem: middleItem
    property Item foolterItem: foolter

    header: abstractDialog.headItem
    contentItem: abstractDialog.middItem
    footer: abstractDialog.foolterItem

    //head
    Item{
        id: head
        height: 21
        width: parent.width
        Rectangle{
            id: header
            anchors.fill: parent
            color: "#1D1F22"
            MouseArea{
                anchors.fill: parent
                property real lastX: 0
                property real lastY: 0
                onPressed: {
                    lastX = mouse.x
                    lastY = mouse.y
                }
                onPositionChanged: {
                    if(pressed){
                        abstractDialog.x += mouse.x - lastX
                        abstractDialog.y += mouse.y - lastY
                    }
                }
            }
            Image{
                id:topImage
                source: "qrc:/resource/top_slider.svg"
                sourceSize: Qt.size(parent.width,2)
            }
            RowLayout{
                anchors.fill: parent
                anchors.margins: 5
                Image{
                    source: "qrc:/resource/small_logo.svg"
                    Layout.preferredHeight: 14
                    Layout.preferredWidth: 12
                    sourceSize: Qt.size(12,14)
                }
                Image{
                    z: header.z + 1
                    source: "qrc:/resource/close.svg"
                    Layout.alignment: Qt.AlignRight
                    Layout.preferredHeight: 10
                    Layout.preferredWidth: 10
                    sourceSize: Qt.size(10,10)
                    MouseArea{
                        anchors.fill: parent
                        onClicked: {
                            abstractDialog.close()
                        }
                    }
                }
            }
        }
    }
    //content
    Item{
        id: middleItem
        width: parent.width
        height: parent.height - headItem.width
        Rectangle{
            anchors.fill: parent
            color: "#242527"
        }
    }
    //foolter
    Item{
        id: foolter
    }
}
