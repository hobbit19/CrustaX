#include "addressbar.h"
#include "actionbutton.h"

CompleterPopup::CompleterPopup(QWidget *parent):
    QAbstractItemView(parent)
{
    setObjectName("navigation-addressbar");
}

AddressBar::AddressBar(QWidget *parent):
    QLineEdit(parent)
{
    m_completer = new QCompleter;
}
