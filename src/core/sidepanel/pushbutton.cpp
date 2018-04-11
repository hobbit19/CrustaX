#include "pushbutton.h"

PushButton::PushButton(QWidget *parent):
    QPushButton(parent)
{
    setObjectName("sidepanel-pushbutton");

    setFlat(true);
}
