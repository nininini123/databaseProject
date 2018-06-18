#-------------------------------------------------
#
# Project created by QtCreator 2018-05-29T08:22:42
#
#-------------------------------------------------

QT       += core gui
QT += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = db_dianxin
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
    userwindow.cpp \
    userinfowindow.cpp \
    paywin.cpp \
    csinfoforuserwin.cpp \
    svrmenuwin.cpp \
    cswindow.cpp \
    tobpwin.cpp \
    searchuserwin.cpp \
    edituserwin.cpp \
    adminwin.cpp \
    billwin.cpp \
    confirmpaywin.cpp \
    csinfowin.cpp \
    selectdatewin.cpp \
    workreportwin.cpp \
    runsqlwin.cpp

HEADERS += \
        mainwindow.h \
    userwindow.h \
    userinfowindow.h \
    userinfowindow.h \
    paywin.h \
    csinfoforuserwin.h \
    svrmenuwin.h \
    cswindow.h \
    tobpwin.h \
    searchuserwin.h \
    edituserwin.h \
    adminwin.h \
    billwin.h \
    confirmpaywin.h \
    csinfowin.h \
    selectdatewin.h \
    workreportwin.h \
    runsqlwin.h

FORMS += \
        mainwindow.ui \
    userwindow.ui \
    userinfowindow.ui \
    paywin.ui \
    csinfoforuserwin.ui \
    svrmenuwin.ui \
    cswindow.ui \
    tobpwin.ui \
    searchuserwin.ui \
    edituserwin.ui \
    adminwin.ui \
    billwin.ui \
    confirmpaywin.ui \
    csinfowin.ui \
    selectdatewin.ui \
    workreportwin.ui \
    runsqlwin.ui
