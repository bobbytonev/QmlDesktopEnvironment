import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.11

Column {
id:column
signal clicked()
property var name
property var windowId 
property var windowIndex
onYChanged: {
    column.clicked()
}

    Row {
        id: row
        width: 200
        height: 50
        spacing: 20

        Label {
            id: label
            text:name;
            width:row.width-(control.width+control.radius/2)


        }

        RoundButton {
            id: control

            anchors.verticalCenter: parent.verticalCenter

                icon.source:"destroy.png"



        }


    }

    Frame {
        MouseArea{
            id:area
           anchors.fill: parent
           onClicked: {
               windowManager.restoreWindow(column.windowId,windowIndex);
			   window.popup.visible=false;
			   console.log("HERE");
           }


        }

        id: frame
        width: 200
        height: 200
			Image {
                id: image1
                width: 64
                height: 64
                anchors.verticalCenter: parent.verticalCenter
                source: "image://icons/"+name;
                anchors.horizontalCenter: parent.horizontalCenter
                fillMode: Image.PreserveAspectFit
            }
    }










}
