#ifndef CMENUBAR_H
#define CMENUBAR_H

#include <QMainWindow>
#include <QMenuBar>

class MenuBar: public QMenuBar {
    QMainWindow* m_browserwindow;

    void createMenus();
    void createFileMenu();
    void createEditMenu();
    void createViewMenu();
    void createHistoryMenu();
    void createBookmarksMenu();
    void createToolsMenu();
    void createHelpMenu();
public:
    MenuBar(QMainWindow *parent = nullptr);
};

#endif // CMENUBAR_H
