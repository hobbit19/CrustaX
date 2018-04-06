#ifndef CDIAL_H
#define CDIAL_H

#include <QWidget>

class Dial : public QWidget
{
    int m_width;
    int m_height;
public:
    Dial(const QPixmap &pixmap, const QString &title, const QUrl &url);
};

#endif // CDIAL_H
