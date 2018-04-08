#include "../cmacros.h"
#include "../../scripts/internalscripts.h"
#include "webtab.h"

#include <QApplication>

WebTab::WebTab(TabWidget *parent):
    QWidget(parent)
  , m_tabwidget(parent)
  , m_isPinned(false)
{
    m_navigationbar = new NavigationBar;
    m_speeddial = new SpeedDial;
    m_webview = new WebView;
    m_vboxlayout = new QVBoxLayout;
    m_stackedwidget = new QStackedWidget;

    m_webview->load(QUrl("https://google.com"));

    m_vboxlayout->addSpacing(0);
    m_vboxlayout->setContentsMargins(0,0,0,0);
    m_vboxlayout->addWidget(m_navigationbar);

    m_stackedwidget->addWidget(m_speeddial);
    m_stackedwidget->addWidget(m_webview);
    m_stackedwidget->setCurrentIndex(1);
    m_vboxlayout->addWidget(m_stackedwidget);

    setLayout(m_vboxlayout);

    connect(m_webview, &WebView::loadStarted, m_navigationbar, &NavigationBar::loadStarted);
    connect(m_webview, &WebView::loadFinished, this, &WebTab::loadFinished);
    connect(m_webview, &WebView::loadProgress, m_navigationbar, &NavigationBar::loadProgress);
    connect(m_webview, &WebView::titleChanged, this, &WebTab::titleChanged);
    connect(m_webview, &WebView::iconChanged, this, &WebTab::iconChanged);
}

void WebTab::loadUrl(const QUrl& url)
{
    Q_UNUSED(url);
}

void WebTab::loadFinished()
{
    m_navigationbar->loadFinished();

    QString src = InternalScripts::getFramework();
    m_webview->page()->runJavaScript(src, [](const QVariant &v) { qDebug() << v.toList(); });
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
}

bool WebTab::isPinned()
{
    return m_isPinned;
}

void  WebTab::setPinned()
{
    m_isPinned = true;
}
