#include "panel.h"

Panel::Panel(QWidget *parent):
    QWidget(parent)
  , m_webview(0)
{
    setObjectName("tabs-panel");

    m_vboxlayout = new QVBoxLayout;
    m_title = new PanelTitle;

    m_vboxlayout->setContentsMargins(0,0,0,0);
    m_vboxlayout->setSpacing(0);
    m_vboxlayout->setStretch(0, 0);
    m_vboxlayout->setStretch(1, 1);
    m_vboxlayout->addWidget(m_title);
    m_title->setText(tr("Panel"));
    m_vboxlayout->addWidget(new QWidget());

    setLayout(m_vboxlayout);
}

void Panel::setWebView(WebView *webview)
{
    m_webview = webview;
}
