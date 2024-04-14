#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    const QUrl url(QStringLiteral("qrc:/qt/qml/main/main-window.qml"));
    engine.load(url);
    if (engine.rootObjects().isEmpty())
    {
        return -1;
    }
    return app.exec();
}
