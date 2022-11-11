#include "servermain.h"

using namespace std;

ServerMain::ServerMain()
{
    cout << "#### Initing server!" << endl;
    initData();
    MQueueManager mqueueManager;
    mqueueManager.openQueue(MQ_PATH_CLIENT_USER);
    while (1) {
        MMESSAGE msg;
        mqueueManager.receiveMQueue(msg);
        cout << "Check msg content: " << msg.content << endl;
        if (strncmp(GET_PROFILE_LIST_SYNC, msg.content, sizeof(GET_PROFILE_LIST_SYNC)) == 0) {
            cout << " >>>> GET LIST PROFILE LIST SYNC" << endl;
            mqueueManager.createMessage(1, MMESSAGE_RESPONSE_OK);
            // write to SHM
            ShmManager shmManager;
            //prepare data to sharemem;
            // char *sByte = new char(m_sSharedProfileList.size() + 1);
            // strcpy(sByte, m_sSharedProfileList.c_str());

            ShortDetailProfile detail[m_listProfile.size()];
            // memcpy(detail, m_listProfile.convertToArray(), sizeof(detail));
            char my_s_bytes[sizeof(detail)];
            // char *sByte = new char(sizeof(my_s_bytes));
            // memcpy(my_s_bytes, &m_listProfile, sizeof(my_s_bytes));
            memcpy(my_s_bytes, &m_listProfile.convertToShortArray()[0], sizeof(detail));
        } else if (strncmp(GET_PROFILE_DETAIL_SYNC, msg.content, sizeof(GET_PROFILE_DETAIL_SYNC)) == 0) {
            cout << " >>>> GET LIST PROFILE DETAIL SYNC at" << msg.id << endl;
            // check ID
            int id = 0;
            // Prepare msg content;
            string content;
            // TODO: find profile smarter;
            for (auto &item : m_listProfile.listProfile) {
                if (item.id == id) {
                    // found profile
                    content = item.serializeMapSkill();
                    break;
                }
            }
            // DetailProfile p = m_listProfile.listProfile.at(0);
            mqueueManager.createMessage(1, content.c_str());

        } else {
            cout << " >>>> TBD ... " << endl;
            mqueueManager.createMessage(1, MMESSAGE_RESPONSE_OK);
        }
        mqueueManager.sendMQueue();
        mqueueManager.setInterruptHandler();
    }
#ifdef TEST_MQ
    // mqueue object
    mqd_t mqueue;

    // mqueue attributes
    struct mq_attr attr;
    attr.mq_flags = 0;
    attr.mq_maxmsg = 10;
    attr.mq_msgsize = MESSAGE_BUFFER_SIZE;
    attr.mq_curmsgs = 0;

    // message buffer
    char buffer[MESSAGE_BUFFER_SIZE];

    cout << "Open mqueue: " << MQ_PATH_CLIENT_USER << endl;
    if ((mqueue = mq_open(MQ_PATH_CLIENT_USER, O_RDWR | O_CREAT, 0660, &attr)) == -1)
    {
        perror("Open queue client");
        exit(EXIT_FAILURE);
    }
    cout << " >>>>> m_queue: " << mqueue << endl;

    // recerve message
#ifndef TEST_WAIT_RECV_MSG
    while (1) {
        cout << "Waiting for message" << endl;
    cout << " >>>>> m_queue: " << mqueue << endl;
        if (mq_receive(mqueue, buffer, attr.mq_msgsize, NULL) == -1)
        {
            perror("Receive");
            exit(EXIT_FAILURE);
        }
        cout << "Received message: " << buffer << endl;
    cout << " >>>>> m_queue: " << mqueue << endl;
        // sending the acknowledge message
        // making the message all uppercase
        for(int i=0; i < strlen(buffer); ++i)
        {
            buffer[i] = toupper(buffer[i]);
        }
#endif

#ifndef TEST_WRITE_SHM
        ShmManager shmManager;
        //prepare data to sharemem;
        // char *sByte = new char(m_sSharedProfileList.size() + 1);
        // strcpy(sByte, m_sSharedProfileList.c_str());

        ShortDetailProfile detail[m_listProfile.size()];
        // memcpy(detail, m_listProfile.convertToArray(), sizeof(detail));
        char my_s_bytes[sizeof(detail)];
        // char *sByte = new char(sizeof(my_s_bytes));
        // memcpy(my_s_bytes, &m_listProfile, sizeof(my_s_bytes));
        memcpy(my_s_bytes, &m_listProfile.convertToShortArray()[0], sizeof(detail));
#endif

#ifndef TEST_READ_SHM
        auto vec = m_listProfile.convertToShortArray();
        shmManager.writeShm(vec.data(), vec.size());
        for (int i = 0; i < 30; i++) {
            std::cout << (int)*(vec.data() + i)<< " ";
        }
        std::cout << std::endl;
        char * data = shmManager.readShm();
        for (int i = 0; i < 30; i++) {
            std::cout << (int)*(data + i) << " ";
        }

        ShortDetailProfile tmpList[m_listProfile.listProfile.size()];
        memcpy(tmpList, data+4, sizeof(my_s_bytes));
        cout << "\n id: " << tmpList[2].id;
        cout << " - name: " << tmpList[2].name;
        cout << " - point: " << tmpList[2].averange << endl;
        Server::ListProfile listProfile;
        listProfile.convertFromShortArray(data);
        cout << "ListProfile: " << listProfile.size();
        for (int i = 0; i < listProfile.size(); i++) {
            Utils::printfProfile(listProfile.listProfile.at(i));
        }
#endif

#ifndef TEST_ACK
        cout << "Sending message:" << buffer << endl;;
        cout << " >>>>> m_queue: " << mqueue << endl;
        if (mq_send(mqueue, buffer, attr.mq_msgsize, 0) == -1)
        {
            perror("failed to send to Server");
        }
        cout << " >>>>> m_queue: " << mqueue << endl;
    }
#endif
    // close message
    cout << "Terminating..." << endl;
    if (mq_close(mqueue) == -1)
    {
        perror("Close");
        exit(EXIT_FAILURE);
    }

    // delete mqueue
    mq_unlink(MQ_PATH_CLIENT_USER);
#endif


}

void ServerMain::initData()
{
    cout << "#### init data";
    m_sSharedProfileList = "";
    FileManager fileManager;
    fstream *f = fileManager.openFile(DATA_FILE);
    string txtData;
    while (getline(*f, txtData)) {
        int size = txtData.size();
            // cout << "size: " << size << endl;
        if (size > 0 && isdigit((int)txtData[0])) {
            // cout << " RAW -> " << txtData << endl;
            DetailProfile p = Utils::strDataToProfile(txtData);
            m_listProfile.listProfile.push_back(p);
            string raw = "" + to_string(p.id) + "-" + string(p.name) + ";";
            m_sSharedProfileList.append(raw);
        }
    }
    fileManager.closeFile();
}
