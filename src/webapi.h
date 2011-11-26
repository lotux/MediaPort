#ifndef WEBAPI_H
#define WEBAPI_H

#include <QObject>
#include "vlcplayer.h"
#include <QCoreApplication>

class WebView;
class QWebFrame;
class VLCPlayer;

class WebAPI : public QObject
{
    Q_OBJECT
public:
    explicit WebAPI(VLCPlayer *p,QObject *parent = 0);
    void setWebView( WebView *view );
    int currentView;



signals:
    void tick(int, int);
    void stateChange(QString);
    void buffering(int);
    void volumeChanged(int);
    void showVideo(int);


public slots:
    void togglePause();
    void setVolume(int);
    void play(QString);
    void stop();
    void pause();
    void resume();
    QString getCurrentMrl();
    int getCurrentView();
    void setCurrentView(int currentIndex);
    QString version();
    QString appName();
    void appExit();
    QString appUser();
    void logout();
    void checkUpdate();

private slots:
    void attachObject();


private:
    QWebFrame *frame;
    VLCPlayer *player;


};

#endif // WEBAPI_H
