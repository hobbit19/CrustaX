#ifndef CSIDEPANEL_H
#define CSIDEPANEL_H

#include <QWidget>

class SidePanel: public QWidget {
    int m_minPanelWidth;
public:
    SidePanel(QWidget* parent = 0);
};

#endif // CSIDEPANEL_H
