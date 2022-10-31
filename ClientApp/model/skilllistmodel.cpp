#include "skilllistmodel.h"

SkillListModel::SkillListModel(QObject *parent)
    : QAbstractListModel{parent}
{

}

void SkillListModel::addData(const SkillModel &model)
{
    m_skillList.append(model);
}

int SkillListModel::rowCount(const QModelIndex &parent) const
{
    return m_skillList.size();
}

QVariant SkillListModel::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() >= m_skillList.size())
    {
        return QVariant();
    }
    SkillModel model = m_skillList.at(index.row());
    switch (role) {
    case IdSkill:
        return model.id();
        break;
    case Point:
        return model.point();
        break;
    default:
        break;
    }
    return QVariant();
}

QHash<int, QByteArray> SkillListModel::roleNames() const
{
    QHash<int ,QByteArray> roles;
    roles[IdSkill] = "id";
    roles[Point] = "point";
    return roles;
}
