#ifndef CHATSERVER_H
#define CHATSERVER_H

#include <QCoreApplication>
#include <QtHttpServer/QHttpServer>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QUrlQuery>
#include <QHttpServerResponder>
#include "message.h"

constexpr uint16_t serverPort = 2000;

class ChatServer : public QObject {
    Q_OBJECT
public:
    explicit ChatServer(QObject *parent = nullptr);

signals:

public slots:

private:
    QHttpServer m_server;
    QVector<Message> m_messages;
};

#endif  // CHATSERVER_H
