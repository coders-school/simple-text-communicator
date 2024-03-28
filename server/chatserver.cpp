#include "chatserver.h"

static QString getIdentifier(QWebSocket* socket)
{
    return QStringLiteral("%1:%2").arg(socket->peerAddress().toString(),
                                       QString::number(socket->peerPort()));
}

ChatServer::ChatServer(quint16 port, QObject *parent)
    : QObject{parent},
      m_webSocketServer{new QWebSocketServer("Chat Server",
                            QWebSocketServer::NonSecureMode,
                            this)}
{
    if(m_webSocketServer->listen(QHostAddress::Any, port))
    {
        qInfo() << "Server listening on port " << port;
        connect(&*m_webSocketServer, &QWebSocketServer::newConnection, this, &ChatServer::onNewConnection);
    }
}

ChatServer::~ChatServer(){
    m_webSocketServer->close();
}

void ChatServer::onNewConnection()
{
    auto clientSocket = m_webSocketServer->nextPendingConnection();
    qInfo() << getIdentifier(clientSocket) << " connected!";
    clientSocket->setParent(this);

    connect(clientSocket, &QWebSocket::textMessageReceived, this, &ChatServer::processMessage);
    connect(clientSocket, &QWebSocket::disconnected, this, &ChatServer::socketDisconnected);

    m_clients << clientSocket;
}

void ChatServer::processMessage(const QString& message)
{
    QWebSocket* clientSender = qobject_cast<QWebSocket *>(sender());
    for (QWebSocket* client : std::as_const(m_clients)) {
        if (client != clientSender)
            client->sendTextMessage(message);
    }
}

void ChatServer::socketDisconnected()
{
    QWebSocket* client = qobject_cast<QWebSocket*>(sender());
    qInfo() << getIdentifier(client) << " disconnected!";
    if(client)
    {
        m_clients.removeAll(client);
        client->deleteLater();
    }
}
