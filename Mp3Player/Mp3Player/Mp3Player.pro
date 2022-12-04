#-------------------------------------------------
#
# Project created by QtCreator 2022-02-11T19:32:38
#
#-------------------------------------------------

QT  = core bluetooth widgets
QT       += core gui
QT       += sensors
QT      += multimedia
QT += androidextras
QT +=    multimediawidgets

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Mp3Player
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
        widget.cpp \
    chat.cpp \
    chatclient.cpp \
    chatserver.cpp \
    remoteselector.cpp

HEADERS += \
        widget.h \
    chat.h \
    chatclient.h \
    chatserver.h \
    remoteselector.h

FORMS += \
        widget.ui \
    chat.ui \
    remoteselector.ui

CONFIG += mobility




OTHER_FILES +=
