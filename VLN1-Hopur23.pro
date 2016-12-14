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
    scientist.cpp \
    scientistservice.cpp \
    localtime.cpp \
    computer.cpp \
    computerservice.cpp \
    dbmanager.cpp \
    ui/addstudentdialog.cpp

HEADERS  += mainwindow.h \
    scientist.h \
    scientistservice.h \
    localtime.h \
    computer.h \
    computerservice.h \
    dbmanager.h \
    ui/addstudentdialog.h

FORMS    += mainwindow.ui \
    ui/addstudentdialog.ui
INCLUDEPATH += ui
