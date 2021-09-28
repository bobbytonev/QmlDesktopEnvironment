import QtQuick 2.12

import QtQuick.Controls 2.12
import QtGraphicalEffects 1.15

Pane{


 property double pages:launcher.programs.length/16

    opacity:0.8
	MouseArea{
        anchors.fill: parent
        acceptedButtons: Qt.BackButton
        onPressed:{
           popup.visible=false
        }


    }
	
	

property alias stackView: stackView

property var unistalling: false

 Popup{
	id:deleteApps
	property var appindex
	modal: true
	visible:unistalling&&!launcher.finish
	x:parent.width/2-width/2
	y:parent.height/2-height/2
	closePolicy:Popup.NoAutoClose
	
	
	
	
	Label{
		text:"Unistalling...."
		width:parent.width
		height:parent.height
	}
	
	onVisibleChanged:{
		if(!visible){ unistalling=false; }
		
	}
	onOpened:{
	var splitString=launcher.programs[appindex][2].split('/');
	launcher.eval(splitString[splitString.length-1],launcher.programs[appindex][0],launcher.programs[appindex][3])
	
		
	}
	}



    SwipeView {
        id: swipeView
        anchors.fill: parent
clip:true
    currentIndex: 1
    onCurrentIndexChanged: {
			window.view.interactive=currentIndex!==0
    }

 StackView {
        id: stackView

        Component.onCompleted: {
           stackView.push("LauncherSettings.qml");

        }
  MouseArea{
            id:mouse
            anchors.fill:parent
            acceptedButtons: Qt.BackButton
            onPressed: {

               if(stackView.children.length>1) {
                   stackView.pop();
               }
            }
        }

    }
			Repeater{
                id:pageRepeater
             model:Math.ceil(launcher.programs.length/16);
                
                  
                Item{
                    id: item1
                       
                Grid{
				
							 property int outerIndex: index
						  property var buttonPages:pages-(index+1)>=0 ? 16:((pages-(index+1))+1)*16
                          
                           id:grid
                             anchors.centerIn: parent

                            columns: 4
                            horizontalItemAlignment: Grid.AlignHCenter
                       

                               spacing: parent.height * 0.01
                           
                            Repeater{
                               id:buttonRepeater
                              model:grid.buttonPages//pages-( outerIndex)>=0 ? 16 : (pages-outerIndex)*16

                             Button{
							 id:button
							 
							 property int appIndex: grid.outerIndex*16
                                 //height: item1.height * 0.19
								height: item1.height *window.settings.appsIconSize
                                 width: height
								 icon.color:"#00000000"
								 icon.source:"image://icons/"+launcher.programs[index+appIndex][1];
								 display: window.settings.iconText ? Button.TextUnderIcon : Button.IconOnly
								 text:launcher.programs[index+appIndex][0];
								onClicked:{
								window.view.currentIndex=0
									 launch.start(launcher.programs[index+appIndex][2]);
									 
								}
								
								Menu {
							id: contextMenu
							y:button.height/2-contextMenu.width/2
							x:button.width/2-contextMenu.height/2
							MenuItem { text: "Info" 
							
							onClicked:{
							window.view.currentIndex=0
							var str =launcher.programs[index+appIndex][0]
								
								launcher.eval("Apps-page.qml",str.split(" ").join("//"));
							}
							
							}
							MenuItem { text: "Uninstall"
							
							onClicked:{
								launcher.finish=false
								unistalling=true
								deleteApps.appindex=index+appIndex
								
							}

							}
        
							}
								
								onPressAndHold:{
								
								contextMenu.open()
								
								}

}
									
									
                           }
                       }
            }
            }



        }
    }

