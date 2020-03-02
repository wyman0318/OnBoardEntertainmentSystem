#-------------------------------------------------
#
# Project created by QtCreator 2019-12-17T12:05:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = carDemo
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    tty.c \
    mytty.cpp \
    mymenu.cpp \
    myvideowindow.cpp \
    listsection.cpp

HEADERS  += widget.h \
    tty.h \
    mytty.h \
    mymenu.h \
    myvideowindow.h \
    listsection.h

FORMS    += widget.ui \
    mymenu.ui \
    myvideowindow.ui \
    listsection.ui

RESOURCES += \
    res.qrc
