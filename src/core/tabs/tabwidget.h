#ifndef CTABWIDGET_H
#define CTABWIDGET_H

#include <QTabWidget>

class TabWidget: public QTabWidget {
public:
    TabWidget(QWidget* parent = nullptr);
    void addView(const QUrl& url);
};

#endif // CTABWIDGET_H
