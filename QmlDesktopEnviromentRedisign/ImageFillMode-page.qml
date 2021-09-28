import QtQuick 2.0
import QtQuick.Controls 2.12
Item {
    property var naming: ["Stretch","Preserve aspect fit","Preserve aspect crop","Tile","Tile vertically","Tile horizontally","Pad"]
      property var logic: [Image.Stretch,Image.PreserveAspectFit , Image.PreserveAspectCrop ,Image.Tile ,Image.TileVertically ,Image.TileHorizontally ,Image.Pad];

     ListView{

       id:view
       anchors.fill: parent
       clip:true
       model:1
           delegate: Column{
               Repeater{
                   model:naming.length
                   Button{
                       text:naming[index];
                       width: view.width
                       height: 74
						highlighted: window.settings.backgroundFillMode ===logic[index]
                       onClicked: {

                           window.settings.backgroundFillMode=logic[index];


                                window.apps.stackView.pop()

                       }
                   }
               }


           }



       }
}
