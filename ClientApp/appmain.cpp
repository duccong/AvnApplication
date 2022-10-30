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
    ProfileModel a(5, "5 five", 5);
    ProfileModel b(3, "3 three", 3);
    ProfileModel c(6, "six two", 6);
    ProfileModel d(4, "4 four", 4);
    profileList->addData(a);
    profileList->addData(b);
    profileList->addData(c);
    profileList->addData(d);

    MyFilterProxyModel myFilterProxyModel;
    myFilterProxyModel.setSourceModel(profileList);
    myFilterProxyModel.setFilterRole(ProfileListModel::Name);
    myFilterProxyModel.setSortRole(ProfileListModel::Name);


    m_qmlContext->setContextProperty("profileListModel", profileList);
    m_qmlContext->setContextProperty("filteredModel", &myFilterProxyModel);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    m_qmlEngine.load(url);

    m_rootObject = m_qmlEngine.rootObjects().at(0);
}
