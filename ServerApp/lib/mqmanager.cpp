#include "mqmanager.h"
using namespace std;

void noop (int interrrupt) {
    // interupt handler
    std::cout << "Interrupt: " << interrrupt << std::endl;
}


MQueueManager::MQueueManager()
{
    m_attr.mq_flags = 0;
    m_attr.mq_maxmsg = QUEUE_MAXMSG;
    m_attr.mq_msgsize = MESSAGE_BUFFER_SIZE;
    m_attr.mq_curmsgs = 0;
}

void MQueueManager::convertMsgToChar(MMESSAGE msg, char *outMsg)
{

}

MMESSAGE MQueueManager::convertCharToMsg(char *msg)
{
    return MMESSAGE{};
}

void MQueueManager::openQueue(char *mqPath)
{
    cout << "Open mqueue " <<  mqPath << endl;
    if (m_mqPath == nullptr) {
        cout << "update mqPath: " <<  mqPath << endl;
        m_mqPath = new char(strlen(mqPath) + 1);
        strcpy(m_mqPath, mqPath);
    }

    cout << "Startigng open mqueue " <<  mqPath << endl;
    if ((m_mqueue = mq_open(mqPath, O_RDWR | O_CREAT, 0660, &m_attr)) == -1)
    {
        perror("open queue");
        exit(EXIT_FAILURE);
    }
    cout << " >>>>> m_queue: " << m_mqueue << endl;
}

void MQueueManager::createMessage(const int id, const char *content)
{
    // MMESSAGE msg;
    m_message.id = id;
    strcpy(m_message.content, content);
    // return msg;
}

void MQueueManager::sendMQueue(const MMESSAGE &msg)
{
    // send the message
    cout << "Sending message:" << msg.content << endl;
    cout << " >>>>> m_queue: " << m_mqueue << endl;
    if (mq_send(m_mqueue, msg.content, m_attr.mq_msgsize, 0) == -1)
    {
        perror("sending message");
        exit(EXIT_FAILURE);
    }

    // register for mqueue notification requesting to receive SIGUSR1
    m_event.sigev_notify = SIGEV_SIGNAL;
    m_event.sigev_signo = SIGUSR1;
    mq_notify(m_mqueue, &m_event);

}

void MQueueManager::sendMQueue()
{
    cout << "Sending message:" << m_message.content << endl;
    cout << " >>>>> m_queue: " << m_mqueue << endl;
    if (mq_send(m_mqueue, m_message.content, m_attr.mq_msgsize, 0) == -1)
    {
        perror("sending message");
        exit(EXIT_FAILURE);
    }

    // register for mqueue notification requesting to receive SIGUSR1
    m_event.sigev_notify = SIGEV_SIGNAL;
    m_event.sigev_signo = SIGUSR1;
    mq_notify(m_mqueue, &m_event);

}

void MQueueManager::setInterruptHandler()
{
    // set interrupt action
    m_signalAction.sa_handler = &noop;
    m_signalAction.sa_flags = SA_RESTART;
    sigaction(SIGUSR1, &m_signalAction, NULL);
    // wait for SIGUSR1 signal
    sigemptyset(&m_signalSet);
    sigaddset(&m_signalSet, SIGUSR1);
    cout << "Waiting for signal" << endl;
    cout << " >>>>> m_queue: " << m_mqueue << endl;
    if (sigwait(&m_signalSet, &m_sig) != 0)
    {
        perror("Sigwait");
    }
}

void MQueueManager::receiveMQueue(MMESSAGE &msg)
{
    cout << "Waiting for message" << endl;
    cout << " >>>>> m_queue: " << m_mqueue << endl;
    char buffer[MESSAGE_BUFFER_SIZE];
    if (mq_receive(m_mqueue, buffer, m_attr.mq_msgsize, NULL) == -1)
    {
        perror("receiving message");
        exit(EXIT_FAILURE);
    }
    cout << "Message received:" << buffer << endl;
    strcpy(msg.content, buffer);
    cout << " >>>>> m_queue: " << m_mqueue << endl;
}

void MQueueManager::closeAndDeleteMQueue()
{
    // close mqueue descriptor
    if (m_mqPath == nullptr) {
        cout << "MqPath is not valid" << endl;
        return;
    }
    cout << "Terminating" << endl;
    if (mq_close(m_mqueue) == -1)
    {
        perror("close");
        exit(EXIT_FAILURE);
    }
    // delete mqueue
    // it may raise an error if the other process delete the queue first
    mq_unlink(m_mqPath);
    delete(m_mqPath);
}

