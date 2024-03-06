#include "../inc/chatserver.h"

ChatServer::ChatServer(QObject* parent) : QObject{parent} {
    connect(&server, &QTcpServer::newConnection, this, &ChatServer::newConnection);
}

void ChatServer::start() {
    if (!server.listen(QHostAddress::Any, serverPort)) {
        qWarning() << server.errorString();
        return;
    }
    qInfo() << "Server listening on " << server.serverAddress().toString() << ":" << serverPort;
}

void ChatServer::quit() {
    server.close();
}

void ChatServer::newConnection() {
    QTcpSocket* socket = server.nextPendingConnection();
    connect(socket, &QTcpSocket::disconnected, this, &ChatServer::disconnected);
    connect(socket, &QTcpSocket::readyRead, this, &ChatServer::readyRead);

    qInfo() << "Someone connected to the server";
}

void ChatServer::disconnected() {
    QTcpSocket* socket = qobject_cast<QTcpSocket*>(sender());
    qInfo() << "Disconnected" << socket;
}

void ChatServer::readyRead() {
    QTcpSocket* socket = qobject_cast<QTcpSocket*>(sender());
    qInfo() << "readyRead" << socket;
    qInfo() << socket->readAll();
}
