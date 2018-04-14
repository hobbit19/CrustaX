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

#ifndef CHISTORYPAGE_H
#define CHISTORYPAGE_H

#include <QCalendarWidget>
#include <QDate>
#include <QTreeWidget>
#include <QVBoxLayout>
#include <QWidget>

class HistoryPage : public QWidget
{
    Q_OBJECT

    QVBoxLayout* m_vboxlayout;
    QCalendarWidget* m_calender;
    QTreeWidget* m_treewidget;

    void loadAllHistory();
    void loadParticularHistory(const QDate& date);
public:
    HistoryPage(QWidget *parent = nullptr);
    QStringList getTopPages();
};

#endif // CHISTORYPAGE_H
