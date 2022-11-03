#include <signal.h>
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <ctype.h>
#include "lib/constantDefine.h"
#include "lib/mqmanager.h"
#include "lib/shmmanager.h"
#include "clienttest.h"

using namespace std;

ClientTest::ClientTest()
{


}

void ClientTest::sendMsg(char *msg)
{
    if (strlen(msg) == 0) {
        msg = new char(10);
        strcpy(msg, "Default");
    }

    MQueueManager mqManager;
    // mqManager.openQueue(MQ_PATH_CLIENT_USER);
    // mqManager.sendMQueue(mqManager.createMessage(1, msg));
    // mqManager.setInterruptHandler();
    // mqManager.receiveMQueue();

    ShmManager shmManager;
    char *data = nullptr;
    data = shmManager.readShm();
    cout << "Readed: " << data;
    // mqManager.closeAndDeleteMQueue();
}
