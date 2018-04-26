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

#ifndef CNAVIGATIONBAR_H
#define CNAVIGATIONBAR_H

#include "actionbutton.h"
#include "addressbar.h"

#include <QHBoxLayout>
#include <QLabel>
#include <QTime>
#include <QWidget>

class NavigationBar : public QWidget
{
    Q_OBJECT

    int m_height;
    QHBoxLayout* m_hboxlayout;

    ActionButton* m_backbutton;
    ActionButton* m_forwardbutton;
    ActionButton* m_topbutton;
    ActionButton* m_reloadstopbutton;
    ActionButton* m_homebutton;
    QLabel* m_timerbutton;

    AddressBar* m_addressbar;

    QTime m_startmillis;
    int m_millis;

    void restoreState();
    void saveState();
    void createLayout();
    void showContextMenu(const QPoint& pos);
public:
    NavigationBar(QWidget *parent = nullptr);
    void loadStarted();
    void loadFinished();
    void loadProgress(const int& progress);

    ActionButton* backButton();
    ActionButton* forwardButton();
    ActionButton* topButton();
    ActionButton* reloadStopButton();
    ActionButton* homeButton();

    int loadTime();
    void setAddress(QUrl address);
signals:
    void handleInternalScheme(QUrl address);
public slots:
    void redirectInternalSchemeHandler(QUrl address);
};

#endif // CNAVIGATIONBAR_H
