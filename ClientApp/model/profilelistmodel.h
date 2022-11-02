#ifndef PROFILELISTMODEL_H
#define PROFILELISTMODEL_H

// #include <QAbstractListModel>
#include <QAbstractTableModel>
// #include <QAbstractItemModel>
#include <QVariant>
#include <QObject>
#include <QList>
#include <QDebug>
#include <interface/serverinterface.h>

class ProfileModel {
private:
    int m_id;
    QString m_name;
    float m_averange;

public:
    ProfileModel(int id, QString name, float averange) {
        this->m_id = id;
        this->m_name = name;
        this->m_averange = averange;
    }

    int id() {
        return m_id;
    }

    QString name() {
        return m_name;
    }

    float averange() {
        return m_averange;
    }
};

class ProfileListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum Roles {
        Id = Qt::UserRole + 1,
        Name,
        Averange
    };

    explicit ProfileListModel(QObject *parent = nullptr);

    void addData(const ProfileModel& model);


    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

    const QList<ProfileModel> &profileList() const;
    void setProfileList(const QList<ProfileModel> &newProfileList);
    void setProfileList(const Server::ListProfile &newProfileList);

protected:
    QHash<int, QByteArray> roleNames() const;

private:
    QList<ProfileModel> m_profileList;
};

#endif // PROFILELISTMODEL_H
