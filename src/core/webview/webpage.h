#ifndef CWEBPAGE_H
#define CWEBPAGE_H

#include <QWebEnginePage>
#include <QWebEngineProfile>

class WebPage : public QWebEnginePage
{
protected:
    bool acceptNavigationRequest(const QUrl &url, NavigationType type, bool isMainFrame);
public:
    WebPage(QObject *parent = nullptr);
    WebPage(QWebEngineProfile *profile, QObject *parent = nullptr);
};

#endif // CWEBPAGE_H
