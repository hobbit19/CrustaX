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

#include "browserwindow.h"

#include <QApplication>
#include <QDebug>
#include <QFile>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Q_INIT_RESOURCE(resource);

    QCoreApplication::setOrganizationName("Crusta");
    QCoreApplication::setOrganizationDomain("crustabrowser.com");
    QCoreApplication::setApplicationName("Crusta X");

//    //TODO: load translations based on locale and preference
//    QTranslator translator;
//    // TODO: set translation path correctly
//    translator.load("../translations/crusta_ru");
//    a.installTranslator(&translator);

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("crusta");
    db.setDatabaseName("crustadb");
    db.setUserName("crusta");
    db.setPassword("root");

    if (db.open()) {
        QSqlQuery query;
//        query.exec("DROP TABLE HISTORY");
        query.exec("CREATE TABLE IF NOT EXISTS HISTORY (FAVICON BLOB, TITLE TEXT, URL TEXT, TIME TEXT, LOADTIME INTEGER, COUNT INTEGER DEFAULT 0)");
    } else {
        // TODO: Handle this case in other files too
        qWarning() << "Could not connect to database";
    }

    BrowserWindow w;
    QFile file("../themes/default.css");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());
    qApp->setStyleSheet(styleSheet);
    w.showMaximized();
    return a.exec();
}
