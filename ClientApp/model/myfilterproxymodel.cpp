#include "myfilterproxymodel.h"

MyFilterProxyModel::MyFilterProxyModel()
{
    setSortOrder(false);
}

void MyFilterProxyModel::setFilterString(QString str)
{
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

