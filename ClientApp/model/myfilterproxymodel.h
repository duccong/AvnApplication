#ifndef MYFILTERPROXYMODEL_H
#define MYFILTERPROXYMODEL_H

#include <QSortFilterProxyModel>
#include <QObject>
#include <QDebug>
#include "profilelistmodel.h"
#ifndef APP_ON_WINDOW
#include "interface/serverinterface.h"
#endif
#include "model/detailprofilemodel.h"

class MyFilterProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT

public:
    MyFilterProxyModel();

    Q_INVOKABLE void setFilterString(QString str);
    Q_INVOKABLE void setSortOrder(bool isAcs);
    Q_INVOKABLE void itemClicked(int index);

    void setFocusDetailModel(DetailProfileModel *model);

private:
    void printDetail(int index);
    DetailProfileModel *m_detailProfileModel = nullptr;
};

#endif // MYFILTERPROXYMODEL_H
