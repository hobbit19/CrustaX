#ifndef CMAINVIEW_H
#define CMAINVIEW_H

#include <QMainWindow>
#include <QSplitter>

class MainView : public QSplitter
{
    QMainWindow* m_browserwindow;
public:
    MainView(QMainWindow* parent = nullptr);
    void addView();
    void addView(const QUrl& url);
};

#endif // CMAINVIEW_H
