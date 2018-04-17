/**
 * Crusta X - Qt webbrowser
 * Copyright (C) 2018 Anmol Gautam <anmol@crustabrowser.com>
 *
 * THIS FILE IS A PART OF CRUSTA X
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

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
    m_vboxlayout->addWidget(new QWidget);
}

void SidePanel::showContextMenu(const QPoint& pos)
{
    QMenu* menu = new QMenu;
    QAction* act_history = menu->addAction(tr("History"));
    act_history->setCheckable(true);
    QAction* act_bookmarks = menu->addAction(tr("Bookmarks"));
    act_bookmarks->setCheckable(true);
    QAction* act_downloads = menu->addAction(tr("Downloads"));
    act_downloads->setCheckable(true);
    menu->addSeparator();
    menu->addAction(tr("Reload All"));
    menu->addAction(tr("Open All in Tabs"));
    menu->addSeparator();
    if (m_isPinned) {
        menu->addAction(tr("Unpin Panel"));
    }
    menu->addAction(tr("Panel Settings"));
    menu->exec(mapToGlobal(pos));
}

bool SidePanel::isPinned()
{
    return m_isPinned;
}
