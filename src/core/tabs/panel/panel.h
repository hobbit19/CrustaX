#ifndef CPANEL_H
#define CPANEL_H

#include "paneltitle.h"
#include "../../webview/webview.h"

#include <QLabel>
#include <QVBoxLayout>
#include <QWidget>

#define MAX_PANEL_WIDTH 200

class Panel : public QWidget
{
    Q_OBJECT

    QVBoxLayout* m_vboxlayout;
    WebView* m_webview;
    PanelTitle* m_title;
public:
    explicit Panel(QWidget *parent = nullptr);
    void setWebView(WebView* webview);
};

#endif // CPANEL_H
