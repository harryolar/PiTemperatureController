#-------------------------------------------------
#
# Project created by QtCreator 2014-09-08T12:22:07
#
#-------------------------------------------------

QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PiTemperatureController
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    pidcontroller.cpp \
    relays.cpp \
    readtemp.cpp \
    GPIOClass.cpp

HEADERS  += mainwindow.h \
    pidcontroller.h \
    relays.h \
    readtemp.h \
    GPIOClass.h

FORMS    += mainwindow.ui
