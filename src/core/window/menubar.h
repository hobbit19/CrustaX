#ifndef CMENUBAR_H
#define CMENUBAR_H

#include <QMenuBar>

class MenuBar: public QMenuBar {
    void createMenus();
    void createFileMenu();
    void createEditMenu();
    void createViewMenu();
    void createHistoryMenu();
    void createBookmarksMenu();
    void createToolsMenu();
    void createHelpMenu();
public:
    MenuBar(QWidget* parent = 0);
};

#endif // CMENUBAR_H
