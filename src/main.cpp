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
        query.exec("CREATE TABLE HISTORY (TITLE TEXT, URL TEXT, TIME TEXT, LOADTIME INTEGER);");
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
