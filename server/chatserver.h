#pragma once

#include <QDebug>
#include <QObject>
#include <QWebSocketServer>
#include <QtWebSockets>

class ChatServer : public QObject {
    Q_OBJECT
public:
    explicit ChatServer(quint16 port, QObject* parent = nullptr);
    ~ChatServer() override;

private slots:
    void onNewConnection();
    void processMessage(const QString& message);
    void socketDisconnected();

private:
    std::unique_ptr<QWebSocketServer> m_webSocketServer;
    std::vector<std::unique_ptr<QWebSocket*>> m_clients;
};
