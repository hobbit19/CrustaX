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

#include "historypage.h"
#include "../utils/pagebutton.h"
#include "../utils/searchbox.h"

#include <QApplication>
#include <QDateTime>
#include <QDebug>
#include <QHBoxLayout>
#include <QSpacerItem>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QTreeWidgetItem>

#ifndef COLUMNPADDING
#define COLUMNPADDING 50
#endif

HistoryPage::HistoryPage(QWidget* parent):
    QWidget(parent)
{
    m_vboxlayout = new QVBoxLayout;
    m_calender = new QCalendarWidget;
    m_treewidget = new QTreeWidget;

    m_treewidget->setColumnCount(4);
    m_treewidget->setAlternatingRowColors(true);
    QStringList headerlabels;
    headerlabels << tr("Date") << tr("Title") << tr("Address") << tr("Visits");
    m_treewidget->setHeaderLabels(headerlabels);
    int firstwidth = COLUMNPADDING + QFontMetrics(qApp->font()).width(QDate::currentDate().toString());
    m_treewidget->setColumnWidth(0, firstwidth);

    QHBoxLayout* h0box = new QHBoxLayout;
    SearchBox* searchbox = new SearchBox;
    h0box->addWidget(searchbox);
    h0box->addWidget(new QWidget());
    PageButton* refreshbutton = new PageButton;
    refreshbutton->setToolTip(tr("Refresh history"));
    h0box->addWidget(refreshbutton);
    PageButton* clearbutton = new PageButton;
    clearbutton->setToolTip(tr("Clear all history"));
    h0box->addWidget(clearbutton);
    connect(refreshbutton, &PageButton::clicked, this, &HistoryPage::loadAllHistory);

    QVBoxLayout* v0box = new QVBoxLayout;
    v0box->setContentsMargins(0,0,0,0);
    v0box->addWidget(m_calender);
    v0box->addWidget(new QWidget());
    m_calender->setFixedSize(m_calender->sizeHint());
    QHBoxLayout* h1box = new QHBoxLayout;
    h1box->addLayout(v0box);
    h1box->addWidget(m_treewidget);
    h1box->setContentsMargins(0,0,0,0);
    h1box->setSpacing(0);

    m_vboxlayout->addLayout(h0box);
    m_vboxlayout->addLayout(h1box);

    setLayout(m_vboxlayout);
    loadAllHistory();

    connect(m_calender, &QCalendarWidget::clicked, this, &HistoryPage::loadParticularHistory);
    connect(m_treewidget, &QTreeWidget::itemClicked, this, [this](QTreeWidgetItem* item, int column){
        Q_UNUSED(column);

        QDate date = QDateTime::fromString(item->text(0)).date();
        if (date.isValid()) {
            m_calender->setSelectedDate(date);
        }
    });

    getTopPages();
}

void HistoryPage::loadAllHistory()
{
    QTreeWidgetItem* itemtoday = new QTreeWidgetItem;
    itemtoday->setText(0, tr("Today"));
    QTreeWidgetItem* itemweek = new QTreeWidgetItem;
    itemweek->setText(0, tr("This week"));
    QTreeWidgetItem* itemmonth = new QTreeWidgetItem;
    itemmonth->setText(0, tr("This month"));
    QTreeWidgetItem* itemolder = new QTreeWidgetItem;
    itemolder->setText(0, tr("Older"));
    QSqlQuery query;
    query.exec("SELECT * FROM HISTORY");
    while (query.next()) {
        QDateTime datetime = QDateTime::fromString(query.value("TIME").toString());
        QString title = query.value("TITLE").toString();
        QString address = query.value("URL").toString();
        int count = query.value("COUNT").toInt();
        QByteArray faviconbuffer = query.value("FAVICON").toByteArray();
        QPixmap faviconpixmap;
        faviconpixmap.loadFromData(faviconbuffer);
        QTreeWidgetItem* localitem = new QTreeWidgetItem;
        localitem->setText(0, datetime.time().toString());
        localitem->setText(1, title);
        localitem->setIcon(1, QIcon(faviconpixmap));
        localitem->setText(2, address);
        localitem->setText(3, QString::number(count));
        if (datetime.date() == QDate::currentDate()) {
            itemtoday->addChild(localitem);
        } else if (datetime.date().weekNumber() == QDate::currentDate().weekNumber()) {
            itemweek->addChild(localitem);
        } else if (datetime.date().month() == QDate::currentDate().month()) {
            itemmonth->addChild(localitem);
        } else {
            itemolder->addChild(localitem);
        }
    }
    m_treewidget->clear();
    m_treewidget->addTopLevelItem(itemtoday);
    m_treewidget->addTopLevelItem(itemweek);
    m_treewidget->addTopLevelItem(itemmonth);
    m_treewidget->addTopLevelItem(itemolder);
}

void HistoryPage::loadParticularHistory(const QDate &date)
{
    QTreeWidgetItem* item = new QTreeWidgetItem;
    item->setText(0, date.toString());
    QSqlQuery query;
    // TODO: optimize it -
    //   its selecting everyting because time is stored as
    //   QDateTime and not as QDate, so they cannot be compared
    //   in the sql query, rather comparision is made over the
    //   whole query
    query.prepare("SELECT * FROM HISTORY");
    query.exec();
    while (query.next()) {
        QDateTime datetime = QDateTime::fromString(query.value("TIME").toString());
        if (date != datetime.date()) {
            continue;
        }
        QString title = query.value("TITLE").toString();
        QString address = query.value("URL").toString();
        int count = query.value("COUNT").toInt();
        QByteArray faviconbuffer = query.value("FAVICON").toByteArray();
        QPixmap faviconpixmap;
        faviconpixmap.loadFromData(faviconbuffer);
        QTreeWidgetItem* localitem = new QTreeWidgetItem;
        localitem->setText(0, datetime.time().toString());
        localitem->setText(1, title);
        localitem->setIcon(1, QIcon(faviconpixmap));
        localitem->setText(2, address);
        localitem->setText(3, QString::number(count));
        item->addChild(localitem);
    }
    m_treewidget->clear();
    m_treewidget->addTopLevelItem(item);
}

QStringList HistoryPage::getTopPages()
{
    QStringList result;
    QSqlQuery query;
    query.exec("SELECT * FROM HISTORY ORDER BY COUNT DESC LIMIT 5");
    while (query.next()) {
        result << query.value("URL").toString() << QString::number(query.value("COUNT").toInt());
    }
    return result;
}
