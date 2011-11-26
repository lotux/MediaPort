#ifndef WEBVIEW_H
#define WEBVIEW_H

#include <QWebView>
#include "webpage.h"

class WebView : public QWebView
{
    Q_OBJECT
public:
    explicit WebView(QWidget *parent = 0);
    void setObject(QString objString);
    QString externalObj;
    void doPlay();
    void enableSettings();
    WebPage* page();
protected:
     virtual void contextMenuEvent(QContextMenuEvent* event);

//private:
         WebPage *m_page;

signals:
    void startPlay();

public slots:
     void loadFinished(bool ok);
     void attachObject();
     void doNothing();
     void urlChanged(const QUrl url);

};

#endif // WEBVIEW_H
