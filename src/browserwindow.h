#ifndef CBROWSERWINDOW_H
#define CBROWSERWINDOW_H

#include "core/window/menubar.h"
#include "core/sidepanel/sidepanel.h"
#include "core/tabs/tabwidget.h"

#include <QMainWindow>

class BrowserWindow : public QMainWindow
{
    Q_OBJECT

    MenuBar* m_menubar;
    SidePanel* m_sidepanel;
    TabWidget* m_tabwidget;
public:
    BrowserWindow(QWidget *parent = 0);
    ~BrowserWindow();
};

#endif // CBROWSERWINDOW_H
