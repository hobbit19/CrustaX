#ifndef CMENUBAR_H
#define CMENUBAR_H

#include "../../browserwindow.h"

#include <QMainWindow>
#include <QMenuBar>

class MenuBar: public QMenuBar {
    BrowserWindow* m_browserwindow;

    void createMenus();
    void createFileMenu();
    void createEditMenu();
    void createViewMenu();
    void createHistoryMenu();
    void createBookmarksMenu();
    void createToolsMenu();
    void createHelpMenu();
public:
    MenuBar(BrowserWindow *parent = nullptr);
};

#endif // CMENUBAR_H
