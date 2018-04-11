#include "webview.h"

WebView::WebView(QWidget *parent):
    QWebEngineView(parent)
{
    setObjectName("webview");
}
