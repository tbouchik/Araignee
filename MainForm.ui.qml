import QtQuick 2.7
import QtQuick.Controls 1.5
import QtQuick.Layouts 1.3

Item
{
    width: 550
    height: 480
    property alias rectPPal: rectPPal
    property alias piece9: piece9
    property alias piece8: piece8
    property alias piece7: piece7
    property alias piece6: piece6
    property alias piece5: piece5
    property alias piece4: piece4
    property alias piece3: piece3
    property alias piece2: piece2
    property alias piece1: piece1
    property alias image: image
    property alias text1: text1
    property alias mouseArea: mouseArea
    property alias couleurJ2: couleurJ2
    property alias couleurJ1: couleurJ1
    property alias joueur2: joueur2
    property alias joueur1: joueur1
    property alias mouseArea9: mouseArea9
    property alias mouseArea8: mouseArea8
    property alias mouseArea7: mouseArea7
    property alias mouseArea6: mouseArea6
    property alias mouseArea5: mouseArea5
    property alias mouseArea4: mouseArea4
    property alias mouseArea1: mouseArea1
    property alias mouseArea2: mouseArea2
    property alias mouseArea3: mouseArea3

    Text
    {
        id: joueur1
        x: 460
        y: 80
        width: 40
        height: 40
        text: qsTr("J1")
        font.bold: true
        font.family: "Times New Roman"
        fontSizeMode: Text.FixedSize
        textFormat: Text.AutoText
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 28
    }

    Text
    {
        id: joueur2
        x: 460
        y: 120
        width: 40
        height: 40
        text: qsTr("J2")
        font.family: "Times New Roman"
        font.bold: true
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 28
    }

    Rectangle
    {
        id: couleurJ1
        x: 425
        y: 85
        width: 30
        height: 30
        color: "#cccccc"
        border.color: "#000000"
        border.width: 4
    }

    Rectangle
    {
        id: couleurJ2
        x: 425
        y: 125
        width: 30
        height: 30
        color: "#000000"
        border.color: "#cccccc"
        border.width: 4
    }

    Text
    {
        id: text1
        x: 60
        y: 400
        width: 280
        height: 40
        text: vueGame.currentText
        font.italic: true
        font.family: "Times New Roman"
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 19
    }

    MouseArea
    {
        id: mouseArea
        anchors.fill: parent
    }

    Rectangle
    {
        id: rectPPal
        x: 20
        y: 20
        width: 360
        height: 360
        color: "#ffffff"

        Image
        {
            id: image
            x: 30
            y: 30
            width: 300
            height: 300
            fillMode: Image.Stretch
            source: "Grille.jpg"
        }

        Rectangle
        {
            id: piece9
            x: 310
            y: 310
            width: 40
            height: 40
            color: vueGame.gameQML[8]
            border.width: 5
            border.color: vueGame.game2QML[8]
            visible: vueGame.game3QML[8]
        }

        Rectangle
        {
            id: piece8
            x: 160
            y: 310
            width: 40
            height: 40
            color: vueGame.gameQML[7]
            border.width: 5
            border.color: vueGame.game2QML[7]
            visible: vueGame.game3QML[7]
        }

        Rectangle
        {
            id: piece7
            x: 10
            y: 310
            width: 40
            height: 40
            color: vueGame.gameQML[6]
            border.width: 5
            border.color: vueGame.game2QML[6]
            visible: vueGame.game3QML[6]
        }

        Rectangle
        {
            id: piece6
            x: 310
            y: 160
            width: 40
            height: 40
            color: vueGame.gameQML[5]
            border.width: 5
            border.color: vueGame.game2QML[5]
            visible: vueGame.game3QML[5]
        }

        Rectangle
        {
            id: piece5
            x: 160
            y: 160
            width: 40
            height: 40
            color: vueGame.gameQML[4]
            border.width: 5
            border.color: vueGame.game2QML[4]
            visible: vueGame.game3QML[4]
        }

        Rectangle
        {
            id: piece4
            x: 10
            y: 160
            width: 40
            height: 40
            color: vueGame.gameQML[3]
            border.width: 5
            border.color: vueGame.game2QML[3]
            visible: vueGame.game3QML[3]
        }

        Rectangle
        {
            id: piece3
            x: 310
            y: 10
            width: 40
            height: 40
            color: vueGame.gameQML[2]
            border.width: 5
            border.color: vueGame.game2QML[2]
            visible: vueGame.game3QML[2]
        }

        Rectangle
        {
            id: piece2
            x: 160
            y: 10
            width: 40
            height: 40
            color: vueGame.gameQML[1]
            border.width: 5
            border.color: vueGame.game2QML[1]
            visible: vueGame.game3QML[1]
        }

        Rectangle
        {
            id: piece1
            x: 10
            y: 10
            width: 40
            height: 40
            color: vueGame.gameQML[0]
            border.width: 5
            border.color: vueGame.game2QML[0]
            visible: vueGame.game3QML[0]
        }

        MouseArea
        {
            id: mouseArea9
            x: 300
            y: 300
            width: 60
            height: 60
        }

        MouseArea
        {
            id: mouseArea8
            x: 150
            y: 300
            width: 60
            height: 60
        }

        MouseArea
        {
            id: mouseArea7
            x: 0
            y: 300
            width: 60
            height: 60
        }

        MouseArea
        {
            id: mouseArea6
            x: 300
            y: 150
            width: 60
            height: 60
        }

        MouseArea
        {
            id: mouseArea5
            x: 150
            y: 150
            width: 60
            height: 60
        }

        MouseArea
        {
            id: mouseArea4
            x: 0
            y: 150
            width: 60
            height: 60
        }

        MouseArea
        {
            id: mouseArea3
            x: 300
            y: 0
            width: 60
            height: 60
        }

        MouseArea
        {
            id: mouseArea2
            x: 150
            y: 0
            width: 60
            height: 60
        }

        MouseArea
        {
            id: mouseArea1
            x: 0
            y: 0
            width: 60
            height: 60
        }
    }
}
