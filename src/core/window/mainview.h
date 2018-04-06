#ifndef CMAINVIEW_H
#define CMAINVIEW_H

#include <QSplitter>

class MainView : public QSplitter
{
public:
    MainView(QWidget* parent = nullptr);
    void addView();
    void addView(const QUrl& url);
};

#endif // CMAINVIEW_H
