#include "skilllistmodel.h"

SkillListModel::SkillListModel(QObject *parent)
    : QAbstractListModel{parent}
{

}

void SkillListModel::addData(const SkillModel &model)
{
    m_skillList.append(model);
}

void SkillListModel::updateListData(const QList<SkillModel> &model)
{
    qDebug() << "model size:" << model.size();
    m_skillList.clear();
    foreach (SkillModel s, model) {
        m_skillList.append(s);
    }
    // m_skillList = model;
    emit layoutChanged();
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
    case Id:
        return model.id();
        break;
    case Point:
        return model.point();
        break;
    case Name:
        return model.name();
        break;
    default:
        break;
    }
    return QVariant();
}

QHash<int, QByteArray> SkillListModel::roleNames() const
{
    QHash<int ,QByteArray> roles;
    roles[Id] = "id";
    roles[Point] = "point";
    roles[Name] = "name";
    return roles;
}
