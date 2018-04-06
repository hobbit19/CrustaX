#ifndef CWEBVIEW_H
#define CWEBVIEW_H

#include <QWebEngineView>

class WebView: public QWebEngineView
{
public:
    WebView(QWidget* parent = nullptr);
};

#endif // CWEBVIEW_H
