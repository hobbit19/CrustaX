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
desktop.path = /usr/share/applications
desktop.files += crusta.desktop
INSTALLS += target desktop

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
    src/core/tabs/tabwidget.cpp \
    src/core/window/menubar.cpp \
    src/browserwindow.cpp \
    src/main.cpp \
    src/core/sidepanel/sidepanel.cpp \
    src/core/sidepanel/pushbutton.cpp \
    src/core/window/mainview.cpp \
    src/core/tabs/webtab.cpp \
    src/core/webview/webview.cpp \
    src/core/tabs/navigation/navigationbar.cpp \
    src/core/tabs/navigation/actionbutton.cpp \
    src/core/tabs/navigation/addressbar.cpp \
    src/core/tabs/tabbar.cpp \
    src/core/tabs/speeddial/speeddial.cpp \
    src/core/tabs/speeddial/dial.cpp \
    src/scripts/internalscripts.cpp \
    src/core/tabs/panel/panel.cpp \
    src/core/tabs/panel/paneltitle.cpp

HEADERS += \
    src/core/tabs/tabwidget.h \
    src/core/window/menubar.h \
    src/browserwindow.h \
    src/core/sidepanel/sidepanel.h \
    src/core/sidepanel/pushbutton.h \
    src/core/window/mainview.h \
    src/core/tabs/webtab.h \
    src/core/webview/webview.h \
    src/core/tabs/navigation/navigationbar.h \
    src/core/tabs/navigation/actionbutton.h \
    src/core/cmacros.h \
    src/core/tabs/navigation/addressbar.h \
    src/core/tabs/tabbar.h \
    src/core/tabs/speeddial/speeddial.h \
    src/core/tabs/speeddial/dial.h \
    src/scripts/internalscripts.h \
    src/core/tabs/panel/panel.h \
    src/core/tabs/panel/paneltitle.h

RESOURCES += \
    resource.qrc

TRANSLATIONS += \
    translations/crusta_es.ts
