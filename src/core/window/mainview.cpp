#include "mainview.h"
#include "../tabs/tabwidget.h"

#include <QUrl>

MainView::MainView(QWidget *parent):
    QSplitter(parent)
{
    setContentsMargins(0,0,0,0);
    addView(QUrl("url"));
}

void MainView::addView()
{
    TabWidget* tabwidget = new TabWidget;
    addWidget(tabwidget);
}

void MainView::addView(const QUrl& url)
{
    TabWidget* tabwidget = new TabWidget;
    tabwidget->addView(url);
    addWidget(tabwidget);
}
