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

#include "../../browserwindow.h"
#include "mainview.h"
#include "../tabs/tabwidget.h"

#include <QDebug>
#include <QUrl>

MainView::MainView(BrowserWindow *parent):
    QSplitter(parent)
  , m_browserwindow(parent)
  , m_actualcount(0)
{
    setObjectName("mainview");

    setContentsMargins(0,0,0,0);
    addView(QUrl("https://google.com"));
}

void MainView::addView()
{
    TabWidget* tabwidget = new TabWidget(this, m_browserwindow);
    addWidget(tabwidget);
    m_actualcount ++;
}

void MainView::addView(const QUrl& url)
{
    TabWidget* tabwidget = new TabWidget(this, m_browserwindow);
    tabwidget->addView(url);
    addWidget(tabwidget);
    m_actualcount ++;
}

void MainView::handleTabWidgetClosed(){
    m_actualcount --;
    if (m_actualcount == 0) {
        m_browserwindow->close();
    }
}
