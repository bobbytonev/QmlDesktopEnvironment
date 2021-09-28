import QtQuick 2.2
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12


RowLayout{
id:row
property var buttonName:["Wi-Fi","Bluetooth","Appearance"]

    Item{
     Layout.fillWidth: true
    Rectangle{
        color: "transparent"
        width: parent.width
        height: parent.height
    }
    }


    ColumnLayout {
        spacing: 20

         Layout.fillWidth: true
       RowLayout{

           Button{
		   id:auto
               text:"Auto Brightness"
			   display:Button.TextOnly
			   
				

           }
          Slider{
			Layout.preferredWidth: grid.width-(auto.width+settingsButton.width)
			height:auto.height
		  }
		  Button{
			id:settingsButton
			icon.source:"Settings.png"
			display:Button.IconOnly
			Layout.preferredWidth:auto.height
		
			onClicked:{
				launcher.eval("","");
				topPanelPopup.close();
			}
			
		  }

       }
       MenuSeparator{
           // Layout.fillWidth: true
		   id:separator
		    Layout.preferredWidth: grid.width
       }
       SwipeView {
               id: swipeView

               clip: true

       Grid{
         id:grid
          //Layout.fillHeight: true
         anchors.centerIn: parent
            columns: buttonName.length
            rows: 1
            horizontalItemAlignment: Grid.AlignHCenter
           spacing: parent.height * 0.01
           Repeater{
              id:buttonRepeater

              model:buttonName.length

            Button{
              height: window.height *0.19
               width: height
              // height: width
				text:buttonName[index];
				icon.source:buttonName[index];
				display:Button.TextUnderIcon
				onPressAndHold:{
				//if(index===buttonName.length-1) launcher.eval("","");
				 launcher.eval(buttonName[index]+"-page.qml","");
				topPanelPopup.close();
				}

            }
           }
       }
      }
       PageIndicator {
           id: indicator

           count: swipeView.count
           currentIndex: swipeView.currentIndex

           //anchors.bottom: swipeView.bottom
           anchors.horizontalCenter: parent.horizontalCenter
       }


    }
    Item{
    Layout.fillWidth: true

    }
}


