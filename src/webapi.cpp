#include "webapi.h"
//#include <QDebug>
#include "webpage.h"
#include "webview.h"
#include <qwebframe.h>
#include "mainapplication.h"


WebAPI::WebAPI(VLCPlayer *p, QObject *parent) :
    QObject(parent)
{
    player = p;

    /*connect(player, SIGNAL(tick(int,int)),
            this,   SIGNAL(tick(int,int)));
    connect(player, SIGNAL(buffering(int)),
            this,   SIGNAL(buffering(int)));
    connect(player, SIGNAL(volume(int)),
            this,   SIGNAL(volumeChanged(int)));*/
}

void WebAPI::setWebView( WebView *view )
{
    WebPage *page = view->page();
    frame = page->mainFrame();
    attachObject();
    connect( frame, SIGNAL(javaScriptWindowObjectCleared()),
             this,  SLOT(attachObject()) );
}

void WebAPI::attachObject()
{
    frame->addToJavaScriptWindowObject( QString("Farsima"), this );
}

void WebAPI::setVolume(int i)
{
     player->changeVolume(i);
}

void WebAPI::togglePause()
{
    //player->togglePause();
}

QString WebAPI::getCurrentMrl()
{
    return player->currentMrl;
}
int WebAPI::getCurrentView()
{
    return currentView;
}
void WebAPI::play(QString s)
{
    player->playFile(s);
}

void WebAPI::stop()
{
    player->stop();
}

void WebAPI::pause()
{
    player->pause(1);
}

void WebAPI::resume()
{
    player->pause(0);
}

void WebAPI::setCurrentView(int currentIndex)
{
    currentView = currentIndex;
}

QString WebAPI::version()
{
    return qApp->applicationVersion();
}

QString WebAPI::appName()
{
    return qApp->applicationName();
}

void WebAPI::appExit()
{
    qApp->instance()->exit(0);
}

QString WebAPI::appUser()
{
    return (static_cast<MainApplication*>(QCoreApplication::instance()))->user();
}

void WebAPI::logout()
{
    player->stop();
    (static_cast<MainApplication*>(QCoreApplication::instance()))->doLogout();
}

void WebAPI::checkUpdate()
{
    frame->evaluateJavaScript("checkUpdate()");
}
