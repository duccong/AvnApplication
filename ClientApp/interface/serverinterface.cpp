#include "serverinterface.h"
#include "utils/utilsapp.h"

ServerInterface::ServerInterface(QObject *parent) : QObject(parent)
{
    initConnection();
    initShm();
}

void ServerInterface::getProfileListSync(Server::ListProfile &profile, int id)
{
    if (m_shmManager && m_mqManager ) {
        qDebug() << "getProfileListSync";
        MMESSAGE msg;
        m_mqManager->createMessage(1, GET_PROFILE_LIST_SYNC);
        // m_mqManager->createMessage(1, GET_PROFILE_LIST_SYNC);
        m_mqManager->sendMQueue();
        m_mqManager->setInterruptHandler();
        m_mqManager->receiveMQueue(msg);
        std::cout << "Check msg content: " << msg.content << endl;

            ShmManager shmManager;
            char *data = nullptr;
            data = m_shmManager->readShm();
            // Server::ListProfile *listProfile = (struct Server::ListProfile *) data;
            // qDebug() << "Readed: " << endl;
            // for (int i = 0; i < 30; i++) {
                // std::cout << (int)*(data + i) << " ";
            // }
            std::cout << std::endl;
            profile.convertFromShortArray(data);
            qDebug() << "ListProfile: " << profile.size();
            for (int i = 0; i < profile.size(); i++) {
                UtilsApp::printfProfile(profile.listProfile.at(i));
            }

    }
    return;
}

void ServerInterface::getProfileDetailSync(Server::DetailProfile &profile, int id)
{
    if (m_shmManager && m_mqManager ) {
        qDebug() << "getProfileListSync";
        MMESSAGE msg;
        m_mqManager->createMessage(1, GET_PROFILE_DETAIL_SYNC);
        // m_mqManager->createMessage(1, GET_PROFILE_LIST_SYNC);
        m_mqManager->sendMQueue();
        m_mqManager->setInterruptHandler();
        m_mqManager->receiveMQueue(msg);
        std::cout << "Check msg content: " << msg.content << endl;
        profile.updateFromSerializeMapSkill(msg.content, sizeof(msg.content));
    }
    return;
}

void ServerInterface::requestGetListProfile()
{
    qDebug() << "requestGetListProfile";

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
