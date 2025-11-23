/*
This is a UI file (.ui.qml) that is intended to be edited in Qt Design Studio only.
It is supposed to be strictly declarative and only uses a subset of QML. If you edit
this file manually, you might introduce QML code that is not supported by Qt Design Studio.
Check out https://doc.qt.io/qtcreator/creator-quick-ui-forms.html for details on .ui.qml files.
*/

import QtQuick
import QtQuick.Controls

Item {
    id: root
    width: 800
    height: 600

    Image {
        id: back
        anchors.fill: parent
        source: "images/back.jpg"
        fillMode: Image.PreserveAspectCrop

        Rectangle {
            id: rectangle
            height: 70
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.leftMargin: 0
            anchors.rightMargin: 0
            anchors.topMargin: 0
            gradient: Gradient {
                GradientStop {
                    position: 0
                    color: "#805bcce9"
                }

                GradientStop {
                    position: 1
                    color: "#000000"
                }
                orientation: Gradient.Vertical
            }

            Text {
                id: dateText
                width: 221
                opacity: 1
                color: "#eaeaea"
                text: qsTr("Sunday, 11/23/2025 7:00")
                anchors.left: parent.left
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                anchors.leftMargin: 10
                anchors.topMargin: 0
                anchors.bottomMargin: 0
                font.pixelSize: 12
                verticalAlignment: Text.AlignVCenter
                styleColor: "#000000"
            }

            MouseArea {
                id: resBut
                x: 680
                width: 50
                height: 50
                anchors.right: parent.right
                anchors.top: parent.top
                anchors.rightMargin: 70
                anchors.topMargin: 10

                Rectangle {
                    id: rectangle2
                    color: "#27a9e3"
                    radius: 10
                    anchors.fill: parent

                    Image {
                        id: restart
                        x: 2
                        y: 2
                        anchors.fill: parent
                        anchors.leftMargin: 2
                        anchors.rightMargin: 2
                        anchors.topMargin: 2
                        anchors.bottomMargin: 2
                        source: "images/restart.png"
                        fillMode: Image.PreserveAspectFit
                    }
                }
            }

            MouseArea {
                id: shutdownBut
                x: 740
                y: 10
                width: 50
                height: 50
                anchors.right: parent.right
                anchors.top: parent.top
                anchors.rightMargin: 10
                anchors.topMargin: 10

                Rectangle {
                    id: rectangle1
                    color: "#27a9e3"
                    radius: 10
                    anchors.fill: parent

                    Image {
                        id: shutdown
                        x: 15
                        y: -5
                        anchors.fill: parent
                        anchors.leftMargin: 5
                        anchors.rightMargin: 5
                        anchors.topMargin: 5
                        anchors.bottomMargin: 5
                        source: "images/shutdown.png"
                        fillMode: Image.PreserveAspectCrop
                    }
                }
            }
        }

        Rectangle {
            id: rectangle3
            width: 360
            height: 200
            color: "#80000000"
            anchors.verticalCenterOffset: 100
            anchors.centerIn: parent

            Text {
                id: text1
                width: 55
                height: 23
                color: "#eaeaea"
                text: qsTr("Username:")
                anchors.left: parent.left
                anchors.top: parent.top
                anchors.leftMargin: 50
                anchors.topMargin: 50
                font.pixelSize: 12
            }

            Text {
                id: text2
                color: "#eaeaea"
                text: qsTr("Password:")
                anchors.left: parent.left
                anchors.top: parent.top
                anchors.leftMargin: 50
                anchors.topMargin: 90
                font.pixelSize: 12
            }

            Rectangle {
                id: rectangle4
                x: 110
                width: 200
                height: 20
                color: "#ffffff"
                radius: 5
                anchors.right: parent.right
                anchors.top: parent.top
                anchors.rightMargin: 50
                anchors.topMargin: 50

                TextInput {
                    id: textInput
                    color: "#000000"
                    text: qsTr("")
                    anchors.fill: parent
                    font.pixelSize: 12
                }
            }

            Rectangle {
                id: rectangle5
                width: 200
                height: 20
                color: "#ffffff"
                radius: 5
                anchors.right: parent.right
                anchors.top: parent.top
                anchors.rightMargin: 50
                anchors.topMargin: 90

                TextInput {
                    id: textInput1
                    text: qsTr("")
                    anchors.fill: parent
                    font.pixelSize: 12
                }
            }

            MouseArea {
                id: mouseArea
                height: 20
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.top: parent.top
                anchors.leftMargin: 50
                anchors.rightMargin: 50
                anchors.topMargin: 130

                Rectangle {
                    id: rectangle6
                    color: "#27a9e3"
                    radius: 5
                    anchors.fill: parent

                    Text {
                        id: text3
                        color: "#ffffff"
                        text: qsTr("Login")
                        anchors.fill: parent
                        font.pixelSize: 12
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                    }
                }
            }
        }

        Image {
            id: panda
            height: 100
            source: "images/panda.png"
            anchors.verticalCenterOffset: -100
            anchors.centerIn: parent
            fillMode: Image.PreserveAspectFit
        }
    }
}
