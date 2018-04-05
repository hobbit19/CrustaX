#include "browserwindow.h"
#include "core/window/menubar.h"

BrowserWindow::BrowserWindow(QWidget *parent)
    : QMainWindow(parent)
{
    MenuBar* menubar = new MenuBar(this);
    setMenuBar(menubar);
}

BrowserWindow::~BrowserWindow()
{
}
