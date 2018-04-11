#ifndef CTABWIDGET_H
#define CTABWIDGET_H

#include "tabbar.h"

#include <QMainWindow>
#include <QPushButton>
#include <QTabWidget>

class TabWidget: public QTabWidget {
    Q_OBJECT

    QMainWindow* m_browserwindow;
    TabBar* m_tabbar;
    QPushButton* m_newtabbutton;

    void handleCurrentChanged(int index);
    void addNewTabButton();
    void replaceNewTabButton();
    QWidget *addViewHelper(bool background);
    void resizeEvent(QResizeEvent* event);
    void resizeTabbar();

public:
    TabWidget(QWidget* parent = nullptr, QMainWindow *browserwindow = nullptr);
    ~TabWidget() {}
    void addView(bool background = false);
    void addView(const QUrl& url, bool background = false);
    void tabTitleChanged(int index, const QString& title, bool isPinned);
    void closeTab(const int index);

public slots:
    void handleTabsChanged();

signals:
    void tabsChanged();
};

#endif // CTABWIDGET_H
