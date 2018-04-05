#include "browserwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Q_INIT_RESOURCE(resource);
    BrowserWindow w;
    w.showMaximized();

    return a.exec();
}
