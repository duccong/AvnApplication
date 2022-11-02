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
    // ServerInterface::instance()->getProfileListSync(profile, row);
    // qDebug() << "Got information: " << profile.name;


}

void MyFilterProxyModel::printDetail(int _index)
{
    // ge
    // int iModel = mapToSource(index(_index, 0)).row();
    qDebug() << "details of " << sourceModel()->data(mapToSource(index(_index,0)), ProfileListModel::Name).toString()
             << " - Averange: " << sourceModel()->data(mapToSource(index(_index,0)), ProfileListModel::Averange).toFloat();
}

