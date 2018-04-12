#include "../../browserwindow.h"
#include "mainview.h"
#include "../tabs/tabwidget.h"

#include <QDebug>
#include <QUrl>

MainView::MainView(BrowserWindow *parent):
    QSplitter(parent)
  , m_browserwindow(parent)
  , m_actualcount(0)
{
    setObjectName("mainview");

    setContentsMargins(0,0,0,0);
    addView(QUrl("url"));
}

void MainView::addView()
{
    TabWidget* tabwidget = new TabWidget(this, m_browserwindow);
    addWidget(tabwidget);
    m_actualcount ++;
}

void MainView::addView(const QUrl& url)
{
    TabWidget* tabwidget = new TabWidget(this, m_browserwindow);
    tabwidget->addView(url);
    addWidget(tabwidget);
    m_actualcount ++;
}

void MainView::handleTabWidgetClosed(){
    m_actualcount --;
    if (m_actualcount == 0) {
        m_browserwindow->close();
    }
}
