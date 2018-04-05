#include "sidepanel.h"

SidePanel::SidePanel(QWidget *parent):
    QWidget(parent)
  , m_minPanelWidth(40)
{
    setMinimumWidth(m_minPanelWidth);
}
