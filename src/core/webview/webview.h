#ifndef CWEBVIEW_H
#define CWEBVIEW_H

#include <QKeyEvent>
#include <QWebEngineView>

class WebPage;

class WebView: public QWebEngineView
{
    WebPage* m_page;
    void keyReleaseEvent(QKeyEvent *event);
public:
    WebView(QWidget* parent = nullptr);
    void zoomIn();
    void zoomOut();
};

#endif // CWEBVIEW_H
