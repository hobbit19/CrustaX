#include "dial.h"
#include "speeddial.h"

#include <QUrl>

SpeedDial::SpeedDial(QWidget *parent):
    QScrollArea(parent)
  , m_cols(4)
{
    setObjectName("speeddial");

    m_gridlayout = new QGridLayout;
    m_gridlayout->setHorizontalSpacing(100);
    m_gridlayout->setVerticalSpacing(100);

    QWidget* widget = new QWidget;
    widget->setLayout(m_gridlayout);
    setWidget(widget);
    setWidgetResizable(true);
}

void SpeedDial::addDial(const QPixmap &pixmap, const QString &title, const QUrl &url)
{
    int row = m_gridlayout->count() / m_cols;
    int col = m_gridlayout->count() % m_cols;
    Dial* dial = new Dial(pixmap, title, url);
    m_gridlayout->addWidget(dial, row, col);
}
