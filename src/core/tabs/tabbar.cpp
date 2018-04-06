#include "tabbar.h"
#include <iostream>

TabBar::TabBar(QWidget *parent):
    QTabBar(parent)
  , m_pinnedcount(0)
  , m_normalcount(0)
{
    setDrawBase(true);
    setContextMenuPolicy(Qt::CustomContextMenu);
}

QSize TabBar::tabSizeHint(int index) const
{
    Q_UNUSED(index)
    return QSize(TAB_WIDTH, TAB_HEIGHT);
}

int TabBar::getWidth() const
{
    return qMin(m_pinnedcount * PINNED_TAB_WIDTH + m_normalcount * TAB_WIDTH, maximumWidth());
}

void TabBar::tabAdded()
{
    m_normalcount ++;
}
