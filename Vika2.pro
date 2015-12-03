QT += core
QT -= gui
QT += core sql

TARGET = Vika2
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    individual.cpp \
    people.cpp \
    dataread.cpp \
    ui.cpp \
    core.cpp \
    sqlitedata.cpp

HEADERS += \
    individual.h \
    people.h \
    dataread.h \
    ui.h \
    core.h \
    sqlitedata.h

