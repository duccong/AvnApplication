QT += quick

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        ../ServerApp/lib/mqmanager.cpp \
        ../ServerApp/lib/shmmanager.cpp \
        appmain.cpp \
        interface/serverinterface.cpp \
        main.cpp \
        model/detailprofilemodel.cpp \
        model/myfilterproxymodel.cpp \
        model/profilelistmodel.cpp \
        model/skilllistmodel.cpp \
        utils/appdefines.cpp

RESOURCES += qml.qrc

LIBS += -lpthread \
        -lrt

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    imageSource/Assembly.png \
    imageSource/Debug.png \
    imageSource/Documenting.png \
    imageSource/QML.png \
    imageSource/Star.png \
    imageSource/System.png

HEADERS += \
    ../ServerApp/lib/constantDefine.h \
    ../ServerApp/lib/mqmanager.h \
    ../ServerApp/lib/shmmanager.h \
    appmain.h \
    interface/serverinterface.h \
    model/detailprofilemodel.h \
    model/myfilterproxymodel.h \
    model/profilelistmodel.h \
    model/skilllistmodel.h \
    utils/appdefines.h
