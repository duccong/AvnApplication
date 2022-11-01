#include "detailprofilemodel.h"

DetailProfileModel::DetailProfileModel(QObject *parent)
{

    m_skillList = new SkillListModel();
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
    SkillModel s(AppDefines::E_SKILL_OPENGL, 4);
    SkillModel s1(AppDefines::E_SKILL_ASSEMBLY, 1);
    SkillModel s2(AppDefines::E_SKILL_QML, 3);
    SkillModel s3(AppDefines::E_SKILL_CPP, 4);
    SkillModel s4(AppDefines::E_SKILL_JS, 1);
    m_skillList->addData(s);
    m_skillList->addData(s1);
    m_skillList->addData(s2);
    m_skillList->addData(s3);
    m_skillList->addData(s4);
    emit onNameChanged();
}

SkillListModel* DetailProfileModel::skillList() const
{
    return m_skillList;
}

void DetailProfileModel::setSkillList(SkillListModel *newSkillList)
{
    if (m_skillList == newSkillList)
        return;
    m_skillList = newSkillList;
    emit onSkillListChanged();
}
