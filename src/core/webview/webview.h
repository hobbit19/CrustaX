#ifndef CWEBVIEW_H
#define CWEBVIEW_H

#include <QKeyEvent>
#include <QWebEngineView>

class WebPage;

class WebView: public QWebEngineView
{
    WebPage* m_page;
    mutable bool m_loading;
    void keyReleaseEvent(QKeyEvent *event);
public:
    WebView(QWidget* parent = nullptr);
    void zoomIn();
    void zoomOut();
    bool isLoading();
};

#endif // CWEBVIEW_H
