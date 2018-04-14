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

#ifndef CSIDEPANEL_H
#define CSIDEPANEL_H

#include "pushbutton.h"

#include <QVBoxLayout>
#include <QWidget>

class SidePanel: public QWidget {
    Q_OBJECT

    int m_closePanelWidth;
    int m_openPanelWidth;
    bool m_isPanelOpen;
    bool m_isPinned;

    QVBoxLayout* m_vboxlayout;

    PushButton* m_bookmarksButton;
    PushButton* m_historyButton;
    PushButton* m_downloadsButton;
    PushButton* m_addPanelButton;

    void restoreState();
    void saveState();

    void createPanel();
    void createAPanels();
    void createBPanels();

    void showContextMenu(const QPoint &pos);
public:
    SidePanel(QWidget* parent = nullptr);
    bool isPinned();
};

#endif // CSIDEPANEL_H
