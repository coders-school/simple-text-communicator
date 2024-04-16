import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Window
Item {
    ColumnLayout {
        anchors.fill: parent
        spacing: 10

        Text {
            text: "Simple Text Communicator"
            font.pixelSize: 40
            color: "black"
            // anchors.horizontalCenter: parent.horizontalCenter
            Layout.alignment: Qt.AlignHCenter
        }

        //@TODO add logo here
        // Item {
        //     Layout.alignment: Qt.AlignHCenter
        //     width: parent.width / 2
        //     height: parent.height / 4

        //     Image {
        //         anchors.top: parent.bottom
        //         source: "logo.png"
        //         width: parent.width / 2
        //         height: parent.height / 4
        //     }
        // }

        RowLayout {
            anchors {
                horizontalCenter: parent.horizontalCenter
                bottom: parent.bottom

            }

            spacing: 10

            Item {
                width: parent.width / 2 - 5
                height: parent.height / 2
            }

            Item {
                width: parent.width / 2 - 5
                height: parent.height / 2

                GridLayout {
                    columns: 2
                    anchors.bottom: parent.bottom
                    anchors.bottomMargin: 20
                    anchors.horizontalCenter: parent.horizontalCenter

                    Button {
                        text: "Register"
                        Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                        width: parent.width / 15
                        height: parent.height / 40
                        font.pixelSize: 30
                        MouseArea {
                            anchors.fill: parent
                            onClicked: {
                                stackView.push(registerPage)
                            }
                        }
                    }

                    Button {
                        text: "Login"
                        Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                        width: parent.width / 15
                        height: parent.height / 40
                        font.pixelSize: 30
                        MouseArea {
                            anchors.fill: parent
                            onClicked: {
                                stackView.push(loginPage)
                           }
                        }
                    }
                }
            }
        }
    }
}
