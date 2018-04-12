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
    QMenu* menu = addMenu(tr("&File"));
    act_splittab = menu->addAction(tr("New &Split Tab"));
    connect(act_splittab, &QAction::triggered, [=]{
        m_browserwindow->newSplitTab();
    });
    menu->addAction(tr("New &Window"));
    menu->addAction(tr("New &Private Window"));
    menu->addSeparator();
    menu->addAction(tr("&Open File"));
    menu->addAction(tr("&Save Page"));
    menu->addAction(tr("Print"));
    menu->addSeparator();
    QAction* act_quit = menu->addAction(tr("Quit"));
    act_quit->setShortcut(QKeySequence::Quit);
    connect(act_quit, &QAction::triggered, [=]{
        m_browserwindow->close();
    });
}

void MenuBar::createEditMenu()
{
    QMenu* menu = addMenu(tr("&Edit"));
    menu->addAction(tr("&Undo"));
    menu->addAction(tr("&Redo"));
    menu->addSeparator();
    menu->addAction(tr("&Cut"));
    menu->addAction(tr("C&opy"));
    menu->addAction(tr("&Paste"));
    menu->addSeparator();
    menu->addAction(tr("&Select All"));
    menu->addAction(tr("&Find In Page"));
    menu->addSeparator();
    menu->addAction(tr("Permissions"));
    menu->addAction(tr("Settings"));
}

void MenuBar::createViewMenu()
{
    QMenu* menu = addMenu(tr("&View"));

    QMenu* mnu_toolbars = menu->addMenu(tr("Toolbars"));
    act_menubar = mnu_toolbars->addAction(tr("&Menubar"));
    act_menubar->setCheckable(true);
    connect(act_menubar, &QAction::triggered, [=]{
        if (m_browserwindow->menuBar()->isVisible()) {
            m_browserwindow->menuBar()->hide();
        } else {
            m_browserwindow->menuBar()->show();
        }
    });
    QAction* act_navigationBar = mnu_toolbars->addAction(tr("&Navigation Bar"));
    act_navigationBar->setCheckable(true);
    QAction* act_bookmarksBar = mnu_toolbars->addAction(tr("&Bookmarks Bar"));
    act_bookmarksBar->setCheckable(true);

    QMenu* mnu_tabs = menu->addMenu(tr("Tabs"));
    QAction* act_tabTop = mnu_tabs->addAction(tr("&Top"));
    act_tabTop->setCheckable(true);
    QAction* act_tabLeft = mnu_tabs->addAction(tr("&Left"));
    act_tabLeft->setCheckable(true);
    QAction* act_tabRight = mnu_tabs->addAction(tr("&Right"));
    act_tabRight->setCheckable(true);
    QAction* act_tabBottom = mnu_tabs->addAction(tr("&Bottom"));
    act_tabBottom->setCheckable(true);

    QMenu* mnu_split = menu->addMenu(tr("Split Mode"));
    QAction* act_horizotnal = mnu_split->addAction(tr("&Horizontal"));
    act_horizotnal->setCheckable(true);
    QAction* act_vertical = mnu_split->addAction(tr("&Vertical"));
    act_vertical->setCheckable(true);

    act_sidePanel = menu->addAction(tr("Side Panel"));
    act_sidePanel->setCheckable(true);
    connect(act_sidePanel, &QAction::triggered, [=]{
        if (m_browserwindow->sidePanel()->isVisible()) {
            m_browserwindow->sidePanel()->hide();
        } else {
            m_browserwindow->sidePanel()->show();
        }
    });

    QAction* act_statusBar = menu->addAction(tr("Status Bar"));
    act_statusBar->setCheckable(true);
    menu->addSeparator();
    menu->addAction(tr("Zoom &In"));
    menu->addAction(tr("Zoom &Out"));
    menu->addAction(tr("&Reset Zoom"));
    menu->addSeparator();
    menu->addAction(tr("&Page Source"));

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
    QMenu* menu = addMenu(tr("Hi&story"));
    menu->addAction(tr("&Back"));
    menu->addAction(tr("&Forward"));
    menu->addAction(tr("&Home"));
    menu->addSeparator();
    menu->addAction(tr("&Show All History"));
    menu->addAction(tr("&Most Visited"));
    menu->addAction(tr("&Recently Closed"));
}

void MenuBar::createBookmarksMenu()
{
    QMenu* menu = addMenu(tr("&Bookmarks"));
    menu->addAction(tr("Bookmark &This Page"));
    menu->addAction(tr("Bookmark &All Tabs"));
    menu->addSeparator();
    menu->addAction(tr("&Show All Bookmarks"));
    menu->addMenu(tr("&Recent Bookmarks"));
    menu->addMenu(tr("&Most Visited"));
}

void MenuBar::createToolsMenu()
{
    QMenu* menu = addMenu(tr("&Tools"));
    menu->addAction(tr("&Site Info"));
    menu->addSeparator();
    menu->addAction(tr("&Web Debugger"));
    menu->addAction(tr("&Cookie Manager"));
    menu->addAction(tr("&Download Manager"));

}

void MenuBar::createHelpMenu()
{
    QMenu* menu = addMenu(tr("&Help"));
    menu->addAction(tr("&Technical Support"));
    menu->addAction(tr("&Report Bug..."));
    menu->addAction(tr("&System Information..."));
    menu->addSeparator();
    menu->addAction(tr("About &Crusta"));
    QAction* act_aboutQt = menu->addAction(tr("About &Qt"));
    connect(act_aboutQt, &QAction::triggered, []{QApplication::aboutQt();});
    menu->addSeparator();
    menu->addAction(tr("&Follow on Twitter"));
    menu->addAction(tr("&Like a Feature"));
    menu->addSeparator();
    menu->addAction(tr("Check for &Updates"));
}
