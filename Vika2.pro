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
    ui.cpp \
    core.cpp \
    sqlitedata.cpp \
    computer.cpp \
    machines.cpp


HEADERS += \
    individual.h \
    people.h \
    ui.h \
    core.h \
    sqlitedata.h \
    computer.h \
    machines.h \
    globalconstants.h


