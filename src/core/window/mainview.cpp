#include "mainview.h"
#include "../tabs/tabwidget.h"

#include <QUrl>

MainView::MainView(QMainWindow *parent):
    QSplitter(parent)
  , m_browserwindow(parent)
{
    setObjectName("mainview");

    setContentsMargins(0,0,0,0);
    addView(QUrl("url"));
}

void MainView::addView()
{
    TabWidget* tabwidget = new TabWidget(this, m_browserwindow);
    addWidget(tabwidget);
}

void MainView::addView(const QUrl& url)
{
    TabWidget* tabwidget = new TabWidget(this, m_browserwindow);
    tabwidget->addView(url);
    tabwidget->addView(url);
    tabwidget->addView(url);
    addWidget(tabwidget);
}
