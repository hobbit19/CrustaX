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

#ifndef CTABWIDGET_H
#define CTABWIDGET_H

#include "tabbar.h"

#include <QMainWindow>
#include <QPushButton>
#include <QTabWidget>

class BrowserWindow;

class TabWidget: public QTabWidget {
    Q_OBJECT

    BrowserWindow* m_browserwindow;
    TabBar* m_tabbar;
    QPushButton* m_newtabbutton;

    void handleCurrentChanged(int index);
    void addNewTabButton();
    void replaceNewTabButton();
    QWidget *addViewHelper(bool background);
    void resizeEvent(QResizeEvent* event);
    void resizeTabbar();

    void keyReleaseEvent(QKeyEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);

    const QString TEXT_ON_NEW_TAB = tr("Connecting...");

public:
    TabWidget(QWidget* parent = nullptr, BrowserWindow *browserwindow = nullptr);
    ~TabWidget() {}
    void addView(bool background = false);
    void addView(const QUrl& url, bool background = false);
    void tabTitleChanged(int index, const QString& title, bool isPinned);
    void closeTab(const int index);

public slots:
    void handleTabsChanged();

signals:
    void tabsChanged();
    void tabWidgetClosed();
};

#endif // CTABWIDGET_H
