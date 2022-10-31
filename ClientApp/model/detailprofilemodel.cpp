#include "detailprofilemodel.h"

DetailProfileModel::DetailProfileModel(QObject *parent)
{

}

const QString &DetailProfileModel::name() const
{
    return m_name;
}

void DetailProfileModel::setName(const QString &newName)
{
    if (m_name == newName)
        return;
    m_name = newName;
    emit onNameChanged();
}
