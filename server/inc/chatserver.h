#ifndef CHATSERVER_H
#define CHATSERVER_H

#include <QAbstractSocket>
#include <QDebug>
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QUrl>
#include <QtHttpServer/QHttpServer>
#include <QtHttpServer/QHttpServerRequest>
#include <QtHttpServer/QHttpServerResponse>

constexpr uint16_t serverPort = 3000;

class ChatServer : public QObject {
    Q_OBJECT
public:
    explicit ChatServer(QObject *parent = nullptr);

signals:

public slots:

private:

};

#endif  // CHATSERVER_H
