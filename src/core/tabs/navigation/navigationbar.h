#ifndef CNAVIGATIONBAR_H
#define CNAVIGATIONBAR_H

#include "actionbutton.h"
#include "addressbar.h"

#include <QHBoxLayout>
#include <QLabel>
#include <QTime>
#include <QWidget>

class NavigationBar : public QWidget
{
    int m_height;
    QHBoxLayout* m_hboxlayout;

    ActionButton* m_backbutton;
    ActionButton* m_forwardbutton;
    ActionButton* m_topbutton;
    ActionButton* m_reloadstopbutton;
    ActionButton* m_homebutton;
    QLabel* m_timerbutton;

    AddressBar* m_addressbar;

    QTime m_startmillis;

    void restoreState();
    void saveState();
    void createLayout();
    void showContextMenu(const QPoint& pos);
public:
    NavigationBar(QWidget *parent = nullptr);
    void loadStarted();
    void loadFinished();
    void loadProgress(const int& progress);
};

#endif // CNAVIGATIONBAR_H
