#ifndef CACTIONBUTTON_H
#define CACTIONBUTTON_H

#include <QPushButton>

class ActionButton: public QPushButton
{
    int m_side;
public:
    ActionButton(QWidget* parent = nullptr);
    void setFillIcon(const QIcon& icon);
    void setSide(int side);
};

#endif // CACTIONBUTTON_H
