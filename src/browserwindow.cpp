#include "browserwindow.h"

#include <QSplitter>

BrowserWindow::BrowserWindow(QWidget *parent)
    : QMainWindow(parent)
{
    m_menubar = new MenuBar(this);
    m_sidepanel = new SidePanel(this);
    m_tabwidget = new TabWidget(this);
    setMenuBar(m_menubar);

    QSplitter* splitter = new QSplitter;
    splitter->addWidget(m_sidepanel);
    splitter->addWidget(m_tabwidget);
    setCentralWidget(splitter);
}

BrowserWindow::~BrowserWindow()
{
}
