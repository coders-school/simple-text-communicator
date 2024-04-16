import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

ApplicationWindow {
    visible: true
    width: 800
    height: 600
    title: "Login/Register"

    StackView {
        id: stackView
        anchors.fill: parent

        initialItem: startPage

        Component {
            id: startPage
            StartPage {}
        }

        Component {
            id: registerPage
            RegisterPage {}
        }

        Component {
            id: loginPage
            LoginPage {}
        }
    }
}
