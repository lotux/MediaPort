# #####################################################################
# Automatically generated by qmake (2.01a) Fri May 7 22:39:44 2010
# #####################################################################
TEMPLATE = app
TARGET =

VERSION = 0.0.4
DEFINES += APP_VERSION="$$VERSION"

DEPENDPATH += .
INCLUDEPATH += .
INCLUDEPATH += $$PWD\\..\\vlc\\include
LIBS += -L"$$PWD\\..\\vlc\\lib"
LIBS += -lvlc
QT += webkit network script svg
#      testlib
#      declarative
# Input
HEADERS += webview.h \
    playlist.h \
    mainwindow.h \
    mainapplication.h \
    singleapplication.h \
    httploader.h \
    webpage.h \ #\
    loginwindow.h \
    settings.h \
    webapi.h \
    overlay.h \
    vlcplayer.h \
    registeruser.h \
    stackview.h \
    constants.h \
    aboutdialog.h \
    overlaycontrol.h \
    rlpmanager.h \
    diskinfo.h \
    usbmonitor.h

SOURCES += main.cpp \
    vlcplayer.cpp \
    webview.cpp \
    playlist.cpp \
    mainwindow.cpp \
    mainapplication.cpp \
    singleapplication.cpp \
    httploader.cpp \
    webpage.cpp \
    loginwindow.cpp \
    settings.cpp \
    webapi.cpp \
    overlay.cpp \
    registeruser.cpp \
    stackview.cpp \
    constants.cpp \
    aboutdialog.cpp \
    overlaycontrol.cpp \
    rlpmanager.cpp \
    diskinfo.cpp \
    usbmonitor_win.cpp
RESOURCES += data.qrc
RC_FILE = mediaport.rc
CONFIG += CONSOLE
win32 {
    LIBS += \
    -ladvapi32 \
    -lws2_32
}

FORMS += \
    loginwindow.ui \
    mainwindow.ui \
    registeruser.ui \
    aboutdialog.ui \
    overlaycontrol.ui
CONFIG -= CONSOLE