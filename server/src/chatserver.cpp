#include "../inc/chatserver.h"

ChatServer::ChatServer(QObject* parent) : QObject{parent} {
    // Defineserver/src/chatserver.cpp a route for sending messages
    m_server.route("/send_message", [this](const QHttpServerRequest& request, QHttpServerResponder&& responder) {
        // Parse JSON payload from request
        QJsonDocument doc = QJsonDocument::fromJson(request.body());
        QJsonObject obj = doc.object();

        // Extract sender, receiver, and message content from JSON
        QString sender = obj["sender"].toString();
        QString receiver = obj["receiver"].toString();
        QString content = obj["content"].toString();

        // Create a new message and add it to the messages vector
        m_messages.append(Message(receiver, sender, content));

        // Send response indicating success

        responder.writeStatusLine(QHttpServerResponder::StatusCode::Ok);
        responder.writeBody(doc.toJson());
        responder.writeBody("Message sent successfully\n");
    });

    // Define a route for retrieving messages for a specific user
    m_server.route("/get_messages", [this](const QHttpServerRequest &request, QHttpServerResponder&& responder) {
        // Extract user name and sender name from the URL
        QUrlQuery query(request.url().query());

        QString user = query.queryItemValue("user");
        QString sender = query.queryItemValue("sender");

        // Extract password from query parameters
        QString password = query.queryItemValue("password");

        // Authenticate user (example: check if password is correct)
        if (password != "correct_password") {
            responder.writeStatusLine(QHttpServerResponder::StatusCode::Unauthorized);
            responder.writeBody("Unauthorized: Incorrect password\n");
            return;
        }

        // Filter messages for the specified user and sender
        QJsonArray messageArray;
        for (const Message& message : m_messages) {
            if (message.getReceiver() == user && (sender.isEmpty() || message.getSender() == sender)) {
                QJsonObject messageObj;
                messageObj["sender"] = message.getSender();
                messageObj["content"] = message.getContent();
                messageArray.append(messageObj);
            }
        }

        // Create JSON response with messages for the user
        QJsonObject responseObject;
        responseObject["messages"] = messageArray;
        QJsonDocument doc(responseObject);

        // Send response with JSON payload
        responder.writeStatusLine(QHttpServerResponder::StatusCode::Ok);
        responder.writeBody(doc.toJson());
        responder.writeBody("Messages received successfully\n");
    });

    m_server.listen(QHostAddress::Any, serverPort);
}
