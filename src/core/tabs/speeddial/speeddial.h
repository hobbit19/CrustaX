#ifndef CSPEEDDIAL_H
#define CSPEEDDIAL_H

#include <QGridLayout>
#include <QScrollArea>

class SpeedDial : public QScrollArea
{
    QGridLayout* m_gridlayout;
    int m_cols;
public:
    SpeedDial(QWidget *parent = nullptr);
    void addDial(const QPixmap& pixmap, const QString& title, const QUrl& url);
};

#endif // CSPEEDDIAL_H
