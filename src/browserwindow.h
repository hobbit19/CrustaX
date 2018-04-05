#ifndef BROWSERWINDOW_H
#define BROWSERWINDOW_H

#include <QMainWindow>

class BrowserWindow : public QMainWindow
{
    Q_OBJECT

public:
    BrowserWindow(QWidget *parent = 0);
    ~BrowserWindow();
};

#endif // BROWSERWINDOW_H
