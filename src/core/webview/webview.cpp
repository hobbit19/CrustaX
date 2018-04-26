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
#include "webview.h"

WebView::WebView(QWidget *parent):
    QWebEngineView(parent)
  , m_loading(false)
{
    setObjectName("webview");

    m_page = new WebPage;

    setPage(m_page);

    connect(this, &WebView::loadStarted, this, [this]{
        m_loading = true;
    });
    connect(this, &WebView::loadFinished, this, [this]{
        m_loading = false;
    });
}

void WebView::zoomIn()
{
    setZoomFactor(zoomFactor() + 20);
}

void WebView::zoomOut()
{
    setZoomFactor(zoomFactor() - 20);
}

void WebView::keyReleaseEvent(QKeyEvent *event)
{
    QWebEngineView::keyReleaseEvent(event);

    switch (event->key()) {
    case Qt::Key_Plus:
    case Qt::Key_Equal:
        if (event->modifiers() == Qt::ControlModifier) {
            zoomIn();
        }
        break;
    case Qt::Key_Minus:
        if (event->modifiers() == Qt::ControlModifier) {
            zoomOut();
        }
        break;
    default:
        break;
    }
}

bool WebView::isLoading()
{
    return m_loading;
}

void WebView::scrollToPos(const QPoint &pos)
{
    page()->runJavaScript(QString("window.scrollTo(%1, %2);").arg(pos.x()).arg(pos.y()));
}
