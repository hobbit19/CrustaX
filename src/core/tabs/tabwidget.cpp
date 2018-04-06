#include "tabmacros.h"
#include "tabwidget.h"
#include "webtab.h"

#include <iostream>

#ifndef ADDBUTTON_PADDING
#define ADDBUTTON_PADDING 4
#endif

TabWidget::TabWidget(QWidget *parent, QMainWindow* browserwindow):
    QTabWidget(parent)
  , m_browserwindow(browserwindow)
{
    m_newtabbutton = new QPushButton(this);
    m_tabbar = new TabBar;
    setTabBar(m_tabbar);
    setElideMode(Qt::ElideRight);
    setTabsClosable(true);
    setMovable(true);
    setContentsMargins(0,0,0,0);

    addNewTabButton();

    connect(this, &TabWidget::currentChanged, this, &TabWidget::handleCurrentChanged);
    connect(this, SIGNAL(tabsChanged()), SLOT(handleTabsChanged()));
}

QWidget* TabWidget::addViewHelper()
{
    WebTab* webtab = new WebTab(this);
    addTab(webtab, TEXT_ON_NEW_TAB);
    m_tabbar->tabAdded();
    emit tabsChanged();
    return webtab;
}

void TabWidget::addView()
{
    addViewHelper();
}

void TabWidget::addView(const QUrl &url)
{
    WebTab* webtab = dynamic_cast<WebTab*>(addViewHelper());
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
    m_newtabbutton->setFixedSize(TAB_HEIGHT - 2 * ADDBUTTON_PADDING, TAB_HEIGHT - 2 * ADDBUTTON_PADDING);
    m_newtabbutton->move(m_tabbar->getWidth(), ADDBUTTON_PADDING);
    connect(m_newtabbutton, &QPushButton::clicked, this, [this]{addView();});
}

void TabWidget::replaceNewTabButton()
{
    m_newtabbutton->move(m_tabbar->getWidth(), ADDBUTTON_PADDING);
}

void TabWidget::handleTabsChanged()
{
    replaceNewTabButton();
}

void TabWidget::resizeEvent(QResizeEvent *event)
{
    QTabWidget::resizeEvent(event);
    m_tabbar->setMaximumWidth(width() - TAB_HEIGHT + 2 * ADDBUTTON_PADDING);
}
