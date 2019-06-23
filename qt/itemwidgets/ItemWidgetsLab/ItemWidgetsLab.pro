#-------------------------------------------------
#
# Project created by QtCreator 2013-05-23T11:51:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ItemWidgetsLab
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    selectshapedialog.cpp \
    mydatasource.cpp

HEADERS  += mainwindow.h \
    selectshapedialog.h \
    mydatasource.h \
    mydatatypes.h

FORMS    += mainwindow.ui

RESOURCES += \
    resources.qrc
