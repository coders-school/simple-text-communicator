#pragma once

#include <QObject>
#include <QWebSocketServer>
#include <QtWebSockets>
#include <QDebug>

class ChatServer : public QObject
{
    Q_OBJECT
public:
    explicit ChatServer(quint16 port, QObject *parent = nullptr);
    ~ChatServer() override;

private slots:
    void onNewConnection();
    void processMessage(const QString& message);
    void socketDisconnected();

private:
    QWebSocketServer* m_webSocketServer;
    QList<QWebSocket*> m_clients;
};
