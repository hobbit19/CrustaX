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

#include "panel.h"

Panel::Panel(QWidget *parent):
    QWidget(parent)
  , m_webview(0)
{
    setObjectName("tabs-panel");

    m_vboxlayout = new QVBoxLayout;
    m_title = new PanelTitle;

    m_vboxlayout->setContentsMargins(0,0,0,0);
    m_vboxlayout->setSpacing(0);
    m_vboxlayout->setStretch(0, 0);
    m_vboxlayout->setStretch(1, 1);
    m_vboxlayout->addWidget(m_title);
    m_title->setText(tr("Panel"));
    m_vboxlayout->addWidget(new QWidget());

    setLayout(m_vboxlayout);
}

void Panel::setWebView(WebView *webview)
{
    m_webview = webview;
}
