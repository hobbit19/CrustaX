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

#include "tabbar.h"

#include <QDebug>

TabBar::TabBar(QWidget *parent):
    QTabBar(parent)
  , m_pinnedcount(0)
  , m_normalcount(0)
{
    setObjectName("tabbar");

    setDrawBase(true);
    setContextMenuPolicy(Qt::CustomContextMenu);
}

QSize TabBar::tabSizeHint(int index) const
{
    Q_UNUSED(index)

    int width = TAB_WIDTH;
    int actualtabbarwidth = m_pinnedcount * PINNED_TAB_WIDTH + m_normalcount * width;
    int maxtabbarwidth = maximumWidth();
    if (actualtabbarwidth > maxtabbarwidth) {
        width = (maxtabbarwidth - m_pinnedcount * PINNED_TAB_WIDTH) / m_normalcount;
        width = (width > MINIMUM_TAB_WIDTH) ? width : MINIMUM_TAB_WIDTH;
    }
    return QSize(width, TAB_HEIGHT);
}

int TabBar::getWidth() const
{
    /* this will return the width of the tabbar
     * assuming every tab to be of size give by
     * TAB_WIDTH, this helps in check for overflow
     * on tabbar */
    int pinnedtabbarwidth = m_pinnedcount * PINNED_TAB_WIDTH;
    int normaltabbarwidth = m_normalcount * TAB_WIDTH;
    int totaltabbarwidth = pinnedtabbarwidth + normaltabbarwidth;
    return qMin(totaltabbarwidth, maximumWidth());
}

void TabBar::tabAdded()
{
    // Pinned tab will never be added, its just converted
    m_normalcount ++;
}

void TabBar::tabRemoved(bool isPinned)
{
    if (isPinned) {
        m_pinnedcount --;
    } else {
        m_normalcount --;
    }
}
