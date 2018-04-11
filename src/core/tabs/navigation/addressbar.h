#ifndef CADDRESSBAR_H
#define CADDRESSBAR_H

#include <QAbstractItemView>
#include <QCompleter>
#include <QHBoxLayout>
#include <QLineEdit>

class CompleterPopup: public QAbstractItemView
{
public:
    CompleterPopup(QWidget* parent = nullptr);
};

class AddressBar: public QLineEdit
{
    QCompleter* m_completer;
    QHBoxLayout* m_hboxlayout;
public:
    AddressBar(QWidget* parent = nullptr);
};

#endif // CADDRESSBAR_H
