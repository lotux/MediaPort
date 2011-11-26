#ifndef WEBPAGE_H
#define WEBPAGE_H

#include <QWebPage>

class WebPage : public QWebPage
{
    Q_OBJECT
public:
    WebPage(QObject *parent = 0);
private slots:
    void doNothing();
};

#endif // WEBPAGE_H
