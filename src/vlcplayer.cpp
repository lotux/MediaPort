/* libVLC and Qt sample code
 * Copyright © 2009 Alexander Maringer <maringer@maringer-it.de>
 */
#include "vlcplayer.h"
#include <QCoreApplication>
#include <QTimer>
#ifdef DEBUG
//#include <QDebug>
#endif

//"--extraintf=logger", //log anything
//"--verbose=2", //be much more verbose then normal for debugging purpose
VLCPlayer::VLCPlayer(QWidget *parent)
: QObject()
{
    //preparation of the vlc command
    QString pluginDir =  QString("--plugin-path=") + QCoreApplication::applicationDirPath() + QString("/plugins/");


    const char * const vlc_args[] = {
              "-I", "dummy", /* Don't use any interface */
              //"--sub-filter=logo{file=c:\\mediaport.png}:rss{urls=http://www.bbc.co.uk/persian/index.xml,length=120,size=23,title=0,speed=300000,x=-10,y=-30,position=8}",
              //"--sub-filter=logo{file=dummy}",
              //"--no-rss-images",
              "--verbose", "0",
              //"--verbose-objects=+filter",
              //"-vvv",
              //"--sout=#duplicate{dst=std{access=mmsh,mux=asfh,dst=0.0.0.0:8080},dst=display}",
              "--ignore-config",
              //"--loop",
              //"--repeat",
              //"-R",
              "--no-video-title-show",
              //"--network-caching 20000",
              //":mmsh-caching=20000",
              pluginDir.toAscii()
              };
    int vlc_argc = sizeof(vlc_args) / sizeof(*vlc_args);

    poller=new QTimer(this);

    //Initialize an instance of vlc
    //a structure for the exception is neede for this initalization
    //libvlc_exception_init(&vlcexcep);

    //create a new libvlc instance
    vlcinstance=libvlc_new(vlc_argc, vlc_args);  //tricky calculation of the char space used
    //raise (&vlcexcep);


    // Create a media player playing environement 
    mp = libvlc_media_player_new (vlcinstance);
    //qDebug() << "error:"<< libvlc_errmsg;
    //raise (&vlcexcep);

//    libvlc_video_set_logo_string(mp,libvlc_logo_file,"http://www.google.ca/intl/en_com/images/srpr/logo1w.png");
//    libvlc_video_set_logo_int(mp,libvlc_logo_enable,1);
//    libvlc_video_set_logo_int(mp,libvlc_logo_x,10);
//    libvlc_video_set_logo_int(mp,libvlc_logo_y,10);
//    libvlc_video_set_logo_int(mp,libvlc_logo_opacity,255);
//    libvlc_video_set_logo_int(mp,libvlc_logo_repeat,1000);

    //connect the two sliders to the corresponding slots (uses Qt's signal / slots technology)
    connect(poller, SIGNAL(timeout()), this, SLOT(updateInterface()));
    poller->start(100); //start timer to trigger every 100 ms the updateInterface slot
    currentMrl = "";
}

void VLCPlayer::setWindowID(WId wID){
    windowID = wID;
}
VLCPlayer::~VLCPlayer()
{
    /* Stop playing */
    libvlc_media_player_stop (mp);

    /* Free the media_player */
    libvlc_media_player_release (mp);

    libvlc_release (vlcinstance);
    //raise (&vlcexcep);
}
int VLCPlayer::playFile(QString file)
{
    //the file has to be in one of the following formats /perhaps a little bit outdated)
    /*
    [file://]filename              Plain media file
    http://ip:port/file            HTTP URL
    ftp://ip:port/file             FTP URL
    mms://ip:port/file             MMS URL
    screen://                      Screen capture
    [dvd://][device][@raw_device]  DVD device
    [vcd://][device]               VCD device
    [cdda://][device]              Audio CD device
    udp:[[<source address>]@[<bind address>][:<bind port>]]
    */

    /* Create a new LibVLC media descriptor */
    m = libvlc_media_new_location (vlcinstance, file.toAscii());
    //raise(&vlcexcep);

    if(mp){
        libvlc_media_player_stop(mp);
        libvlc_media_player_release(mp);
    }

    mp = libvlc_media_player_new_from_media (m);
    libvlc_video_set_logo_int(mp,libvlc_logo_enable,1);
    libvlc_video_set_logo_string(mp,libvlc_logo_file,"c:\\mediaport.png");


    //libvlc_media_player_set_media (mp, m);
    //raise(&vlcexcep);

    // /!\ Please note /!\
    //
    // passing the widget to the lib shows vlc at which position it should show up
    // vlc automatically resizes the video to the ´given size of the widget
    // and it even resizes it, if the size changes at the playing

    /* Get our media instance to use our window */
    #if defined(Q_OS_WIN)
        //libvlc_media_player_set_drawable(mp, reinterpret_cast<unsigned int>(windowID));
        libvlc_media_player_set_hwnd (mp, windowID);
        //libvlc_media_player_set_hwnd(_mp, _videoWidget->winId(), &_vlcexcep ); // for vlc 1.0
    #elif defined(Q_OS_MAC)
        //libvlc_media_player_set_drawable(mp, windowID);
         libvlc_media_player_set_nsobject (mp, windowID);
        //libvlc_media_player_set_agl (_mp, _videoWidget->winId(), &_vlcexcep); // for vlc 1.0
    #else //Linux
         libvlc_media_player_set_xdrawable (mp, xdrawable);
        //libvlc_media_player_set_xwindow(_mp, _videoWidget->winId(), &_vlcexcep ); // for vlc 1.0
    #endif
    //raise(&vlcexcep);

    /* Play */
   if (libvlc_media_player_play(mp) == 0)
   {
       currentMrl = file.toAscii();
       return 0;
   }

    //raise(&vlcexcep);
    return -1;
}

void VLCPlayer::changeVolume(int newVolume)
{
    //libvlc_exception_clear(&vlcexcep);
    libvlc_audio_set_volume(mp,newVolume);
    //settings.saveVolume(newVolume);
    //raise(&vlcexcep);
}

void VLCPlayer::changePosition(int newPosition)
{
    //libvlc_exception_clear(&vlcexcep);
    // It's possible that the vlc doesn't play anything
    // so check before
    libvlc_media_t *curMedia = libvlc_media_player_get_media (mp);
    //libvlc_exception_clear(&vlcexcep);
    if (curMedia == NULL)
        return;

    float pos=(float)(newPosition)/(float)POSITION_RESOLUTION;
    libvlc_media_player_set_position (mp, pos);
    //raise(&vlcexcep);
}

void VLCPlayer::pause(int doPause)
{
    if(mp)
       libvlc_media_player_set_pause(mp,doPause);
}

void VLCPlayer::stop()
{
    if(mp){
        libvlc_media_player_stop(mp);
        //libvlc_media_player_release(mp);
    }
}

void VLCPlayer::updateInterface()
{
    //if(!isPlaying())
    //    return;

    // It's possible that the vlc doesn't play anything
    // so check before
    libvlc_media_t *curMedia = libvlc_media_player_get_media (mp);
    //libvlc_exception_clear(&vlcexcep);
    if (curMedia == NULL)
        return;

    float pos=libvlc_media_player_get_position (mp);
    mediaPosition=(int)(pos*(float)(POSITION_RESOLUTION));
    volumePosition=libvlc_audio_get_volume(mp);

}

QString VLCPlayer::getStateName()
{
    libvlc_state_t state;
    QString stateString;
    state = libvlc_media_player_get_state(mp);
    switch(state)
    {
        case libvlc_NothingSpecial  :
               stateString = QString("Nothing");
               break;

        case libvlc_Opening:
               stateString = QString("Opening");
               break;

        case libvlc_Buffering:
               stateString = QString("Buffering");
               break;

        case libvlc_Playing :
               stateString = QString("Playing");
               break;

        case libvlc_Paused :
               stateString = QString("Paused");
               break;

        case libvlc_Stopped:
               stateString = QString("Stopped");
               break;

        case libvlc_Ended:
               stateString = QString("Ended");
               break;

        case libvlc_Error:
               stateString = QString("Error");
               break;

    }

 return stateString;
}

int VLCPlayer::getState()
{
    libvlc_state_t state;
    state = libvlc_media_player_get_state(mp);
    return state;
}
/*void VLCPlayer::raise(libvlc_exception_t * ex)
{
    if (libvlc_exception_raised (ex))
    {
         qDebug() << stderr << "error: " << libvlc_exception_get_message(ex);
         exit (-1);
    }
}
*/
bool VLCPlayer::isPlaying(){

    if(libvlc_media_player_get_state(mp) == 3)
       return true;

    return false;
}

void VLCPlayer::toggleFullscreen(int toggle)
{
    libvlc_set_fullscreen(mp,toggle);
}

bool VLCPlayer::isFullscreen()
{
    return libvlc_get_fullscreen(mp);
}

QSize VLCPlayer::videoSize(QSize m_widgetSize)
{
    unsigned int height;
    unsigned int width;

    libvlc_video_get_size(mp,0,&width,&height);

    return getActualScale(m_widgetSize,QSize(width,height));
}

QSize VLCPlayer::getActualScale(QSize m_widgetSize,QSize m_videoSize)
{
    int width;
    int height;
    width = m_videoSize.width();
    height = m_videoSize.height();

    double mdst = m_widgetSize.height() / m_widgetSize.width();
    double msrc = m_videoSize.height() / m_videoSize.width();

    if(  m_widgetSize.height() > m_videoSize.height() &&
         m_widgetSize.width() > m_videoSize.width())
      {
         for (int i;  height < m_widgetSize.height() &&
                      width  < m_widgetSize.width(); i++ )
         {
              height++;
              width++;
              msrc = height/width;
         }
      }
    else{

        width = 1 * msrc;
        height = 1;

        for (int i;  height < m_widgetSize.height() &&
                     width  < m_widgetSize.width(); i++ )
        {
             height++;
             width++;
             msrc = height/width;
         }
    }
    return QSize(width,height);
}
