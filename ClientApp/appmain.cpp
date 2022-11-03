#include "appmain.h"


AppMain::AppMain(QObject *parent)
    : QObject{parent}
{
    initialize();
    initServerInterface();
}


void AppMain::initialize()
{
    qDebug() << "#### initialize";
    m_qmlContext = m_qmlEngine.rootContext();
    // Init model
    m_profileListModel = new ProfileListModel();

#ifdef TEST_MODEL
    ProfileModel a(5, "5 five", 5);
    ProfileModel b(3, "3 three", 3);
    ProfileModel c(6, "six two", 6);
    ProfileModel d(4, "4 four", 4);
    ProfileModel e(4, "e4 four", 2);
    ProfileModel f(4, "f4 four", 1);
    m_profileListModel->addData(a);
    m_profileListModel->addData(b);
    m_profileListModel->addData(c);
    m_profileListModel->addData(d);
    m_profileListModel->addData(e);
    m_profileListModel->addData(f);
#endif

    m_myFilterProxyModel = new MyFilterProxyModel();
    m_myFilterProxyModel->setSourceModel(m_profileListModel);
    m_myFilterProxyModel->setFilterRole(ProfileListModel::Name);
    m_myFilterProxyModel->setSortRole(ProfileListModel::Name);

    m_detailProfile = new DetailProfileModel();
    m_myFilterProxyModel->setFocusDetailModel(m_detailProfile);
    m_detailProfile->setName("Loading");

    qDebug() << "#### setContextProperty";
    m_qmlContext->setContextProperty("profileListModel", m_profileListModel);
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

void AppMain::qmlCommand(QVariant _cmd, QVariant _opt)
{
    QString cmd = _cmd.toString();
    QString opt = _opt.toString();
    qDebug() << "cmd: " << cmd << " - opt: " << opt;
    if (cmd == "user") {
        if (opt == "refresh") {
            // m_service->requestGetListProfile();
            Server::ListProfile profiles;
            ServerInterface::instance()->getProfileListSync(profiles, -1);
            m_profileListModel->setProfileList(profiles);
        }
    } else if (cmd == "admin") {

    }

}
