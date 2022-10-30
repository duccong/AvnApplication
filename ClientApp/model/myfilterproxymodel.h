#ifndef MYFILTERPROXYMODEL_H
#define MYFILTERPROXYMODEL_H

#include <QSortFilterProxyModel>
#include <QObject>

class MyFilterProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT

    Q_INVOKABLE void setFilterString(QString str);
    Q_INVOKABLE void setSortOrder(bool isAcs);

public:
    MyFilterProxyModel();


};

#endif // MYFILTERPROXYMODEL_H
