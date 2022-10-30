#include "profilelistmodel.h"

ProfileListModel::ProfileListModel(QObject *parent) : QAbstractListModel(parent)
{

}

void ProfileListModel::addData(const ProfileModel &model)
{
    m_profileList.push_back(model);
}

int ProfileListModel::rowCount(const QModelIndex &parent) const
{
    return m_profileList.size();
}

int ProfileListModel::columnCount(const QModelIndex &parent) const
{
    return 2;
}

QVariant ProfileListModel::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() >= m_profileList.size())
    {
        return QVariant();
    }
    ProfileModel model = m_profileList.at(index.row());
    switch (role) {
    case Id:
        return model.id();
        break;
    case Name:
        return model.name();
        break;
    case Averange:
        return model.averange();
        break;
    default:
        break;
    }
    return QVariant();
}

QVariant ProfileListModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal)
    {
        switch (section)
        {
        // case -1:
            // return QString("ID");
        case 0:
            return QString("Name");
        case 1:
            return QString("Averange");
            // etc etc
        }

    }
    return QVariant();
}

QHash<int, QByteArray> ProfileListModel::roleNames() const
{
    QHash<int ,QByteArray> roles;
    roles[Id] = "id";
    roles[Name] = "name";
    roles[Averange] = "averange";
    return roles;
}
