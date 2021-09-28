import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.11
import QtQuick.Controls 2.15
import QtGraphicalEffects 1.12
RoundButton {
    id: button
    width: 32

    property alias imageSource: image.source

    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
    Layout.preferredHeight: 48
    Layout.preferredWidth: 48
  Image{
        id: image
        anchors.fill: parent
        horizontalAlignment: Image.AlignHCenter
        verticalAlignment: Image.AlignVCenter
        mipmap: true
        anchors.bottomMargin: 10
        anchors.rightMargin: 10
        anchors.leftMargin: 10
        anchors.topMargin: 10
        antialiasing: true
        autoTransform: false
        fillMode: Image.Stretch
        //visible: false
        ColorOverlay {
                anchors.fill: image
                source: image
                color: msg.colors[1]
            }


    }
}


/*##^##
Designer {
    D{i:0;formeditorZoom:8;height:48;width:48}
}
##^##*/
