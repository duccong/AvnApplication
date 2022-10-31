#ifndef SERVERINTERFACE_H
#define SERVERINTERFACE_H

#include <QObject>
#include <QDebug>
#include <../ServerApp/lib/constantDefine.h>
#include <../ServerApp/lib/mqmanager.h>
#include <../ServerApp/lib/shmmanager.h>

class ServerInterface : public QObject
{
    Q_OBJECT
private:
    explicit ServerInterface(QObject *parent = nullptr);

public:
    static ServerInterface* instance() {
        static ServerInterface* iServer = nullptr;
        if (iServer == nullptr) {
            iServer = new ServerInterface();
        }
        return iServer;
    }

    void getDetailProfileSync(Server::DetailProfile &profile, int id);

signals:

private:
    MQueueManager *m_mqManager = nullptr;
    ShmManager *m_shmManager = nullptr;
    void initConnection();
    void initShm();

};

#endif // SERVERINTERFACE_H
