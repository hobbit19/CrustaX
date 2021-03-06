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

#ifndef CTABBAR_H
#define CTABBAR_H

#include <QMouseEvent>
#include <QTabBar>

#define TAB_HEIGHT 36
#define PINNED_TAB_WIDTH 36
#define TAB_WIDTH 200
#define MINIMUM_TAB_WIDTH 100

class TabWidget;

class TabBar : public QTabBar
{
    Q_OBJECT

    TabWidget* m_parent;
    int m_pinnedcount;
    int m_normalcount;
    void showContextMenu(const QPoint& pos);

public:
    TabBar(TabWidget* parent = nullptr);
    int getWidth() const;
    void tabAdded();
    void tabRemoved(bool isPinned = false);
protected:
    QSize tabSizeHint(int index) const;
};

#endif // CTABBAR_H
