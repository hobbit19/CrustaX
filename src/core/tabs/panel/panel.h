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

#ifndef CPANEL_H
#define CPANEL_H

#include "paneltitle.h"
#include "../../webview/webview.h"

#include <QLabel>
#include <QVBoxLayout>
#include <QWidget>

#define MAX_PANEL_WIDTH 200

class Panel : public QWidget
{
    Q_OBJECT

    QVBoxLayout* m_vboxlayout;
    WebView* m_webview;
    PanelTitle* m_title;
public:
    explicit Panel(QWidget *parent = nullptr);
    void setWebView(WebView* webview);
};

#endif // CPANEL_H
