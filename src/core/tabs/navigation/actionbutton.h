#ifndef CACTIONBUTTON_H
#define CACTIONBUTTON_H

#include <QToolButton>

class ActionButton: public QToolButton
{
    int m_side;
public:
    ActionButton(QWidget* parent = nullptr);
    void setFillIcon(const QIcon& icon);
    void setSide(int side);
};

#endif // CACTIONBUTTON_H
