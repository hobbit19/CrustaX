#ifndef CBROWSERWINDOW_H
#define CBROWSERWINDOW_H

#include <QMainWindow>

class BrowserWindow : public QMainWindow
{
    Q_OBJECT

public:
    BrowserWindow(QWidget *parent = 0);
    ~BrowserWindow();
};

#endif // CBROWSERWINDOW_H
