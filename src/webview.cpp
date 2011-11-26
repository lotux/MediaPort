#include "webview.h"
#include <QWebFrame>
//#ifdef DEBUG
#include <QDebug>
//#endif
#include <QWebSettings>
#include <QCoreApplication>
#include <QMenu>
#include <QWebHitTestResult>
#include <QContextMenuEvent>
#include <QSettings>

WebView::WebView(QWidget *parent) :
    QWebView(parent)
    , m_page(new WebPage(this))
{
    setPage(m_page);
    page()->setLinkDelegationPolicy(QWebPage::DelegateAllLinks);
    connect( m_page->mainFrame() , SIGNAL(javaScriptWindowObjectCleared()), this, SLOT(attachObject()) );

    connect(this,SIGNAL(loadFinished(bool)),this,SLOT(loadFinished(bool)));
    connect(this,SIGNAL(selectionChanged()),this,SLOT(doNothing()));
    connect(this,SIGNAL(urlChanged(QUrl)),this,SLOT(urlChanged(QUrl)));
    enableSettings();
    attachObject();
    //setContextMenuPolicy(Qt::PreventContextMenu);
}

WebPage * WebView::page(){
    return m_page;
}
void WebView::urlChanged(const QUrl url){
    qDebug() << "URL IS" << url;
}
void WebView::loadFinished(bool ok){
        //setObject(externalObj);
}

void WebView::setObject(QString objString)
{

    QVariant ret = m_page->mainFrame()->evaluateJavaScript("searchCurrentDataTable('"+objString+"');");

}
void WebView::attachObject(){
    m_page->mainFrame()->addToJavaScriptWindowObject(QLatin1String("webview"),this);
}
void WebView::doPlay(){
    emit startPlay();
}
void WebView::enableSettings()
{
     QWebSettings::globalSettings()->setAttribute(QWebSettings::DeveloperExtrasEnabled, false);
     QWebSettings::globalSettings()->setAttribute(QWebSettings::PluginsEnabled, true);
     QWebSettings::globalSettings()->setAttribute(QWebSettings::JavascriptEnabled, true);
     QWebSettings::globalSettings()->setAttribute(QWebSettings::OfflineStorageDatabaseEnabled, true);
     QWebSettings::globalSettings()->setAttribute(QWebSettings::OfflineWebApplicationCacheEnabled, true);
     QWebSettings::globalSettings()->setAttribute(QWebSettings::LocalStorageDatabaseEnabled, true);
     QWebSettings::globalSettings()->setOfflineWebApplicationCachePath(  QCoreApplication::applicationDirPath() + QString("/webappCache/") );
     QWebSettings::globalSettings()->setLocalStoragePath( QCoreApplication::applicationDirPath() + QString("/localStore/"));
     QWebSettings::globalSettings()->setOfflineStoragePath(QCoreApplication::applicationDirPath() + QString("/dbcache/"));

}

void WebView::contextMenuEvent(QContextMenuEvent* event)
{
        QSettings settings;
        return;
        if(settings.value("disableDebug").toBool()){
            return;
        }

        QMenu* menu = m_page->createStandardContextMenu();

        QWebHitTestResult r = page()->mainFrame()->hitTestContent(event->pos());

        if (!r.linkUrl().isEmpty()) {
            QAction* newTabAction = menu->addAction(tr("Test Menu"));
            newTabAction->setData(r.linkUrl());
            menu->insertAction(menu->actions().at(2), newTabAction);
        }
        for(int i=0; i< menu->actions().size();i++){
            QAction *qa = menu->actions().at(i);
        }

        menu->exec(mapToGlobal(event->pos()));
        delete menu;
}
void WebView::doNothing(){
    this->focusPreviousChild();
}
