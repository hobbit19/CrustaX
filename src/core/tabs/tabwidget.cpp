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
#include "tabwidget.h"
#include "webtab.h"

#include <QKeyEvent>
#include <QMouseEvent>

#ifndef ADDBUTTON_PADDING
#define ADDBUTTON_PADDING 4
#endif

TabWidget::TabWidget(QWidget *parent, BrowserWindow* browserwindow):
    QTabWidget(parent)
  , m_browserwindow(browserwindow)
{
    setObjectName("tabwidget");

    m_newtabbutton = new QPushButton(this);
    m_tabbar = new TabBar;
    setTabBar(m_tabbar);
    setElideMode(Qt::ElideRight);
    setTabsClosable(true);
    setMovable(true);
    setContentsMargins(0,0,0,0);

    addNewTabButton();

    connect(this, &TabWidget::currentChanged, this, &TabWidget::handleCurrentChanged);
    connect(this, &TabWidget::tabCloseRequested, this, &TabWidget::closeTab);
    connect(this, SIGNAL(tabsChanged()), SLOT(handleTabsChanged()));
}

QWidget* TabWidget::addViewHelper(bool background)
{
    WebTab* webtab = new WebTab(this);
    int newindex = addTab(webtab, TEXT_ON_NEW_TAB);
    m_tabbar->tabAdded();
    if (!background) {
        setCurrentIndex(newindex);
    }
    emit tabsChanged();
    return webtab;
}

void TabWidget::addView(bool background)
{
    addViewHelper(background);
}

void TabWidget::addView(const QUrl &url, bool background)
{
    WebTab* webtab = dynamic_cast<WebTab*>(addViewHelper(background));
    if (!webtab) {
        return;
    }
    webtab->loadUrl(url);
}

void TabWidget::tabTitleChanged(int index, const QString &title, bool isPinned)
{
    if (isPinned) {
        setTabText(index, "");
    } else {
        setTabText(index, title);
    }
    setTabToolTip(index, title);
    if (m_browserwindow) {
        m_browserwindow->setWindowTitle(title + tr(" - Crusta"));
    }
}

void TabWidget::handleCurrentChanged(int index)
{
    const QString title = tabText(index);
    if (m_browserwindow) {
        m_browserwindow->setWindowTitle(title + tr(" - Crusta"));
    }
}

void TabWidget::addNewTabButton()
{
    m_newtabbutton->setObjectName("add-tab-button");
    m_newtabbutton->setIcon(QIcon::fromTheme("list-add"));
    m_newtabbutton->setToolTip(tr("Add Tab"));
    m_newtabbutton->setFlat(true);
    m_newtabbutton->setFixedSize(TAB_HEIGHT - 2 * ADDBUTTON_PADDING, TAB_HEIGHT - 2 * ADDBUTTON_PADDING);
    m_newtabbutton->move(m_tabbar->getWidth(), m_tabbar->geometry().top() + ADDBUTTON_PADDING);
    connect(m_newtabbutton, &QPushButton::clicked, this, [this]{addView();});
}

void TabWidget::replaceNewTabButton()
{
    m_newtabbutton->move(m_tabbar->getWidth(), m_tabbar->geometry().top() + ADDBUTTON_PADDING);
}

void TabWidget::handleTabsChanged()
{
    resizeTabbar();
    replaceNewTabButton();
}

void TabWidget::resizeEvent(QResizeEvent *event)
{
    QTabWidget::resizeEvent(event);
    resizeTabbar();
    replaceNewTabButton();
}

void TabWidget::resizeTabbar()
{
    m_tabbar->setMaximumWidth(width() - TAB_HEIGHT + 2 * ADDBUTTON_PADDING);
    m_tabbar->setMinimumWidth(m_tabbar->getWidth());
}

void TabWidget::closeTab(const int index)
{
    widget(index)->deleteLater();
    removeTab(index);
    // TODO: pass if tab was pinned
    m_tabbar->tabRemoved();
    emit tabsChanged();

    if (count() == 0) {
        m_browserwindow->mainView()->handleTabWidgetClosed();
        close();
    }
}

void TabWidget::keyReleaseEvent(QKeyEvent *event)
{
    QTabWidget::keyReleaseEvent(event);
    switch (event->key()) {
    // Ctrl + T --> new tab
    case Qt::Key_T:
        if (event->modifiers() == Qt::ControlModifier) {
            addView(QUrl("url"));
        }
        break;
    default:
        break;
    }
}

void TabWidget::mouseReleaseEvent(QMouseEvent *event)
{
    QTabWidget::mouseReleaseEvent(event);

    if(event->button() == Qt::MiddleButton && tabBar()->tabAt(event->pos()) != -1) {
        int index = tabBar()->tabAt(event->pos());
        closeTab(index);
    }
}
