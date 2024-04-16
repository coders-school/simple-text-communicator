import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item {
    width: 800
    height: 600

    ColumnLayout {
        spacing: 10
        anchors.centerIn: parent

        TextField {
            id: userNameField
            placeholderText: "User Name"
        }

        TextField {
            id: passwordField
            placeholderText: "Password"
            echoMode: TextInput.Password
        }

        Button {
            text: "Login"
            onClicked: {
                var userName = userNameField.text;
                var password = passwordField.text;
                console.log("Login user: ")
                console.log("User Name:", userName, "Password:", password);
            }
        }
    }

    RowLayout {
        width: parent.width
        anchors.top: parent.top
        spacing: 10
        Button {
            text: "Back"
            onClicked: {
                stackView.pop()
            }
        }
    }
}
