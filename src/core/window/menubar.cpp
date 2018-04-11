#include "../../browserwindow.h"
#include "menubar.h"

#include <QApplication>

MenuBar::MenuBar(BrowserWindow *parent):
    QMenuBar(parent)
  , m_browserwindow(parent)
{
    setObjectName("menubar");

    createMenus();
}

void MenuBar::createMenus()
{
    createFileMenu();
    createEditMenu();
    createViewMenu();
    createHistoryMenu();
    createBookmarksMenu();
    createToolsMenu();
    createHelpMenu();
}

void MenuBar::createFileMenu()
{
    QMenu* menu = addMenu("&File");
    menu->addAction("&New Tab");
    menu->addAction("New &Split Tab");
    menu->addAction("New &Window");
    menu->addAction("New &Private Window");
    menu->addSeparator();
    menu->addAction("&Open File");
    menu->addAction("&Save Page");
    menu->addAction("Print");
    menu->addSeparator();
    QAction* act_quit = menu->addAction("Quit");
    act_quit->setShortcut(QKeySequence::Quit);
    connect(act_quit, &QAction::triggered, [=]{
        m_browserwindow->close();
    });
}

void MenuBar::createEditMenu()
{
    QMenu* menu = addMenu("&Edit");
    menu->addAction("&Undo");
    menu->addAction("&Redo");
    menu->addSeparator();
    menu->addAction("&Cut");
    menu->addAction("C&opy");
    menu->addAction("&Paste");
    menu->addSeparator();
    menu->addAction("&Select All");
    menu->addAction("&Find In Page");
    menu->addSeparator();
    menu->addAction("Permissions");
    menu->addAction("Settings");
}

void MenuBar::createViewMenu()
{
    QMenu* menu = addMenu("&View");

    QMenu* mnu_toolbars = menu->addMenu("Toolbars");
    act_menubar = mnu_toolbars->addAction("&Menubar");
    act_menubar->setCheckable(true);
    connect(act_menubar, &QAction::triggered, [=]{
        if (m_browserwindow->menuBar()->isVisible()) {
            m_browserwindow->menuBar()->hide();
        } else {
            m_browserwindow->menuBar()->show();
        }
    });
    QAction* act_navigationBar = mnu_toolbars->addAction("&Navigation Bar");
    act_navigationBar->setCheckable(true);
    QAction* act_bookmarksBar = mnu_toolbars->addAction("&Bookmarks Bar");
    act_bookmarksBar->setCheckable(true);

    QMenu* mnu_tabs = menu->addMenu("Tabs");
    QAction* act_tabTop = mnu_tabs->addAction("&Top");
    act_tabTop->setCheckable(true);
    QAction* act_tabLeft = mnu_tabs->addAction("&Left");
    act_tabLeft->setCheckable(true);
    QAction* act_tabRight = mnu_tabs->addAction("&Right");
    act_tabRight->setCheckable(true);
    QAction* act_tabBottom = mnu_tabs->addAction("&Bottom");
    act_tabBottom->setCheckable(true);

    QMenu* mnu_split = menu->addMenu("Split Mode");
    QAction* act_horizotnal = mnu_split->addAction("&Horizontal");
    act_horizotnal->setCheckable(true);
    QAction* act_vertical = mnu_split->addAction("&Vertical");
    act_vertical->setCheckable(true);

    act_sidePanel = menu->addAction("Side Panel");
    act_sidePanel->setCheckable(true);
    connect(act_sidePanel, &QAction::triggered, [=]{
        if (m_browserwindow->sidePanel()->isVisible()) {
            m_browserwindow->sidePanel()->hide();
        } else {
            m_browserwindow->sidePanel()->show();
        }
    });

    QAction* act_statusBar = menu->addAction("Status Bar");
    act_statusBar->setCheckable(true);
    menu->addSeparator();
    menu->addAction("Zoom &In");
    menu->addAction("Zoom &Out");
    menu->addAction("&Reset Zoom");
    menu->addSeparator();
    menu->addAction("&Page Source");

    connect(menu, &QMenu::aboutToShow, this, &MenuBar::aboutToShowViewMenu);
}

void MenuBar::aboutToShowViewMenu()
{
    if (m_browserwindow->menuBar()->isVisible()) {
        act_menubar->setChecked(true);
    } else {
        act_menubar->setChecked(false);
    }

    if (m_browserwindow->sidePanel()->isVisible()) {
        act_sidePanel->setChecked(true);
    } else {
        act_sidePanel->setChecked(false);
    }
}

void MenuBar::createHistoryMenu()
{
    QMenu* menu = addMenu("Hi&story");
    menu->addAction("&Back");
    menu->addAction("&Forward");
    menu->addAction("&Home");
    menu->addSeparator();
    menu->addAction("&Show All History");
    menu->addAction("&Most Visited");
    menu->addAction("&Recently Closed");
}

void MenuBar::createBookmarksMenu()
{
    QMenu* menu = addMenu("&Bookmarks");
    menu->addAction("Bookmark &This Page");
    menu->addAction("Bookmark &All Tabs");
    menu->addSeparator();
    menu->addAction("&Show All Bookmarks");
    menu->addMenu("&Recent Bookmarks");
    menu->addMenu("&Most Visited");
}

void MenuBar::createToolsMenu()
{
    QMenu* menu = addMenu("&Tools");
    menu->addAction("&Site Info");
    menu->addSeparator();
    menu->addAction("&Web Debugger");
    menu->addAction("&Cookie Manager");
    menu->addAction("&Download Manager");

}

void MenuBar::createHelpMenu()
{
    QMenu* menu = addMenu("&Help");
    menu->addAction("&Technical Support");
    menu->addAction("&Report Bug...");
    menu->addAction("&System Information...");
    menu->addSeparator();
    menu->addAction("About &Crusta");
    QAction* act_aboutQt = menu->addAction("About &Qt");
    connect(act_aboutQt, &QAction::triggered, []{QApplication::aboutQt();});
    menu->addSeparator();
    menu->addAction("&Follow on Twitter");
    menu->addAction("&Like a Feature");
    menu->addSeparator();
    menu->addAction("Check for &Updates");
}
