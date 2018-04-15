/**
 * Crusta X - Qt webbrowser
 * Copyright (C) 2018 Anmol Gautam <anmol@crustabrowser.com>
 *
 * THIS FILE IS A PART OF CRUSTA X
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef CADDRESSBAR_H
#define CADDRESSBAR_H

#include <QAbstractItemView>
#include <QCompleter>
#include <QFocusEvent>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QUrl>

class CompleterPopup: public QAbstractItemView
{
public:
    CompleterPopup(QWidget* parent = nullptr);
};

class AddressBar: public QLineEdit
{
    Q_OBJECT

    QCompleter* m_completer;
    QHBoxLayout* m_hboxlayout;

    QUrl m_fulladdres;

    void focusInEvent(QFocusEvent* event);
    void focusOutEvent(QFocusEvent* event);
    void handleReturnPressed();
public:
    AddressBar(QWidget* parent = nullptr);
    void setAddress(QUrl address);

signals:
    void handleInternalScheme(QUrl address);
};

#endif // CADDRESSBAR_H
