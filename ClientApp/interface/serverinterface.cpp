#include "serverinterface.h"

ServerInterface::ServerInterface(QObject *parent) : QObject(parent)
{
    initConnection();
    initShm();
}

void ServerInterface::getDetailProfileSync(Server::DetailProfile &profile, int id)
{
    if (m_shmManager && m_mqManager ) {
        qDebug() << "getDetailProfileSync";
        m_mqManager->sendMQueue(m_mqManager->createMessage(1, "test"));
        m_mqManager->setInterruptHandler();
        m_mqManager->receiveMQueue();

        ShmManager shmManager;
        char *data = nullptr;
        data = m_shmManager->readShm();
        std::cout << "Readed: " << data;
        profile.id = id;
        strcpy(profile.name, data);
    }
    return;
}

void ServerInterface::initConnection()
{
    qDebug() << "##### Init connection";
    m_mqManager = new MQueueManager();
    m_mqManager->openQueue(MQ_PATH_CLIENT_USER);
}

void ServerInterface::initShm()
{
    qDebug() << "#### Init Shm";
    m_shmManager = new ShmManager();
}
