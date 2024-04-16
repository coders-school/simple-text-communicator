import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item {
    width: 800
    height: 600

    ColumnLayout {
        anchors.centerIn: parent
        spacing: 10

        TextField {
            id: userNameField
            placeholderText: "User Name"
        }

        TextField {
            id: passwordField
            placeholderText: "Password"
            echoMode: TextInput.Password
        }

        TextField {
            id: emailField
            placeholderText: "Email"
        }

        Button {
            text: "Register"
            onClicked: {
                var userName = userNameField.text;
                var password = passwordField.text;
                var email = emailField.text;
                console.log("Register user: ")
                console.log("User Name:", userName, "Password:", password, "email:", email);
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
