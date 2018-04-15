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

#include "actionbutton.h"

ActionButton::ActionButton(QWidget *parent):
    QToolButton(parent)
{
    setObjectName("navigation-actionbutton");

    setAutoRaise(true);
}

void ActionButton::setFillIcon(const QIcon &icon)
{
    setIcon(icon);
    setIconSize(QSize(m_side - 4, m_side - 4));
}

void ActionButton::setSide(int side)
{
    m_side = side;
    setFixedSize(QSize(m_side, m_side));
}
