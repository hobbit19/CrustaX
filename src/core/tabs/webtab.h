#ifndef WEBTAB_H
#define WEBTAB_H

#include "navigation/navigationbar.h"
#include "speeddial/speeddial.h"
#include "tabwidget.h"
#include "../webview/webview.h"

#include <QStackedWidget>
#include <QVBoxLayout>
#include <QWidget>

class WebTab : public QWidget
{
    TabWidget* m_tabwidget;
    NavigationBar* m_navigationbar;
    SpeedDial* m_speeddial;
    WebView* m_webview;
    QVBoxLayout* m_vboxlayout;
    QStackedWidget* m_stackedwidget;
    void titleChanged(const QString& title);
    void iconChanged(const QIcon& icon);

    bool m_isPinned;
public:
    WebTab(TabWidget *parent = nullptr);
    void loadUrl(const QUrl& url);
    bool isPinned();
    void setPinned();
};

#endif // WEBTAB_H
