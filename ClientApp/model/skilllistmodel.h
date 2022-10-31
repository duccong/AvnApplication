#ifndef SKILLLISTMODEL_H
#define SKILLLISTMODEL_H

#include <QAbstractListModel>
#include <QObject>
#include "../utils/appdefines.h"

class SkillModel {
private:
    AppDefines::E_SKILL_ID m_id;
    float m_point;

public:
    SkillModel(AppDefines::E_SKILL_ID id, float _point) {
        this->m_id = id;
        this->m_point = _point;
    }

    AppDefines::E_SKILL_ID id() {
        return m_id;
    }

    float point() {
        return m_point;
    }
};

class SkillListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum Roles {
        IdSkill = Qt::UserRole + 1,
        Point
    };

    explicit SkillListModel(QObject *parent = nullptr);

    void addData(const SkillModel& model);

    int rowCount(const QModelIndex &parent = QModelIndex()) const;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

protected:
    QHash<int, QByteArray> roleNames() const;

private:
    QList<SkillModel> m_skillList;
};

#endif // SKILLLISTMODEL_H
