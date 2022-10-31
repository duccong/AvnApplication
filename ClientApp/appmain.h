#ifndef APPMAIN_H
#define APPMAIN_H
#include <qqmlapplicationengine.h>
#include <QQmlContext>
#include <QObject>
#include <QVariant>
#include <model/profilelistmodel.h>
#include <model/myfilterproxymodel.h>
#include <../ServerApp/lib/constantDefine.h>
#include <../ServerApp/lib/mqmanager.h>
#include <../ServerApp/lib/shmmanager.h>
#include <interface/serverinterface.h>

class AppMain : public QObject
{
    Q_OBJECT
public:

    explicit AppMain(QObject *parent = nullptr);

public:
    Q_INVOKABLE void qmlCommand(QVariant cmd, QVariant opt);

private:
    QQmlApplicationEngine m_qmlEngine;
    MyFilterProxyModel *m_myFilterProxyModel = nullptr;
    QQmlContext *m_qmlContext = nullptr;
    QObject *m_rootObject = nullptr;
    ServerInterface * m_service = nullptr;

    void initialize();
    void initSignalSlot();
    void initServerInterface();
    void initConnection();
    void initShm();
signals:

};

#endif // APPMAIN_H
