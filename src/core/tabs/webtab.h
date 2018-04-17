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

#ifndef WEBTAB_H
#define WEBTAB_H

#include "navigation/navigationbar.h"
#include "panel/panel.h"
#include "tabwidget.h"
#include "../webview/webview.h"

#include <QStackedWidget>
#include <QVBoxLayout>
#include <QWidget>
#include <QSplitter>

class WebTab : public QWidget
{
    TabWidget* m_tabwidget;
    NavigationBar* m_navigationbar;
    QSplitter* m_splitter;
    Panel* m_panel;
    WebView* m_webview;
    QVBoxLayout* m_vboxlayout;
    QStackedWidget* m_stackedwidget;
    void loadFinished();
    void titleChanged(const QString& title);
    void iconChanged(const QIcon& icon);


    bool m_isPinned;
public:
    WebTab(TabWidget *parent = nullptr);
    void loadUrl(const QUrl& url);
    bool isPinned();
    void setPinned();
    void back();
    void forward();
    void reload();
};

#endif // WEBTAB_H
