#include "browserwindow.h"
#include "core/window/menubar.h"

#include <QDebug>
#include <QSettings>
#include <QSplitter>
#include <QUrl>

BrowserWindow::BrowserWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setObjectName("browserwindow");

    m_sidepanel = new SidePanel(this);
    m_mainview = new MainView(this);

    MenuBar* menubar = new MenuBar(this);
    setMenuBar(menubar);

    layout()->setContentsMargins(0,0,0,0);

    createSplitter();

    loadSettings();
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

MainView* BrowserWindow::mainView()
{
    return m_mainview;
}

SidePanel* BrowserWindow::sidePanel()
{
    return m_sidepanel;
}

void BrowserWindow::newSplitTab()
{
    m_mainview->addView(QUrl("url"));
}

void BrowserWindow::loadSettings()
{
    QSettings settings;
    settings.beginGroup("browserwindow");
    if(!settings.value("menubar-visible", true).toBool()) {
        menuBar()->hide();
    }
    if(!settings.value("sidepanel-visible", true).toBool()) {
        sidePanel()->hide();
    }
    settings.endGroup();
}
