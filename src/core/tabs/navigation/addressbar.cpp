#include "addressbar.h"
#include "actionbutton.h"

CompleterPopup::CompleterPopup(QWidget *parent):
    QAbstractItemView(parent)
{
    setObjectName("navigation-addressbar-popup");
}

AddressBar::AddressBar(QWidget *parent):
    QLineEdit(parent)
{
    setObjectName("navigation-addressbar");

    m_completer = new QCompleter;
}
