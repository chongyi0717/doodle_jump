#-------------------------------------------------
#
# Project created by QtCreator 2020-04-22T13:25:25
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 2020-pd2-DoodleJump
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    player.cpp \
    bullet.cpp \
    platformmoving.cpp \
    platform_basic.cpp \
    platformbroken.cpp \
    platform_prop_springbed.cpp \
    platform_prop_spring.cpp \
    monster.cpp \
    hazard.cpp \
    shield.cpp \
    lose_interface.cpp \
    coin.cpp

HEADERS += \
        mainwindow.h \
    player.h \
    bullet.h \
    platform.h \
    platformmoving.h \
    platform_basic.h \
    platformbroken.h \
    platform_prop_springbed.h \
    platform_prop_spring.h \
    monster.h \
    hazard.h \
    shield.h \
    lose_interface.h \
    coin.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

RESOURCES += \
    resource.qrc
