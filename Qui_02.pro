#-------------------------------------------------
#
# Project created by QtCreator 2018-04-30T14:01:32
#
#-------------------------------------------------

QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Qui_02
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    lista.cpp \
    startowe.cpp \
    symulacja.cpp \
    czas.cpp \
    data_k_wybor.cpp \
    historyjka.cpp \
    instrukcja.cpp \
    przywitanie.cpp \
    muzyka.cpp \
    od_tworcow.cpp

HEADERS += \
        mainwindow.h \
    lista.h \
    startowe.h \
    symulacja.h \
    czas.h \
    data_k_wybor.h \
    historyjka.h \
    instrukcja.h \
    przywitanie.h \
    muzyka.h \
    od_tworcow.h

FORMS += \
        mainwindow.ui \
    startowe.ui \
    data_k_wybor.ui \
    historyjka.ui \
    instrukcja.ui \
    przywitanie.ui \
    muzyka.ui \
    od_tworcow.ui

RESOURCES += \
    resources.qrc

QMAKE_CXXFLAGS += -std=gnu++14

QMAKE_CXXFLAGS += -std=gnu++11

