#-------------------------------------------------
#
# Project created by QtCreator 2014-11-18T10:17:40
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets multimedia

TARGET = PvZ
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    player.cpp \
    gamescreen.cpp \
    sun.cpp \
    zombie.cpp \
    plant.cpp \
    peashooter.cpp \
    sunflower.cpp \
    flag.cpp \
    conehead.cpp \
    buckethead.cpp \
    newspaper.cpp \
    regular.cpp \
    bullet.cpp \
    chomper.cpp \
    potatomine.cpp \
    repeater.cpp \
    cherrybomb.cpp \
    snowpea.cpp \
    wallnut.cpp \
    lawnmower.cpp

HEADERS  += mainwindow.h \
    player.h \
    gamescreen.h \
    sun.h \
    zombie.h \
    plant.h \
    peashooter.h \
    sunflower.h \
    flag.h \
    conehead.h \
    buckethead.h \
    newspaper.h \
    regular.h \
    bullet.h \
    chomper.h \
    potatomine.h \
    repeater.h \
    cherrybomb.h \
    snowpea.h \
    wallnut.h \
    lawnmower.h

FORMS    += mainwindow.ui

RESOURCES += \
    Resources.qrc
