import QtQuick 2.2
import QtQuick.Controls 2.10
import QtQuick.Layouts 1.2

RowLayout {
            id: buttonLayout
            width: parent.width
            spacing: 0
        
            AnimationButton{
                id:backButton
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                imageSource: "Back-15.png"
                onClicked: {
                   // Qt.quit();
                    windowManager.back();
					
					//window.view.currentIndex=0;
                }


        }

        AnimationButton {
            id: animationButton
            imageSource: "Home-35.png"

            onClicked: {
                    //Qt.quit();
                    windowManager.minimize();
					window.popup.visible=false;
					window.topPanelPopup.visible=false;
					window.view.currentIndex=0;
                }
        }

        AnimationButton {
            id: animationButton1
            imageSource: "Apps-15.png"
			 onClicked: {
                //window.viewCurrentIndex=1;
				window.view.currentIndex=0;
                if(window.popup.visible){
                     window.popup.visible=false;
					
               } else{
                    window.popup.visible=true;
					
					}
            }
        }

        
		
		
}

