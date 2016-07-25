#-------------------------------------------------
#
# Project created by QtCreator 2016-07-16T20:06:05
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = lpms_1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

INCLUDEPATH += C:\\OpenMAT\\OpenMAT-1.3.0-x64\\include\

LIBS += C:\\OpenMAT\\OpenMAT-1.3.0-x64\\lib\\x64\\LpSensor64.lib\
        C:\\OpenMAT\\OpenMAT-1.3.0-x64\\lib\\x64\\LpSensorD64.lib
