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

#include "browserwindow.h"
#include "core/window/menubar.h"

#include <QDebug>
#include <QSettings>
#include <QSplitter>
#include <QUrl>

BrowserWindow::BrowserWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setObjectName("browserwindow");

    m_sidepanel = new SidePanel(this);
    m_mainview = new MainView(this);

    MenuBar* menubar = new MenuBar(this);
    setMenuBar(menubar);

    layout()->setContentsMargins(0,0,0,0);

    createSplitter();

    loadSettings();
}

BrowserWindow::~BrowserWindow()
{
}

void BrowserWindow::createSplitter()
{
    QSplitter* splitter = new QSplitter(this);
    splitter->setStretchFactor(0,0);
    splitter->addWidget(m_sidepanel);
    splitter->addWidget(m_mainview);
    splitter->setMidLineWidth(0);
    splitter->setLineWidth(0);
    setCentralWidget(splitter);
}

MainView* BrowserWindow::mainView()
{
    return m_mainview;
}

SidePanel* BrowserWindow::sidePanel()
{
    return m_sidepanel;
}

void BrowserWindow::newSplitTab()
{
    m_mainview->addView(QUrl("url"));
}

void BrowserWindow::loadSettings()
{
    QSettings settings;
    settings.beginGroup("browserwindow");
    if(!settings.value("menubar-visible", true).toBool()) {
        menuBar()->hide();
    }
    if(!settings.value("sidepanel-visible", true).toBool()) {
        sidePanel()->hide();
    }
    settings.endGroup();
}
