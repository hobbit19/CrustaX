#include "../../cmacros.h"
#include "actionbutton.h"

ActionButton::ActionButton(QWidget *parent):
    QPushButton(parent)
  , m_isPresent(true)
{
    setFlat(true);
}

void ActionButton::setFillIcon(const QIcon &icon)
{
    setIcon(icon);
    setIconSize(QSize(20,20));
}

void ActionButton::setSide(int side)
{
    setFixedSize(QSize(side, side));
}

bool ActionButton::isPresent()
{
    return m_isPresent;
}
