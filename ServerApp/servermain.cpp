#include <iostream>
#include <stdio.h>
#include <time.h>
#include <ctype.h>
#include "lib/constantDefine.h"
#include "servermain.h"
#include "lib/mqmanager.h"

using namespace std;

ServerMain::ServerMain()
{
    cout << "#### Initing server!" << endl;
    MQueueManager mqueueManager;
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

    // recerve message
    // while (1) {
        cout << "Waiting for message" << endl;
        if (mq_receive(mqueue, buffer, attr.mq_msgsize, NULL) == -1)
        {
            perror("Receive");
            exit(EXIT_FAILURE);
        }
        cout << "Received message: " << buffer << endl;
        // sending the acknowledge message
        // making the message all uppercase
        for(int i=0; i < strlen(buffer); ++i)
        {
            buffer[i] = toupper(buffer[i]);
        }
        cout << "Sending message:" << buffer << endl;;
        if (mq_send(mqueue, buffer, attr.mq_msgsize, 0) == -1)
        {
            perror("failed to send to Server");
        }
    // }

    // close message
    cout << "Terminating..." << endl;
    if (mq_close(mqueue) == -1)
    {
        perror("Close");
        exit(EXIT_FAILURE);
    }

    // delete mqueue
    mq_unlink(MQ_PATH_CLIENT_USER);

}
