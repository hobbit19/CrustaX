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

#include "../cmacros.h"
#include "../../scripts/internalscripts.h"
#include "webtab.h"

#include "history/historypage.h"

#include <QApplication>
#include <QBuffer>
#include <QPixmap>
#include <QSqlQuery>

WebTab::WebTab(TabWidget *parent):
    QWidget(parent)
  , m_tabwidget(parent)
  , m_isPinned(false)
{
    setObjectName("webtab");

    m_navigationbar = new NavigationBar;
    m_speeddial = new SpeedDial;
    m_splitter = new QSplitter;
    m_panel = new Panel;
    m_webview = new WebView;
    m_vboxlayout = new QVBoxLayout;
    m_stackedwidget = new QStackedWidget;

    m_webview->load(QUrl("https://google.com"));

    m_vboxlayout->addSpacing(0);
    m_vboxlayout->setContentsMargins(0,0,0,0);
    m_vboxlayout->addWidget(m_navigationbar);

    m_stackedwidget->addWidget(new HistoryPage);
    m_stackedwidget->addWidget(m_splitter);
    m_stackedwidget->setCurrentIndex(1);
    m_splitter->setContentsMargins(0,0,0,0);
    m_splitter->setMidLineWidth(0);
    m_splitter->addWidget(m_panel);
    // hide panel for now
    m_panel->hide();
    m_splitter->addWidget(m_webview);
    m_splitter->setStretchFactor(0, 0);
    m_vboxlayout->addWidget(m_stackedwidget);

    setLayout(m_vboxlayout);

    connect(m_webview, &WebView::loadStarted, m_navigationbar, &NavigationBar::loadStarted);
    connect(m_webview, &WebView::loadFinished, this, &WebTab::loadFinished);
    connect(m_webview, &WebView::loadProgress, m_navigationbar, &NavigationBar::loadProgress);
    connect(m_webview, &WebView::titleChanged, this, &WebTab::titleChanged);
    connect(m_webview, &WebView::iconChanged, this, &WebTab::iconChanged);
    connect(m_webview, &WebView::urlChanged, m_navigationbar, &NavigationBar::setAddress);

    connect(m_navigationbar->backButton(), &ActionButton::clicked, m_webview, &WebView::back);
    connect(m_navigationbar->forwardButton(), &ActionButton::clicked, m_webview, &WebView::forward);
    connect(m_navigationbar->reloadStopButton(), &ActionButton::clicked, this, [this]{
        if (m_webview->isLoading()) {
            m_webview->stop();
        } else {
            m_webview->reload();
        }
    });

}

void WebTab::loadUrl(const QUrl& url)
{
    Q_UNUSED(url);
}

void WebTab::loadFinished()
{
    m_navigationbar->loadFinished();
    QString displayurl = m_webview->url().toString(QUrl::RemoveQuery | QUrl::RemoveFragment);

    // add site to history
    QSqlQuery query;
    query.prepare("SELECT * FROM HISTORY WHERE URL = ?");
    query.bindValue(0, displayurl);
    query.exec();
    int count = 0;
    while (query.next()) {
        count = query.value("COUNT").toInt();
        // Its expected that this break is never used
        // ... or you can find a case when it does :P
        break;
    }
    if (count) {
        query.prepare("UPDATE HISTORY SET TITLE = ?, TIME = ?, LOADTIME = ?, COUNT = ? WHERE URL = ?");
        query.bindValue(0, m_webview->title());
        query.bindValue(1, QDateTime::currentDateTime().toString());
        query.bindValue(2, m_navigationbar->loadTime());
        query.bindValue(3, count + 1);
        query.bindValue(4, displayurl);
    } else {
        query.prepare("INSERT INTO HISTORY (TITLE, URL, TIME, LOADTIME, COUNT) VALUES (?, ?, ?, ?, ?)");
        query.bindValue(0, m_webview->title());
        query.bindValue(1, displayurl);
        query.bindValue(2, QDateTime::currentDateTime().toString());
        query.bindValue(3, m_navigationbar->loadTime());
        query.bindValue(4, 1);
    }
    query.exec();

//    QString src = InternalScripts::getFramework();
//    m_webview->page()->runJavaScript(src, [](const QVariant &v) { qDebug() << v.toList(); });
}

void WebTab::titleChanged(const QString &title)
{
    const int index = m_tabwidget->indexOf(this);
    m_tabwidget->tabTitleChanged(index, title, m_isPinned);
}

void WebTab::iconChanged(const QIcon &icon)
{
    const int index = m_tabwidget->indexOf(this);
    m_tabwidget->setTabIcon(index, icon);

    QByteArray faviconbuffer;
    QBuffer inBuffer(&faviconbuffer);
    inBuffer.open(QIODevice::WriteOnly);
    icon.pixmap(QSize(16,16)).save(&inBuffer, "PNG");
    inBuffer.close();

    QString displayurl = m_webview->url().toString(QUrl::RemoveQuery | QUrl::RemoveFragment);

    // add site to history
    QSqlQuery query;
    query.prepare("UPDATE HISTORY SET FAVICON = ? WHERE URL = ?");
    query.bindValue(0, faviconbuffer);
    query.bindValue(1, displayurl);
    query.exec();
}

bool WebTab::isPinned()
{
    return m_isPinned;
}

void  WebTab::setPinned()
{
    m_isPinned = true;
}
