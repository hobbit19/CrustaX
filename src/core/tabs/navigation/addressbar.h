#ifndef CADDRESSBAR_H
#define CADDRESSBAR_H

#include <QHBoxLayout>
#include <QLineEdit>

class AddressBar: public QLineEdit
{
    QHBoxLayout* m_hboxlayout;
public:
    AddressBar(QWidget* parent = nullptr);
};

#endif // ADDRESSBAR_H
