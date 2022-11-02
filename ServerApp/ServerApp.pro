TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        clienttest.cpp \
        lib/filemanager.cpp \
        lib/mqmanager.cpp \
        lib/shmmanager.cpp \
        main.cpp \
        servermain.cpp \
        utils/utils.cpp

LIBS += -lpthread \
        -lrt

HEADERS += \
    clienttest.h \
    lib/constantDefine.h \
    lib/filemanager.h \
    lib/mqmanager.h \
    lib/shmmanager.h \
    servermain.h \
    utils/utils.h

DISTFILES +=
