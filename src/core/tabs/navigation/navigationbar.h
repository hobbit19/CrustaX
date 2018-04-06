#ifndef CNAVIGATIONBAR_H
#define CNAVIGATIONBAR_H

#include "actionbutton.h"
#include "addressbar.h"

#include <QHBoxLayout>
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

    AddressBar* m_addressbar;

    void restoreState();
    void saveState();
    void createLayout();
    void showContextMenu(const QPoint& pos);
public:
    NavigationBar(QWidget *parent = nullptr);
};

#endif // CNAVIGATIONBAR_H
