#include "appmain.h"


AppMain::AppMain(QObject *parent)
    : QObject{parent}
{
    initialize();
    initServerInterface();
}


void AppMain::initialize()
{
    m_qmlContext = m_qmlEngine.rootContext();
    // Init model
    ProfileListModel *profileList = new ProfileListModel();
    ProfileModel a(5, "5 five", 5);
    ProfileModel b(3, "3 three", 3);
    ProfileModel c(6, "six two", 6);
    ProfileModel d(4, "4 four", 4);
    ProfileModel e(4, "e4 four", 2);
    ProfileModel f(4, "f4 four", 1);
    profileList->addData(a);
    profileList->addData(b);
    profileList->addData(c);
    profileList->addData(d);
    profileList->addData(e);
    profileList->addData(f);

    m_myFilterProxyModel = new MyFilterProxyModel();
    m_myFilterProxyModel->setSourceModel(profileList);
    m_myFilterProxyModel->setFilterRole(ProfileListModel::Name);
    m_myFilterProxyModel->setSortRole(ProfileListModel::Name);

    m_detailProfile = new DetailProfileModel();
    m_detailProfile->setName("Loading");

    m_qmlContext->setContextProperty("profileListModel", profileList);
    m_qmlContext->setContextProperty("filteredModel", m_myFilterProxyModel);
    m_qmlContext->setContextProperty("detailProfileModel", m_detailProfile);
    m_qmlContext->setContextProperty("appMain", this);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    m_qmlEngine.load(url);

    m_rootObject = m_qmlEngine.rootObjects().at(0);
}

void AppMain::initSignalSlot()
{
    qDebug() << "#### Init sigal/slot";
    if (m_rootObject) {

    } else {
        qWarning () << "Root object is null";
    }

}

void AppMain::initServerInterface()
{
    if (m_service == nullptr) {
        m_service = ServerInterface::instance();
    }

}

void AppMain::qmlCommand(QVariant cmd, QVariant opt)
{
    if (cmd == "user") {
        if (opt == "refesh") {
            m_service->requestGetListProfile();
        }
    } else if (cmd == "admin") {

    }

}
