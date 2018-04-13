#include "webpage.h"
#include "webview.h"

WebView::WebView(QWidget *parent):
    QWebEngineView(parent)
  , m_loading(false)
{
    setObjectName("webview");

    m_page = new WebPage;

    setPage(m_page);

    connect(this, &WebView::loadStarted, this, [this]{
        m_loading = true;
    });
    connect(this, &WebView::loadFinished, this, [this]{
        m_loading = false;
    });
}

void WebView::zoomIn()
{
    setZoomFactor(zoomFactor() + 20);
}

void WebView::zoomOut()
{
    setZoomFactor(zoomFactor() - 20);
}

void WebView::keyReleaseEvent(QKeyEvent *event)
{
    QWebEngineView::keyReleaseEvent(event);

    switch (event->key()) {
    case Qt::Key_Plus:
    case Qt::Key_Equal:
        if (event->modifiers() == Qt::ControlModifier) {
            zoomIn();
        }
        break;
    case Qt::Key_Minus:
        if (event->modifiers() == Qt::ControlModifier) {
            zoomOut();
        }
        break;
    default:
        break;
    }
}

bool WebView::isLoading()
{
    return m_loading;
}
