import QtQuick 2.0
import QtQuick.Controls 2.12
Item {
    property var naming: ["Left","Right","Center"]
      property var logic: [Image.AlignLeft,Image.AlignRight,Image.AlignHCenter];

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
						  highlighted:window.settings.backgroundHorizontalAlignment ===logic[index]
                       onClicked: {
                           //applicationWindow.sizeGrid=logic[index];
                          window.settings.backgroundHorizontalAlignment=logic[index];

                          // applicationWindow.settings.gridSpacing=spacingGrid[index];

                        window.apps.stackView.pop()

                       }
                   }
               }


           }



       }
}
