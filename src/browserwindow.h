#ifndef CBROWSERWINDOW_H
#define CBROWSERWINDOW_H

#include "core/sidepanel/sidepanel.h"
#include "core/window/menubar.h"
#include "core/window/mainview.h"

#include <QMainWindow>

class BrowserWindow : public QMainWindow
{
    Q_OBJECT

    MenuBar* m_menubar;
    MainView* m_mainview;
    SidePanel* m_sidepanel;
public:
    BrowserWindow(QWidget *parent = nullptr);
    ~BrowserWindow();
    void createSplitter();
};

#endif // CBROWSERWINDOW_H
