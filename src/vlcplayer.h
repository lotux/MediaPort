/* libVLC and Qt sample code
 * Copyright © 2009 Alexander Maringer <maringer@maringer-it.de>
 */
#ifndef VLC_ON_QT_H
#define VLC_ON_QT_H

#include <vlc/vlc.h>
#include <vlc/libvlc_media_player.h>

#include <QWidget>
#include <QStackedWidget>
#include <QtWebKit/QWebView>
#include <QListWidget>

#include "playlist.h"
#include "settings.h"

class QVBoxLayout;
class QPushButton;
class QTimer;
class QFrame;
class QSlider;
class QListWidgetItem;

#define POSITION_RESOLUTION 10000

class VLCPlayer : public QObject
{
    Q_OBJECT
    QTimer *poller;
    //libvlc_exception_t vlcexcep;
    libvlc_instance_t *vlcinstance;
    libvlc_media_player_t *mp;
    libvlc_media_t *m;

public:
    VLCPlayer(QWidget *parent = 0);
    ~VLCPlayer();
    //void raise(libvlc_exception_t * ex);
    QFrame *videoWidget;
    bool isPlaying();
    int mediaPosition;
    int volumePosition;
    void setWindowID(WId windowID);
    QString getStateName();
    int getState();
    void toggleFullscreen(int toggle);
    bool isFullscreen();
    QString currentMrl;
    QSize videoSize(QSize m_widgetSize);
    QSize getActualScale(QSize m_widgetSize,QSize m_videoSize);

private:
    WId windowID;
    Settings settings;

public slots:
    int playFile(QString file);
    void pause(int doPasue);
    void stop();
    void updateInterface();
    void changeVolume(int newVolume);
    void changePosition(int newPosition);
};
#endif
