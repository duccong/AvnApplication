#ifndef APPDEFINES_H
#define APPDEFINES_H

#include <QObject>
#include <QMap>

class AppDefines : public QObject
{
    Q_OBJECT
public:
    explicit AppDefines(QObject *parent = nullptr);

    enum E_SKILL_ID
    {
        E_SKILL_ASSEMBLY = 0,
        E_SKILL_CPP,
        E_SKILL_JS,
        E_SKILL_QML,
        E_SKILL_OPENGL,
        E_SKILL_MAX

    };
    Q_ENUM(E_SKILL_ID)

public:
    // QMap<E_SKILL_ID, QString> skillMap = {

    // }
};

Q_DECLARE_METATYPE(AppDefines::E_SKILL_ID)

#endif // APPDEFINES_H
