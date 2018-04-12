#include "webpage.h"

#include <QDebug>

WebPage::WebPage(QObject *parent):
    QWebEnginePage(parent)
{

}

WebPage::WebPage(QWebEngineProfile *profile, QObject *parent):
    QWebEnginePage(profile, parent)
{

}

bool WebPage::acceptNavigationRequest(const QUrl &url, NavigationType type, bool isMainFrame)
{
    Q_UNUSED(url);
    Q_UNUSED(isMainFrame);

    if (type == WebPage::NavigationTypeFormSubmitted) {
        runJavaScript("document.forms", [](const QVariant &v) { qDebug() << v.toList(); });
    }
    return true;
}
