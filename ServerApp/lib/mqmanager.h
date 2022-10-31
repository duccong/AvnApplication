#ifndef MQMANAGER_H
#define MQMANAGER_H
#include <signal.h>
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <ctype.h>
#include "constantDefine.h"

typedef struct MMESSAGE
{
    int id = 0;
    char content[128];
} MMESSAGE;

class MQueueManager
{
public:
    MQueueManager();
    void convertMsgToChar(MMESSAGE msg, char *outMsg);
    MMESSAGE convertCharToMsg(char *msg);

void openQueue(char *mqPath);
    MMESSAGE createMessage(const int id, const char* content);
    void sendMQueue(const MMESSAGE &msg);
    void setInterruptHandler();
    void receiveMQueue();
    void closeAndDeleteMQueue();

private:
    MMESSAGE m_message{};
    char *m_mqPath = nullptr;
    struct mq_attr m_attr;
    mqd_t m_mqueue;

    // set the interrupt handler to catch SIGUSR1, otherwise
    // it will trigger the default behaviour (terminate)
    struct sigaction m_signalAction;

    // signal interrupt
    int m_sig;
    sigset_t m_signalSet;
    struct sigevent m_event;

};

#endif // MQMANAGER_H
