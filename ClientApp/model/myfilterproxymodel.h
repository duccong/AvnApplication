#ifndef MYFILTERPROXYMODEL_H
#define MYFILTERPROXYMODEL_H

#include <QSortFilterProxyModel>
#include <QObject>
#include <QDebug>

class MyFilterProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT

public:
    MyFilterProxyModel();

    Q_INVOKABLE void setFilterString(QString str);
    Q_INVOKABLE void setSortOrder(bool isAcs);

};

#endif // MYFILTERPROXYMODEL_H
