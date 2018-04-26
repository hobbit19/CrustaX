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

#include "navigationbar.h"

#include <QDebug>
#include <QMenu>
#include <QSettings>

#define NAVIGATIONBAR_HEIGHT 30

NavigationBar::NavigationBar(QWidget *parent):
    QWidget(parent)
  , m_height(NAVIGATIONBAR_HEIGHT)
  , m_millis(-1)
{
    setObjectName("navigation-navigationbar");

    m_hboxlayout = new QHBoxLayout;
    m_backbutton = new ActionButton;
    m_forwardbutton = new ActionButton;
    m_topbutton = new ActionButton;
    m_reloadstopbutton = new ActionButton;
    m_homebutton = new ActionButton;
    m_timerbutton = new QLabel;
    m_addressbar = new AddressBar;

    m_backbutton->setSide(NAVIGATIONBAR_HEIGHT - 4);
    m_backbutton->setFillIcon(QIcon::fromTheme("go-previous"));
    m_backbutton->setToolTip(tr("Back"));

    m_forwardbutton->setSide(NAVIGATIONBAR_HEIGHT - 4);
    m_forwardbutton->setFillIcon(QIcon::fromTheme("go-next"));
    m_forwardbutton->setToolTip(tr("Forward"));

    m_topbutton->setSide(NAVIGATIONBAR_HEIGHT - 4);
    m_topbutton->setFillIcon(QIcon::fromTheme("go-up"));
    m_topbutton->setToolTip(tr("Top"));

    m_reloadstopbutton->setSide(NAVIGATIONBAR_HEIGHT - 4);
    m_reloadstopbutton->setFillIcon(QIcon::fromTheme("refresh"));

    m_homebutton->setSide(NAVIGATIONBAR_HEIGHT - 4);
    m_homebutton->setFillIcon(QIcon::fromTheme("go-home"));
    m_homebutton->setToolTip(tr("Home"));
    m_timerbutton->setToolTip(tr("Page load time"));

    m_hboxlayout->setContentsMargins(2,2,2,2);
    m_hboxlayout->setSpacing(0);

    createLayout();

    setLayout(m_hboxlayout);
    restoreState();

    setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this, &NavigationBar::customContextMenuRequested, this, &NavigationBar::showContextMenu);
    connect(m_addressbar, &AddressBar::handleInternalScheme, this, &NavigationBar::redirectInternalSchemeHandler);
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
    m_hboxlayout->addWidget(m_homebutton);
    m_hboxlayout->addWidget(m_addressbar);
    m_hboxlayout->addWidget(m_timerbutton);

    QSettings settings;
    settings.beginGroup("navigationbar");
    if (!settings.value("backbutton-visible", true).toBool()) {
        m_backbutton->hide();
    }
    if (!settings.value("forwardbutton-visible", true).toBool()) {
        m_forwardbutton->hide();
    }
    if (!settings.value("topbutton-visible", true).toBool()) {
        m_topbutton->hide();
    }
    if (!settings.value("reloadstopbutton-visible", true).toBool()) {
        m_reloadstopbutton->hide();
    }
    if (!settings.value("homebutton-visible", true).toBool()) {
        m_homebutton->hide();
    }
    if (!settings.value("timerbutton-visible", true).toBool()) {
        m_timerbutton->hide();
    }
    settings.endGroup();
}

void NavigationBar::showContextMenu(const QPoint &pos)
{
    QMenu* menu = new QMenu;

    QAction* act_back = menu->addAction(tr("Back"));
    act_back->setCheckable(true);
    if (m_backbutton->isVisible()) {
        act_back->setChecked(true);
    }
    connect(act_back, &QAction::toggled, [=](bool checked){
        QSettings settings;
        settings.beginGroup("navigationbar");
        settings.setValue("backbutton-visible", checked);
        m_backbutton->setVisible(checked);
        settings.endGroup();
    });

    QAction* act_forward = menu->addAction(tr("Forward"));
    act_forward->setCheckable(true);
    if (m_forwardbutton->isVisible()) {
        act_forward->setChecked(true);
    }
    connect(act_forward, &QAction::toggled, [=](bool checked){
        QSettings settings;
        settings.beginGroup("navigationbar");
        settings.setValue("forwardbutton-visible", checked);
        m_forwardbutton->setVisible(checked);
        settings.endGroup();
    });

    QAction* act_top = menu->addAction(tr("Top"));
    act_top->setCheckable(true);
    if (m_topbutton->isVisible()) {
        act_top->setChecked(true);
    }
    connect(act_top, &QAction::toggled, [=](bool checked){
        QSettings settings;
        settings.beginGroup("navigationbar");
        settings.setValue("topbutton-visible", checked);
        m_topbutton->setVisible(checked);
        settings.endGroup();
    });

    QAction* act_reload = menu->addAction(tr("Reload-Stop"));
    act_reload->setCheckable(true);
    if (m_reloadstopbutton->isVisible()) {
        act_reload->setChecked(true);
    }
    connect(act_reload, &QAction::toggled, [=](bool checked){
        QSettings settings;
        settings.beginGroup("navigationbar");
        settings.setValue("reloadstopbutton-visible", checked);
        m_reloadstopbutton->setVisible(checked);
        settings.endGroup();
    });

    QAction* act_home = menu->addAction(tr("Home"));
    act_home->setCheckable(true);
    if (m_homebutton->isVisible()) {
        act_home->setChecked(true);
    }
    connect(act_home, &QAction::toggled, [=](bool checked){
        QSettings settings;
        settings.beginGroup("navigationbar");
        settings.setValue("homebutton-visible", checked);
        m_homebutton->setVisible(checked);
        settings.endGroup();
    });

    QAction* act_timer = menu->addAction(tr("Timer"));
    act_timer->setCheckable(true);
    if (m_timerbutton->isVisible()) {
        act_timer->setChecked(true);
    }
    connect(act_timer, &QAction::toggled, [=](bool checked){
        QSettings settings;
        settings.beginGroup("navigationbar");
        settings.setValue("timerbutton-visible", checked);
        m_timerbutton->setVisible(checked);
        settings.endGroup();
    });

    menu->exec(mapToGlobal(pos));
}

void NavigationBar::loadStarted()
{
    m_reloadstopbutton->setFillIcon(QIcon::fromTheme("process-stop"));
    m_startmillis = QTime::currentTime();
}

void NavigationBar::loadFinished()
{
    m_reloadstopbutton->setFillIcon(QIcon::fromTheme("view-refresh"));
    m_millis = m_startmillis.msecsTo(QTime::currentTime());
    m_timerbutton->setText(QString::number((m_millis/100)/10.0) + "s");
}

void NavigationBar::loadProgress(const int &progress)
{
    Q_UNUSED(progress);
}

ActionButton* NavigationBar::backButton()
{
    return m_backbutton;
}

ActionButton* NavigationBar::forwardButton()
{
    return m_forwardbutton;
}

ActionButton* NavigationBar::topButton()
{
    return m_topbutton;
}

ActionButton* NavigationBar::reloadStopButton()
{
    return m_reloadstopbutton;
}

ActionButton* NavigationBar::homeButton()
{
    return m_homebutton;
}

int NavigationBar::loadTime()
{
    return m_millis;
}

void NavigationBar::setAddress(QUrl address)
{
    m_addressbar->setAddress(address);
}

void NavigationBar::redirectInternalSchemeHandler(QUrl address)
{
    emit handleInternalScheme(address);
}
