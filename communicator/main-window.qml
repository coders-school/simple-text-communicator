import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

ApplicationWindow {
    visible: true
    width: 600
    height: 400
    minimumWidth: 400
    minimumHeight: 300
    title: "Simple Text Communicator"
    color: "#f0f0f0"

    ColumnLayout {
        anchors.fill: parent
        spacing: 10

        RowLayout {
            width: parent.width
            Layout.alignment: Qt.AlignHCenter
            Button {
                text: "Login"
                Layout.alignment: Qt.AlignRight
                onClicked: {
                }
            }
            Button {
                text: "Register"
                Layout.alignment: Qt.AlignRight
                onClicked: {
                }
            }
        }
    }
}
