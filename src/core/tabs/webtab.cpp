#include "../cmacros.h"
#include "../../scripts/internalscripts.h"
#include "webtab.h"

#include "history/historypage.h"

#include <QApplication>
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
    m_stackedwidget->setCurrentIndex(0);
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

    // add site to history
    QSqlQuery query;
    query.prepare("INSERT INTO HISTORY (TITLE, URL, TIME, LOADTIME) VALUES (?, ?, ?, ?)");
    query.addBindValue(m_webview->title());
    query.addBindValue(m_webview->url().toString());
    query.addBindValue(QDateTime::currentDateTime().toString());
    query.addBindValue(m_navigationbar->loadTime());
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
}

bool WebTab::isPinned()
{
    return m_isPinned;
}

void  WebTab::setPinned()
{
    m_isPinned = true;
}
