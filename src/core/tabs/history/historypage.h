#ifndef CHISTORYPAGE_H
#define CHISTORYPAGE_H

#include <QCalendarWidget>
#include <QDate>
#include <QHBoxLayout>
#include <QTreeWidget>
#include <QWidget>

class HistoryPage : public QWidget
{
    Q_OBJECT

    QHBoxLayout* m_hboxlayout;
    QCalendarWidget* m_calender;
    QTreeWidget* m_treewidget;

    void loadAllHistory();
    void loadParticularHistory(const QDate& date);
public:
    HistoryPage(QWidget *parent = nullptr);
};

#endif // CHISTORYPAGE_H