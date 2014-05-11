#-------------------------------------------------
#
# Project created by QtCreator 2014-05-03T21:48:31
#
#-------------------------------------------------

QT       += core gui

CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = dz_events_423
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    simpleevent.cpp \
    node.cpp \
    eventcontainersmodel.cpp \
    eventeditordialog.cpp \
    searchresultdialog.cpp \
    searchbytimedialog.cpp

HEADERS  += mainwindow.h \
    event.h \
    simpleevent.h \
    node.h \
    eventcontainersmodel.h \
    eventeditordialog.h \
    searchresultdialog.h \
    eventcontainer.h \
    searchbytimedialog.h

FORMS    += mainwindow.ui \
    eventeditordialog.ui \
    searchresultdialog.ui \
    searchbytimedialog.ui

RESOURCES += \
    icons.qrc
