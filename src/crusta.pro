#-------------------------------------------------
#
# Project created by QtCreator 2018-04-05T17:54:10
#
#-------------------------------------------------

QT += core gui

QT += widgets webengine webenginewidgets

TARGET = crusta
TEMPLATE = app

target.path = /usr/local/bin/
INSTALLS += target

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
    core/tabs/tabwidget.cpp \
    core/window/menubar.cpp \
    browserwindow.cpp \
    main.cpp \
    core/sidepanel/sidepanel.cpp \
    core/sidepanel/pushbutton.cpp \
    core/window/mainview.cpp \
    core/tabs/webtab.cpp \
    core/webview/webview.cpp \
    core/tabs/navigation/navigationbar.cpp \
    core/tabs/navigation/actionbutton.cpp \
    core/tabs/navigation/addressbar.cpp \
    core/tabs/tabbar.cpp \
    core/tabs/speeddial/speeddial.cpp \
    core/tabs/speeddial/dial.cpp

HEADERS += \
    core/tabs/tabwidget.h \
    core/window/menubar.h \
    browserwindow.h \
    core/sidepanel/sidepanel.h \
    core/sidepanel/pushbutton.h \
    core/window/mainview.h \
    core/tabs/webtab.h \
    core/tabs/tabmacros.h \
    core/webview/webview.h \
    core/tabs/navigation/navigationbar.h \
    core/tabs/navigation/actionbutton.h \
    core/cmacros.h \
    core/tabs/navigation/addressbar.h \
    core/tabs/tabbar.h \
    core/tabs/speeddial/speeddial.h \
    core/tabs/speeddial/dial.h

RESOURCES += \
    resource.qrc
