#include "searchbox.h"

SearchBox::SearchBox(QWidget* parent):
    QLineEdit(parent)
{
    setPlaceholderText(tr("Search ..."));
    setMaximumWidth(400);
}
