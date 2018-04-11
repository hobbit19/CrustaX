#include "../cmacros.h"
#include "sidepanel.h"

#include <QMenu>
#include <QPoint>

SidePanel::SidePanel(QWidget *parent):
    QWidget(parent)
  , m_closePanelWidth(40)
  , m_openPanelWidth(100)
{
    setObjectName("sidepanel");

    m_vboxlayout = new QVBoxLayout;
    m_vboxlayout->setSpacing(0);
    m_vboxlayout->setContentsMargins(0,0,0,0);
    m_bookmarksButton = new PushButton;
    m_historyButton = new PushButton;
    m_downloadsButton = new PushButton;
    m_addPanelButton = new PushButton;

    restoreState();

    if (!m_isPanelOpen) {
        setFixedWidth(m_closePanelWidth);
    }

    setLayout(m_vboxlayout);

    createPanel();

    setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this, &SidePanel::customContextMenuRequested, this, &SidePanel::showContextMenu);
}

void SidePanel::restoreState()
{
     m_isPanelOpen = false;
     m_isPinned = true;
}

void SidePanel::saveState()
{
}

void SidePanel::createPanel()
{
    createAPanels();
    createBPanels();
}

void SidePanel::createAPanels()
{
    m_vboxlayout->addWidget(m_bookmarksButton);
    m_vboxlayout->addWidget(m_historyButton);
    m_vboxlayout->addWidget(m_downloadsButton);
}

void SidePanel::createBPanels()
{
    m_vboxlayout->addWidget(m_addPanelButton);
    m_vboxlayout->addWidget(FLEXIBLE_SPACE);
}

void SidePanel::showContextMenu(const QPoint& pos)
{
    QMenu* menu = new QMenu;
    QAction* act_history = menu->addAction("History");
    act_history->setCheckable(true);
    QAction* act_bookmarks = menu->addAction("Bookmarks");
    act_bookmarks->setCheckable(true);
    QAction* act_downloads = menu->addAction("Downloads");
    act_downloads->setCheckable(true);
    menu->addSeparator();
    menu->addAction("Reload All");
    menu->addAction("Open All in Tabs");
    menu->addSeparator();
    if (m_isPinned) {
        menu->addAction("Unpin Panel");
    }
    menu->addAction("Panel Settings");
    menu->exec(mapToGlobal(pos));
}

bool SidePanel::isPinned()
{
    return m_isPinned;
}
