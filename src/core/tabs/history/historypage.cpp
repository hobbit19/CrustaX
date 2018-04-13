#include "historypage.h"

#include <QApplication>
#include <QDateTime>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QTreeWidgetItem>
#include <QVBoxLayout>

#ifndef COLUMNPADDING
#define COLUMNPADDING 50
#endif

HistoryPage::HistoryPage(QWidget* parent):
    QWidget(parent)
{
    m_hboxlayout = new QHBoxLayout;
    m_calender = new QCalendarWidget;
    m_treewidget = new QTreeWidget;

    m_treewidget->setColumnCount(3);
    m_treewidget->setAlternatingRowColors(true);
    QStringList headerlabels;
    headerlabels << tr("Date") << tr("Title") << tr("Address");
    m_treewidget->setHeaderLabels(headerlabels);
    int firstwidth = COLUMNPADDING + QFontMetrics(qApp->font()).width(QDate::currentDate().toString());
    m_treewidget->setColumnWidth(0, firstwidth);

    QVBoxLayout* v0box = new QVBoxLayout;
    v0box->setContentsMargins(0,0,0,0);
    v0box->addWidget(m_calender);
    v0box->addWidget(new QWidget());
    m_calender->setFixedSize(m_calender->sizeHint());
    m_hboxlayout->addLayout(v0box);
    m_hboxlayout->addWidget(m_treewidget);
    m_hboxlayout->setContentsMargins(0,0,0,0);
    m_hboxlayout->setSpacing(0);

    setLayout(m_hboxlayout);
    loadAllHistory();

    connect(m_calender, &QCalendarWidget::clicked, this, &HistoryPage::loadParticularHistory);
    connect(m_treewidget, &QTreeWidget::itemClicked, this, [this](QTreeWidgetItem* item, int column){
        Q_UNUSED(column);

        QDate date = QDateTime::fromString(item->text(0)).date();
        if (date.isValid()) {
            m_calender->setSelectedDate(date);
        }
    });
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
    int datefield = query.record().indexOf("TIME");
    int titlefield = query.record().indexOf("TITLE");
    int addressfield = query.record().indexOf("URL");
    while (query.next()) {
        QDateTime datetime = QDateTime::fromString(query.value(datefield).toString());
        QString title = query.value(titlefield).toString();
        QString address = query.value(addressfield).toString();
        if (datetime.date() == QDate::currentDate()) {
            QTreeWidgetItem* localitem = new QTreeWidgetItem;
            localitem->setText(0, datetime.time().toString());
            localitem->setText(1, title);
            localitem->setText(2, address);
            itemtoday->addChild(localitem);
        } else if (datetime.date().weekNumber() == QDate::currentDate().weekNumber()) {
            QTreeWidgetItem* localitem = new QTreeWidgetItem;
            localitem->setText(0, datetime.toString());
            localitem->setText(1, title);
            localitem->setText(2, address);
            itemtoday->addChild(localitem);
        } else if (datetime.date().month() == QDate::currentDate().month()) {
            QTreeWidgetItem* localitem = new QTreeWidgetItem;
            localitem->setText(0, datetime.toString());
            localitem->setText(1, title);
            localitem->setText(2, address);
            itemtoday->addChild(localitem);
        } else {
            QTreeWidgetItem* localitem = new QTreeWidgetItem;
            localitem->setText(0, datetime.toString());
            localitem->setText(1, title);
            localitem->setText(2, address);
            itemtoday->addChild(localitem);
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
    int datefield = query.record().indexOf("TIME");
    int titlefield = query.record().indexOf("TITLE");
    int addressfield = query.record().indexOf("URL");
    while (query.next()) {
        QDateTime datetime = QDateTime::fromString(query.value(datefield).toString());
        if (date != datetime.date()) {
            continue;
        }
        QString title = query.value(titlefield).toString();
        QString address = query.value(addressfield).toString();
        QTreeWidgetItem* localitem = new QTreeWidgetItem;
        localitem->setText(0, datetime.time().toString());
        localitem->setText(1, title);
        localitem->setText(2, address);
        item->addChild(localitem);
    }
    m_treewidget->clear();
    m_treewidget->addTopLevelItem(item);
}
