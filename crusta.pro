#-------------------------------------------------
#
# Project created by QtCreator 2018-04-05T17:54:10
#
#-------------------------------------------------

QT += core gui

QT += widgets webengine webenginewidgets

QT += sql

TARGET = crusta
TEMPLATE = app

target.path = /usr/local/bin/
desktop.path = /usr/share/applications
desktop.files += crusta.desktop
INSTALLS += target desktop

DEFINES += QT_DEPRECATED_WARNINGS

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
    src/scripts/internalscripts.cpp \
    src/core/tabs/panel/panel.cpp \
    src/core/tabs/panel/paneltitle.cpp \
    src/core/webview/webpage.cpp \
    src/core/tabs/history/historypage.cpp \
    src/core/tabs/utils/pagebutton.cpp \
    src/core/tabs/utils/searchbox.cpp \
    src/core/tabs/utils/base.cpp

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
    src/core/tabs/navigation/addressbar.h \
    src/core/tabs/tabbar.h \
    src/scripts/internalscripts.h \
    src/core/tabs/panel/panel.h \
    src/core/tabs/panel/paneltitle.h \
    src/core/webview/webpage.h \
    src/core/tabs/history/historypage.h \
    src/core/tabs/utils/pagebutton.h \
    src/core/tabs/utils/searchbox.h \
    src/core/tabs/utils/base.h

RESOURCES += \
    resource.qrc

TRANSLATIONS += \
    translations/crusta_es.ts \
    translations/crusta_hi.ts \
    translations/crusta_ru.ts

FORMS +=
