#ifndef WEBTAB_H
#define WEBTAB_H

#include "navigation/navigationbar.h"
#include "../webview/webview.h"

#include <QVBoxLayout>
#include <QWidget>

class WebTab : public QWidget
{
    NavigationBar* m_navigationbar;
    WebView* m_webview;
    QVBoxLayout* m_vboxlayout;
public:
    WebTab(QWidget *parent = nullptr);
    void loadUrl(const QUrl& url);
};

#endif // WEBTAB_H
