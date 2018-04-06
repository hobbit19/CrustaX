#ifndef CTABBAR_H
#define CTABBAR_H

#include <QTabBar>

#define TAB_HEIGHT 36
#define PINNED_TAB_WIDTH 36
#define TAB_WIDTH 200

class TabBar : public QTabBar
{
    int m_pinnedcount;
    int m_normalcount;

public:
    TabBar(QWidget* parent = nullptr);
    int getWidth() const;
    void tabAdded();
protected:
    QSize tabSizeHint(int index) const;
};

#endif // CTABBAR_H
