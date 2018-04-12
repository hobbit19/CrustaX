#ifndef CBROWSERWINDOW_H
#define CBROWSERWINDOW_H

#include "core/sidepanel/sidepanel.h"
#include "core/window/mainview.h"

#include <QMainWindow>

class BrowserWindow : public QMainWindow
{
    Q_OBJECT

    MainView* m_mainview;
    SidePanel* m_sidepanel;

    void loadSettings();
public:
    BrowserWindow(QWidget *parent = nullptr);
    ~BrowserWindow();
    void createSplitter();

    MainView* mainView();
    SidePanel* sidePanel();
    void newSplitTab();
};

#endif // CBROWSERWINDOW_H
