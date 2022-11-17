#include "myfilterproxymodel.h"

MyFilterProxyModel::MyFilterProxyModel()
{
    setSortOrder(true);
}

void MyFilterProxyModel::setFilterString(QString str)
{
    qDebug()<< "setFilterString: " << str.toLocal8Bit().data();
    this->setFilterCaseSensitivity(Qt::CaseInsensitive);
    this->setFilterFixedString(str);
}

void MyFilterProxyModel::setSortOrder(bool isAcs)
{
    if (isAcs) {
        this->sort(1, Qt::AscendingOrder);
    } else {
        this->sort(1, Qt::DescendingOrder);
    }

}

void MyFilterProxyModel::itemClicked(int _index)
{
    int row = mapToSource(index(_index, 0)).row();
    qDebug() << "Item clicked: " << _index << " at model " << row;
    printDetail(_index);
#ifndef APP_ON_WINDOW
    Server::DetailProfile profile;
    ServerInterface::instance()->getProfileDetailSync(profile, 0);
    // ServerInterface::instance()->getProfileListSync(profile, row);
    // qDebug() << "Got information: " << profile.name;
    qDebug() << profile.serializeMapSkill().c_str();
    // m_profileListModel->updateProfileListAt(profile, 0);
    QString name = sourceModel()->data(mapToSource(index(_index,0)), ProfileListModel::Name).toString();
    qDebug() << "name: " << name;
    m_detailProfileModel->setName(name);
    QList<SkillModel> skillList;
    qDebug() << profile.mapSkill.size();
    for (const auto& item : profile.mapSkill) {
        SkillModel s((AppDefines::E_SKILL_ID)item.first, item.second);
        skillList.append(s);
    }
    qDebug() << skillList.size();
    m_detailProfileModel->skillList()->updateListData(skillList);
#endif
}

void MyFilterProxyModel::setFocusDetailModel(DetailProfileModel *model)
{
    qDebug() << "setFocusDetailModel";
    m_detailProfileModel = model;
}

void MyFilterProxyModel::printDetail(int _index)
{
    // ge
    // int iModel = mapToSource(index(_index, 0)).row();
    qDebug() << "details of " << sourceModel()->data(mapToSource(index(_index,0)), ProfileListModel::Name).toString()
             << " - Averange: " << sourceModel()->data(mapToSource(index(_index,0)), ProfileListModel::Averange).toFloat();
}

