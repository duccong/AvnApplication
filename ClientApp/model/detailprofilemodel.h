#ifndef DETAILPROFILEMODEL_H
#define DETAILPROFILEMODEL_H

#include <QObject>

class DetailProfileModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY onNameChanged)
    QString m_name;

public:
    DetailProfileModel(QObject *parent = nullptr);
    const QString &name() const;
    void setName(const QString &newName);
signals:
    void onNameChanged();
};

#endif // DETAILPROFILEMODEL_H
