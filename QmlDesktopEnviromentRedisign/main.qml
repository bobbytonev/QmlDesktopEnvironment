import QtQuick 2.12

import QtQuick.Controls 2.12
import QtGraphicalEffects 1.15
import Qt.labs.settings 1.1
ApplicationWindow {
    width: 640
    height: 480
    visible: true
    id:window


    color:"black"
    property alias popup: popup
	 property alias topPanelPopup: topPanelPopup
 property alias view: view
 property alias apps: apps
property alias settings: settings

 Component.onCompleted:{ launcher.startupApps();}


header: SwipeView{
		clip:true
        currentIndex:topPanelPopup.visible ?0:1
    onCurrentIndexChanged: {
     if(currentIndex===0) topPanelPopup.visible=true

    }
      orientation: Qt.Vertical
        Pane{background: Rectangle{color:"transparent"}}
    TopPanel{//top panel
        height: 30
        visible:!topPanelPopup.visible

    }

}


background: Rectangle{
    color: "#00000000"
    border.color: "#00000000"
    Image{
        id:background
        anchors.fill: parent
        source: "bg.png"
        visible:false

    }
    FastBlur {
            anchors.fill: background
            source: background
            radius:0 //popup.visible? 35:0
        }


}
RecentApps{//poup for recent apps

id:popup
}
TopPanelPopup{//poup for top panel

id:topPanelPopup

}



SwipeView{

 anchors.fill: parent
 id:view
orientation: Qt.Vertical
clip:true

  onCurrentIndexChanged: {

			 if(currentIndex===0) interactive=true;
           
			windowManager.setOnTop(currentIndex!=0);
    }

    Item{

    }
   Apps{id:apps}

}
Settings {
    id:settings
    property alias source:background.source
    property alias backgroundFillMode:background.fillMode
    property alias backgroundHorizontalAlignment:background.horizontalAlignment
    property alias backgroundVerticalAlignment:background.verticalAlignment
    property var appsIconSize:0.19
	property bool iconText: true


}

footer: BottomPanel{}//system buttons

}
