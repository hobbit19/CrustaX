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

#include "addressbar.h"
#include "actionbutton.h"

#include <QDebug>

CompleterPopup::CompleterPopup(QWidget *parent):
    QAbstractItemView(parent)
{
    setObjectName("navigation-addressbar-popup");
}

AddressBar::AddressBar(QWidget *parent):
    QLineEdit(parent)
{
    setObjectName("navigation-addressbar");

    addAction(QIcon::fromTheme("edit-copy"), ActionPosition::LeadingPosition);
    addAction(QIcon::fromTheme("edit-copy"), ActionPosition::TrailingPosition);

    m_completer = new QCompleter;
    connect(this, &AddressBar::returnPressed, this, &AddressBar::handleReturnPressed);
}

void AddressBar::setAddress(QUrl address)
{
    m_fulladdres = address;
    setText(m_fulladdres.toString(QUrl::RemoveQuery | QUrl::RemoveFragment));
}

void AddressBar::focusInEvent(QFocusEvent *event)
{
    QLineEdit::focusInEvent(event);

    setText(m_fulladdres.toString());
}

void AddressBar::focusOutEvent(QFocusEvent *event)
{
    QLineEdit::focusOutEvent(event);

    setText(m_fulladdres.toString(QUrl::RemoveQuery | QUrl::RemoveFragment));
}

void AddressBar::handleReturnPressed()
{
    /**
     * Note that schemes are handled here rather than
     * schemehandler class for qwebengine, because the
     * custom scheme is handled by changing the currentIndex
     * of stackedwidget in webtab
     */
    QUrl address = QUrl(text());
    QString scheme = address.scheme();
    if (scheme == "crusta") {
        emit handleInternalScheme(address);
    } else if (scheme == "http" || scheme == "https") {
        emit handleUrlRequested(address);
    } else if (scheme.isNull()) {
        //! TODO: Implement Default search engine manager
        emit handleUrlRequested(address);
    }
    m_fulladdres = address;
}
