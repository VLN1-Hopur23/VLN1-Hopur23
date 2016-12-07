QT += core
QT -= gui
QT += sql

CONFIG += c++11

TARGET = VLN1-Hopur23
CONFIG += console
CONFIG -= app_bundle


TEMPLATE = app

SOURCES += main.cpp \
    consoleui.cpp \
    scientist.cpp \
    scientistservice.cpp \
    dataaccess.cpp \
    localtime.cpp \
    dbmanager.cpp \
    computer.cpp

HEADERS += \
    consoleui.h \
    scientist.h \
    scientistservice.h \
    dataaccess.h \
    localtime.h \
    dbmanager.h \
    computer.h
