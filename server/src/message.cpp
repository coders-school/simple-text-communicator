#include "../inc/message.h"

Message::Message(QString receiver, QString sender, QString content):
    m_receiver(receiver), m_sender(sender), m_content(content)
{

}

QString Message::getReceiver() const
{
    return m_receiver;
}

QString Message::getSender() const
{
    return m_sender;
}

QString Message::getContent() const{
    return m_content;
}
