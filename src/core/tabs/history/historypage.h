#ifndef CHISTORYPAGE_H
#define CHISTORYPAGE_H

#include <QCalendarWidget>
#include <QDate>
#include <QHBoxLayout>
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
