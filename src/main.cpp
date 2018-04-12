#include "browserwindow.h"

#include <QApplication>
#include <QFile>
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

    BrowserWindow w;
    QFile file("../themes/default.css");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());
    qApp->setStyleSheet(styleSheet);
    w.showMaximized();
    return a.exec();
}
