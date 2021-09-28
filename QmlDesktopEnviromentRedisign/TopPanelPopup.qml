import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.3
Popup {
 id:popup
   
	 property alias label: label
    MouseArea{
        anchors.fill: parent
        acceptedButtons: Qt.BackButton
        onPressed:{
           popup.close()
        }


    }
    onVisibleChanged: {
	
		
			if(!window.popup.visible&&window.view.currentIndex===0){
			windowManager.setAllwaysOnTop(popup.visible);
			
			}
			
			
	 
    }

    width: view.width
    height:view.height
    ColumnLayout{
        id: column
anchors.fill: parent
spacing: 20
        Label{
            id:label
           
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
			Layout.fillWidth: true
            font.pointSize: 40
           
		   textFormat: Text.RichText
		   
			 
            Timer{
             interval: 500; running:true ; repeat: true
              onTriggered: {
               var today = new Date();
               var s =Qt.formatDateTime(new Date(),"hh:mm");
                   var d =Qt.formatDateTime(new Date(),"ddd, MMM, yy");
                  if(label.text!==s)
                label.text =s+"<html><div style='font-size:20px;'>"+d+"</div></html>";
                }

               }
            Component.onCompleted: {
                var today = new Date();
                var s =Qt.formatDateTime(new Date(),"hh:mm");
                    var d =Qt.formatDateTime(new Date(),"ddd, MMM, yy");
                 label.text =s+"<html><div style='font-size:20px;'>"+d+"</div></html>";
            }

        }
     
        TabBar {
            id: tabBar
            Layout.fillWidth: true
           // anchors.centerIn: parent
            //position: TabBar.Footer
            currentIndex: swipeView.currentIndex
            background: Rectangle{
				color:"transparent"
            }

            TabButton {
                text: qsTr("Quick settings")
				

            }
            TabButton {
                text: qsTr("Notification")


            }

        }
        SwipeView {
            id: swipeView
            //height: parent.height
           // anchors.fill: parent

            Layout.fillWidth: true
            Layout.fillHeight: true


            clip:true

           // anchors.topMargin: 64
            //anchors.bottomMargin: tabBar.height
            currentIndex: tabBar.currentIndex
            QuickToggle{
	
            }
            Rectangle{
                
            }




        }





    }




}

/*##^##
Designer {
    D{i:0;formeditorZoom:1.5}
}
##^##*/
