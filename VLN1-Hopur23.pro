#-------------------------------------------------
#
# Project created by QtCreator 2016-12-12T09:32:28
#
#-------------------------------------------------

QT       += core gui sql

CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = VLN1-Hopur23
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    ui/addstudentdialog.cpp \
    ui/addcomputerdialog.cpp \
    Models/computer.cpp \
    Models/scientist.cpp \
    Repositories/dbmanager.cpp \
    Services/computerservice.cpp \
    Services/localtime.cpp \
    Services/scientistservice.cpp \
    Services/connectionservice.cpp \
    ui/connectiondialog.cpp

HEADERS  += mainwindow.h \
    ui/addstudentdialog.h \
    ui/addcomputerdialog.h \
    Models/computer.h \
    Models/scientist.h \
    Repositories/dbmanager.h \
    Services/computerservice.h \
    Services/localtime.h \
    Services/scientistservice.h \
    Services/connectionservice.h \
    ui/connectiondialog.h

FORMS    += mainwindow.ui \
    ui/addstudentdialog.ui \
    ui/addcomputerdialog.ui
INCLUDEPATH += ui \
    Models \
    Repositories \
    Services

RESOURCES += \
    resources.qrc

