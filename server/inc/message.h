#pragma once

#include <QString>

class Message
{
public:
    Message(QString receiver, QString sender, QString content);
    QString getReceiver() const;
    QString getSender() const;
    QString getContent() const;

private:
    QString m_receiver;
    QString m_sender;
    QString m_content;
};
