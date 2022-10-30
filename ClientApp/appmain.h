#ifndef APPMAIN_H
#define APPMAIN_H
#include <qqmlapplicationengine.h>
#include <QQmlContext>
#include <QObject>
#include <model/profilelistmodel.h>

class AppMain : public QObject
{
    Q_OBJECT
public:
    explicit AppMain(QObject *parent = nullptr);

private:
    QQmlApplicationEngine m_qmlEngine;
    QQmlContext *m_qmlContext;
    QObject *m_rootObject;

    void initialize();
signals:

};

#endif // APPMAIN_H
