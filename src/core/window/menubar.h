#ifndef CMENUBAR_H
#define CMENUBAR_H

#include <QAction>
#include <QMainWindow>
#include <QMenuBar>

class BrowserWindow;

class MenuBar: public QMenuBar {
    Q_OBJECT

    BrowserWindow* m_browserwindow;

    QAction* act_splittab;
    QAction* act_sidePanel;
    QAction* act_menubar;

    void createMenus();
    void createFileMenu();
    void createEditMenu();
    void createViewMenu();
    void createHistoryMenu();
    void createBookmarksMenu();
    void createToolsMenu();
    void createHelpMenu();

    void aboutToShowViewMenu();
public:
    MenuBar(BrowserWindow *parent = nullptr);
};

#endif // CMENUBAR_H
