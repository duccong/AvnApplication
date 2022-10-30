#include "appmain.h"

AppMain::AppMain(QObject *parent)
    : QObject{parent}
{
    initialize();
}

void AppMain::initialize()
{
    m_qmlContext = m_qmlEngine.rootContext();
    ProfileListModel *profileList = new ProfileListModel();
    ProfileModel a(1, "1", 1);
    ProfileModel b(2, "2", 2);
    ProfileModel c(2, "2", 2);

    profileList->addData(a);
    profileList->addData(b);
    profileList->addData(c);

    m_qmlContext->setContextProperty("profileListModel", profileList);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    m_qmlEngine.load(url);

    m_rootObject = m_qmlEngine.rootObjects().at(0);
}
