import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.2
Popup {
     id: popup
     width: view.width
     height:view.height
background.opacity:0.8
         
	   focus: true
        closePolicy: Popup.NoAutoClose
       
        MouseArea{
            anchors.fill: parent
            acceptedButtons: Qt.BackButton
            onPressed:{
               popup.visible=false
            }


        }
	
		onVisibleChanged: {
		 windowManager.setAllwaysOnTop(popup.visible);
		 if(visible){
		 window.topPanelPopup.visible=false;
		 }
		}

        ListView {
            id: listView
                anchors.fill: parent
                spacing:20
                orientation: ListView.Horizontal

            removeDisplaced: Transition {
                        NumberAnimation { property: "x"; duration: 150 }
                    }
            populate: Transition {
                        NumberAnimation { property: "x"; duration: 100 }
                    }
            model:windowManager.data.length
            delegate: SwipeView{
				property var viewIndex:listView.currentIndex ;
				id:swipeView;
                anchors.verticalCenter: parent.verticalCenter

              // height:layout.height
                 orientation:Qt.Vertical
                 clip:false
                 currentIndex: 1
                 onCurrentIndexChanged: {
					
                    if(currentIndex!=1){
						windowManager.killWindow(windowManager.data[index][0]); 
						if(listView.count<=1){ popup.visible=false;}	
					
					}
                 }
				

        Item{}

                Program{
                    id:control
                    //height:50
                    //text:windows.data[index]+""
                   // name:windowManager.getName(index);
					//windowId:windowManager.data[index]
					windowId:windowManager.data[index][0]
					name:windowManager.data[index][1]
					windowIndex:index
		

                }
                Item{}

                }
        }
		Button{
			display:Button.TextOnly
			text:"REMOVE ALL"
			visible:listView.count>=1
			onClicked:{
				windowManager.killAllWindows();
				popup.visible=false;
			}
			
		}
		Label{
			text:"Nothing to show here"
			x:parent.width/2-width/2
			y:parent.height/2-height/2
			visible:listView.count===0
			font.pixelSize: 22
		}





    }
