import QtQuick 2.0
import QtQuick.Controls 2.12

Row {
spacing: 10;


    ListView{
        id:notifications
        width: parent.width/2-(time.width+parent.spacing)

        height: parent.height
        layoutDirection: Qt.RightToLeft
        orientation: ListView.Horizontal
        
        clip:true
        
    }

    Label{
        id:time
        height: parent.height
        text:window.topPanelPopup.label.text.split("<")[0];
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font.bold: true
		 style:Text.Outline
		 color:"white"


    }
    ListView{
        id:quickSettings
        width:notifications.width
        height: parent.height
        clip:true
        spacing:10
        orientation: ListView.Horizontal
        layoutDirection: Qt.LeftToRight
        
    }

}

/*##^##
Designer {
    D{i:0;formeditorZoom:6}
}
##^##*/
