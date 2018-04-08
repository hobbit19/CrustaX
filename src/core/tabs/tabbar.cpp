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
    int width = TAB_WIDTH;
    int actualtabbarwidth = m_pinnedcount * PINNED_TAB_WIDTH + m_normalcount * width;
    int maxtabbarwidth = maximumWidth();
    if (actualtabbarwidth > maxtabbarwidth) {
        width = (maxtabbarwidth - m_pinnedcount * PINNED_TAB_WIDTH) / m_normalcount;
        width = (width > MINIMUM_TAB_WIDTH) ? width : MINIMUM_TAB_WIDTH;
    }
    return QSize(width, TAB_HEIGHT);
}

int TabBar::getWidth() const
{
    /* this will return the width of the tabbar
     * assuming every tab to be of size give by
     * TAB_WIDTH, this helps in check for overflow
     * on tabbar */
    int pinnedtabbarwidth = m_pinnedcount * PINNED_TAB_WIDTH;
    int normaltabbarwidth = m_normalcount * TAB_WIDTH;
    int totaltabbarwidth = pinnedtabbarwidth + normaltabbarwidth;
    return qMin(totaltabbarwidth, maximumWidth());
}

void TabBar::tabAdded()
{
    // Pinned tab will never be added, its just converted
    m_normalcount ++;
}
