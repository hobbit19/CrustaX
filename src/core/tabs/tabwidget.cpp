#include "tabmacros.h"
#include "tabwidget.h"
#include "webtab.h"

TabWidget::TabWidget(QWidget *parent):
    QTabWidget(parent)
{
    setContentsMargins(0,0,0,0);
}

void TabWidget::addView(const QUrl &url)
{
    WebTab* webtab = new WebTab;
    webtab->loadUrl(url);
    addTab(webtab, TEXT_ON_NEW_TAB);
}
