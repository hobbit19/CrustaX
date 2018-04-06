#include "../cmacros.h"
#include "webtab.h"

WebTab::WebTab(QWidget *parent):
    QWidget(parent)
{
    m_navigationbar = new NavigationBar;
    m_webview = new WebView;
    m_vboxlayout = new QVBoxLayout;

    m_webview->load(QUrl("https://google.com"));

    m_vboxlayout->addSpacing(0);
    m_vboxlayout->setContentsMargins(0,0,0,0);
    m_vboxlayout->addWidget(m_navigationbar);
    m_vboxlayout->addWidget(m_webview);

    setLayout(m_vboxlayout);
}

void WebTab::loadUrl(const QUrl& url)
{
    Q_UNUSED(url);
}
