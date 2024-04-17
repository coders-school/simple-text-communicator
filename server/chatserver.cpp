#include "chatserver.h"

static QString getIdentifier(QWebSocket* socket) {
    return QStringLiteral("%1:%2").arg(socket->peerAddress().toString(), QString::number(socket->peerPort()));
}

ChatServer::ChatServer(quint16 port, QObject* parent)
    : QObject{parent},
      m_webSocketServer{std::make_unique<QWebSocketServer>("Chat Server", QWebSocketServer::NonSecureMode, this)} {
    if (m_webSocketServer->listen(QHostAddress::Any, port)) {
        qInfo() << "Server listening on port " << port;
        connect(&*m_webSocketServer, &QWebSocketServer::newConnection, this, &ChatServer::onNewConnection);
    }
}

ChatServer::~ChatServer() { m_webSocketServer->close(); }

void ChatServer::onNewConnection() {
    auto clientSocket = std::make_unique<QWebSocket*>(m_webSocketServer->nextPendingConnection());
    qInfo() << getIdentifier(*clientSocket) << " connected!";

    connect(*clientSocket, &QWebSocket::textMessageReceived, this, &ChatServer::processMessage);
    connect(*clientSocket, &QWebSocket::disconnected, this, &ChatServer::socketDisconnected);
    m_clients.push_back(std::move(clientSocket));
}

void ChatServer::processMessage(const QString& message) {
    const auto& clientSender = std::make_unique<QWebSocket*>(qobject_cast<QWebSocket*>(sender()));
    for (const auto& client : std::as_const(m_clients)) {
        if (client != clientSender) {
            (*client)->sendTextMessage(message);
        }
    }
}

void ChatServer::socketDisconnected() {
    auto client = std::make_unique<QWebSocket*>(qobject_cast<QWebSocket*>(sender()));
    qInfo() << getIdentifier(*client) << " disconnected!";
    if (client) {
        m_clients.erase(std::remove(std::begin(m_clients), std::end(m_clients), client), std::end(m_clients));
    }
}
