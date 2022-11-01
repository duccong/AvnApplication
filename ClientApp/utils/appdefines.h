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
    static QString skillIdToStr(const E_SKILL_ID id) {
        switch (id) {
        case E_SKILL_ASSEMBLY:
            return "Assembly";
            break;
        case E_SKILL_CPP:
            return "C++";
            break;
        case E_SKILL_JS:
            return "Java script";
            break;
        case E_SKILL_QML:
            return "QML";
            break;
        case E_SKILL_OPENGL:
            return "Open GL";
            break;
        default:
            break;
        }
        return "invalid";
    }
};

Q_DECLARE_METATYPE(AppDefines::E_SKILL_ID)

#endif // APPDEFINES_H
