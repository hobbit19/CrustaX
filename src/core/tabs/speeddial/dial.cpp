#include "dial.h"

Dial::Dial(const QPixmap &pixmap, const QString &title, const QUrl &url):
    m_width(200)
  , m_height(100)
{
    Q_UNUSED(pixmap);
    Q_UNUSED(title);
    Q_UNUSED(url);
    setObjectName("speeddial-dial");

    setFixedSize(m_width, m_height);
}
