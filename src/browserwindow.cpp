#include "browserwindow.h"

#include <QSplitter>
#include <QDebug>

BrowserWindow::BrowserWindow(QWidget *parent)
    : QMainWindow(parent)
{
    m_menubar = new MenuBar(this);
    m_sidepanel = new SidePanel(this);
    m_mainview = new MainView(this);
    setMenuBar(m_menubar);

    layout()->setContentsMargins(0,0,0,0);

    createSplitter();
}

BrowserWindow::~BrowserWindow()
{
}

void BrowserWindow::createSplitter()
{
    QSplitter* splitter = new QSplitter(this);
    splitter->setStretchFactor(0,0);
    splitter->addWidget(m_sidepanel);
    splitter->addWidget(m_mainview);
    setCentralWidget(splitter);
}
