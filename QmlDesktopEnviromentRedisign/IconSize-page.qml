import QtQuick 2.0
import QtQuick.Controls 2.12
Item {
    property var naming: ["Small","Medium","Large"]
      property var logic: [0.15,0.19,0.25];

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
						highlighted: logic[index]===Number(settings.appsIconSize)
                       onClicked: {
                           window.settings.appsIconSize=logic[index];
                           window.apps.stackView.pop()

                       }
                   }
               }


           }



       }
}
