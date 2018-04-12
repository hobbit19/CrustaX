#ifndef CMAINVIEW_H
#define CMAINVIEW_H

#include <QMainWindow>
#include <QSplitter>

class BrowserWindow;

class MainView : public QSplitter
{
    BrowserWindow* m_browserwindow;
    int m_actualcount;
public:
    MainView(BrowserWindow* parent = nullptr);
    void addView();
    void addView(const QUrl& url);
    void handleTabWidgetClosed();
};

#endif // CMAINVIEW_H
