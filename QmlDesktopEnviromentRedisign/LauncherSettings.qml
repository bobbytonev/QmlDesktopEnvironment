import QtQuick 2.0
import QtQuick.Controls 2.2
import QtQuick.Dialogs 1.3

Item {
     property var naming: ["Icon size","Image vertical alignment","Image horizontal alignment","Image fill mode"]
height:parent.height


property var pageNaming: ["IconSize","ImageVerticalAlignment","ImageHorizontalAlignment","ImageFillMode"] //can be improved


    FileDialog{
            id: fileDialog
            title: "Please choose a file"
            folder: shortcuts.home
            onAccepted: {
               window.settings.source=fileDialog.fileUrl
            }
		modality: Qt.NonModal
			onRejected: {
                fileDialog.close()
                fileDialog.setVisible(false)
            }



    }


    ListView{

        id:view
        anchors.fill: parent
        clip:true
        model:1
        delegate: Column{
                Button{
                        text:naming[index];
                        width: view.width
                        height: 74
                        onClicked: {
                             window.apps.stackView.push(pageNaming[index]+"-page.qml");
                        }
                    }

                //CheckBox{
                  //  text:"Fit to parent"
                  //  id:control
                   // width: parent.width
                  //  height: 74;
                    //checked: applicationWindow.settings.gridFill
                  //  onCheckedChanged: {
                      // if(applicationWindow.settings.gridFill!==checked)
                      //  applicationWindow.settings.gridFill=control.checked
                   // }
               // }
				
				
				Switch{
                    text:"Show icon text"
                    checked:window.settings.iconText
                     width: parent.width
                     height: 74;
                     onCheckedChanged: {
							window.settings.iconText=checked
                       }

                }

                MenuSeparator{
                    width: view.width
                }
				Button{
                    text:"Background image"
                     width: view.width
                     height: 74
                     onClicked: {
					    fileDialog.close()
                        fileDialog.open();
                     }
                }

                Repeater{
                    model:3
                    Button{
                        text:naming[index+1]
                        width: view.width
                        height: 74
                        onClicked: {
                             window.apps.stackView.push(pageNaming[index+1]+"-page.qml");
                        }
                    }
                }

            }



        }
}
