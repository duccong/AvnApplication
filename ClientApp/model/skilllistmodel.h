#ifndef SKILLLISTMODEL_H
#define SKILLLISTMODEL_H

#include <QAbstractListModel>
#include <QObject>
#include "../utils/appdefines.h"

class SkillModel {
private:
    AppDefines::E_SKILL_ID m_id;
    float m_point;
    QString m_name;

public:
    SkillModel(AppDefines::E_SKILL_ID id, float _point) {
        this->m_id = id;
        this->m_point = _point;
        this->m_name = AppDefines::skillIdToStr(id);
    }

    AppDefines::E_SKILL_ID id() {
        return m_id;
    }

    float point() {
        return m_point;
    }

    QString name() {
        return m_name;
    }
};

class SkillListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum Roles {
        Id = Qt::UserRole + 1,
        Point,
        Name
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
