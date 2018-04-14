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

#include "webpage.h"

#include <QDebug>

WebPage::WebPage(QObject *parent):
    QWebEnginePage(parent)
{

}

WebPage::WebPage(QWebEngineProfile *profile, QObject *parent):
    QWebEnginePage(profile, parent)
{

}

bool WebPage::acceptNavigationRequest(const QUrl &url, NavigationType type, bool isMainFrame)
{
    Q_UNUSED(url);
    Q_UNUSED(isMainFrame);

    if (type == WebPage::NavigationTypeFormSubmitted) {
        runJavaScript("document.forms", [](const QVariant &v) { qDebug() << v.toList(); });
    }
    return true;
}
