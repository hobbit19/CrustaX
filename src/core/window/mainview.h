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

#ifndef CMAINVIEW_H
#define CMAINVIEW_H

#include <QMainWindow>
#include <QSplitter>

class BrowserWindow;

class MainView : public QSplitter
{
    BrowserWindow* m_browserwindow;
    int m_actualcount;
public:
    MainView(BrowserWindow* parent = nullptr);
    void addView();
    void addView(const QUrl& url);
    void handleTabWidgetClosed();
};

#endif // CMAINVIEW_H
