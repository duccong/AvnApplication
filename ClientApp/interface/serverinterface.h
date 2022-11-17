#ifndef SERVERINTERFACE_H
#define SERVERINTERFACE_H

#include <QObject>
#include <QDebug>
#ifndef APP_ON_WINDOW
#include <../ServerApp/lib/constantDefine.h>
#include <../ServerApp/lib/mqmanager.h>
#include <../ServerApp/lib/shmmanager.h>
#endif

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

#ifndef APP_ON_WINDOW
    void getProfileListSync(Server::ListProfile &profile, int id);
    void getProfileDetailSync(Server::DetailProfile &profile, int id );
    void requestGetListProfile();
#endif
signals:

private:
#ifndef APP_ON_WINDOW
    MQueueManager *m_mqManager = nullptr;
    ShmManager *m_shmManager = nullptr;
#endif
    void initConnection();
    void initShm();
};

#endif // SERVERINTERFACE_H
