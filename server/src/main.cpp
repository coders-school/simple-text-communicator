#include <QCoreApplication>

#include "../inc/chatserver.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    ChatServer server;
    server.start();

    return a.exec();
}
