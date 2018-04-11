#include "paneltitle.h"

PanelTitle::PanelTitle(QWidget *parent):
    QLabel(parent)
{
    setObjectName("tabs-paneltitle");

    setAlignment(Qt::AlignCenter);
}
