#ifndef DETAILPROFILEMODEL_H
#define DETAILPROFILEMODEL_H

#include <QObject>
#include "skilllistmodel.h"

class DetailProfileModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY onNameChanged)
    Q_PROPERTY(SkillListModel* skillList READ skillList WRITE setSkillList NOTIFY onSkillListChanged)
    QString m_name;

public:
    DetailProfileModel(QObject *parent = nullptr);
    const QString &name() const;
    void setName(const QString &newName);

    SkillListModel* skillList() const;
    void setSkillList(SkillListModel* newSkillList);

signals:
    void onNameChanged();
    void onSkillListChanged();
private:
    SkillListModel *m_skillList;
};

#endif // DETAILPROFILEMODEL_H
