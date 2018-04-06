#include "browserwindow.h"
#include "core/window/menubar.h"

#include <QSplitter>
#include <QDebug>

BrowserWindow::BrowserWindow(QWidget *parent)
    : QMainWindow(parent)
{
    m_sidepanel = new SidePanel(this);
    m_mainview = new MainView(this);

    MenuBar* menubar = new MenuBar(this);
    setMenuBar(menubar);

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

SidePanel* BrowserWindow::sidePanel()
{
    return m_sidepanel;
}
