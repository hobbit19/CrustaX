#ifndef CSIDEPANEL_H
#define CSIDEPANEL_H

#include "pushbutton.h"

#include <QVBoxLayout>
#include <QWidget>

class SidePanel: public QWidget {

    int m_closePanelWidth;
    int m_openPanelWidth;
    bool m_isPanelOpen;
    bool m_isPinned;

    QVBoxLayout* m_vboxlayout;

    PushButton* m_bookmarksButton;
    PushButton* m_historyButton;
    PushButton* m_downloadsButton;
    PushButton* m_addPanelButton;

    void restoreState();
    void saveState();

    void createPanel();
    void createAPanels();
    void createBPanels();

    void showContextMenu(const QPoint &pos);
public:
    SidePanel(QWidget* parent = nullptr);
};

#endif // CSIDEPANEL_H
