#ifndef APPMAIN_H
#define APPMAIN_H
#include <qqmlapplicationengine.h>
#include <QQmlContext>
#include <QObject>
#include <model/profilelistmodel.h>
#include <model/myfilterproxymodel.h>

class AppMain : public QObject
{
    Q_OBJECT
public:
    explicit AppMain(QObject *parent = nullptr);

private:
    QQmlApplicationEngine m_qmlEngine;
    MyFilterProxyModel *m_myFilterProxyModel = nullptr;
    QQmlContext *m_qmlContext = nullptr;
    QObject *m_rootObject = nullptr;

    void initialize();
signals:

};

#endif // APPMAIN_H
