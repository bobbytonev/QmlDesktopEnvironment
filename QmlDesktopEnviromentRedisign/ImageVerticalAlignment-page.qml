import QtQuick 2.0
import QtQuick.Controls 2.12
Item {
    property var naming: ["Top","Bottom","Center"]
      property var logic: [Image.AlignTop,Image.AlignBottom,Image.AlignVCenter];

   ListView{

       id:view
       anchors.fill: parent
       model:1
           delegate: Column{
               Repeater{
                   model:naming.length
                   Button{
                       text:naming[index];
                       width: view.width
                       height: 74
                       
						highlighted:window.settings.backgroundVerticalAlignment ===logic[index]
                       onClicked: {

                           //applicationWindow.sizeGrid=logic[index];
                            window.settings.backgroundVerticalAlignment=logic[index];
//applicationWindow.background.verticalAlignment=logic[index];

                          window.apps.stackView.pop()

                       }
                   }
               }


           }



       }
}
