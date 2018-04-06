#include "../../cmacros.h"
#include "navigationbar.h"

#include <QMenu>

NavigationBar::NavigationBar(QWidget *parent):
    QWidget(parent)
  , m_height(NAVIGATIONBAR_HEIGHT)
{
    m_hboxlayout = new QHBoxLayout;
    m_backbutton = new ActionButton;
    m_forwardbutton = new ActionButton;
    m_topbutton = new ActionButton;
    m_reloadstopbutton = new ActionButton;
    m_homebutton = new ActionButton;
    m_addressbar = new AddressBar;

    m_backbutton->setFillIcon(QIcon(":/res/icons/back.svg"));
    m_backbutton->setSide(NAVIGATIONBAR_HEIGHT - 4);
    m_forwardbutton->setFillIcon(QIcon(":/res/icons/forward.svg"));
    m_forwardbutton->setSide(NAVIGATIONBAR_HEIGHT - 4);
    m_topbutton->setFillIcon(QIcon(":/res/icons/top.svg"));
    m_topbutton->setSide(NAVIGATIONBAR_HEIGHT - 4);
    m_reloadstopbutton->setFillIcon(QIcon(":/res/icons/refresh.svg"));
    m_reloadstopbutton->setSide(NAVIGATIONBAR_HEIGHT - 4);
    m_homebutton->setFillIcon(QIcon(":/res/icons/home.svg"));
    m_homebutton->setSide(NAVIGATIONBAR_HEIGHT - 4);

    m_hboxlayout->setContentsMargins(2,2,2,2);
    m_hboxlayout->setSpacing(0);

    createLayout();

    setLayout(m_hboxlayout);
    restoreState();

    setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this, &NavigationBar::customContextMenuRequested, this, &NavigationBar::showContextMenu);
}

void NavigationBar::restoreState()
{
    setFixedHeight(m_height);
}

void NavigationBar::saveState()
{

}

void NavigationBar::createLayout()
{
    m_hboxlayout->addWidget(m_backbutton);
    m_hboxlayout->addWidget(m_forwardbutton);
    m_hboxlayout->addWidget(m_topbutton);
    m_hboxlayout->addWidget(m_reloadstopbutton);
    m_hboxlayout->addWidget(m_addressbar);
    m_hboxlayout->addWidget(m_homebutton);
}

void NavigationBar::showContextMenu(const QPoint &pos)
{
    QMenu* menu = new QMenu;
    QAction* act_back = menu->addAction("Back");
    act_back->setCheckable(true);
    QAction* act_forward = menu->addAction("Forward");
    act_forward->setCheckable(true);
    QAction* act_reload = menu->addAction("Reload-Stop");
    act_reload->setCheckable(true);
    QAction* act_home = menu->addAction("Home");
    act_home->setCheckable(true);
    menu->exec(mapToGlobal(pos));
}
