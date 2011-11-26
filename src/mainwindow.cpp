#include "mainwindow.h"
//#include <QVBoxLayout>
#define DEBUG 1
#include <QPushButton>
#include <QToolBar>
#include <QSlider>
#include <QTimer>
#include <QFrame>
#ifdef DEBUG
//#include <QDebug>
#endif
#include <QListWidget>
#include <QStringListModel>
#include <QLineEdit>
#include <QSpacerItem>
#include <QtWebKit/QWebView>
#include <QStackedWidget>
#include <QDockWidget>
#include <QAction>
#include <QtGui>
#include <picturebrowser.h>
#include <QWebFrame>
#include "aboutdialog.h"
#include "rlpmanager.h"
#include "usbmonitor.h"

MainWindow::MainWindow()
{
    playList = new PlayList();
    setAttribute(Qt::WA_TranslucentBackground, true);

    ui.setupUi(this);

    stackView = new StackView;
    loadStyleSheet();
    setCentralWidget(stackView);
    createToolBar();
    createMainWidgets();


    connect(positionSlider, SIGNAL(sliderMoved(int)), vlcPlayer, SLOT(changePosition(int)));
    connect(volumeSlider, SIGNAL(sliderMoved(int)), vlcPlayer, SLOT(changeVolume(int)));
    connect(volumeSlider,SIGNAL(valueChanged(int)),vlcPlayer,SLOT(changeVolume(int)));
    connect(positionSlider, SIGNAL(valueChanged(int)), vlcPlayer, SLOT(changePosition(int)));
    connect(stackView,SIGNAL(toggleFullscreen()),this,SLOT(toggleFullscreen()));

    playList->updatePlayList(QString(""));
    connect(playList,SIGNAL(playListReady()),this,SLOT(updatePlayList()));

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateInterface()));
    timer->start(500);
    //QTimer::singleShot(1000,this,SLOT(playdummy()));

}
void MainWindow::playdummy()
{
    playMedia("mmsh://uaebox.dyndns.org:8070");
}
void MainWindow::aboutApplication(){}

void MainWindow::createToolBar()
{

    ui.searchBar->setFloatable(false);
    ui.searchBar->setMovable(false);
    ui.searchBar->setAllowedAreas(Qt::TopToolBarArea);
    prevButton = new QAction(0);
    prevButton->setIcon(QIcon(":/icons/mediaport/next.png"));
    nextButton = new QAction(0);
    nextButton->setIcon(QIcon(":/icons/mediaport/prev.png"));

    connect(prevButton, SIGNAL(triggered()),
            this, SLOT(prevStackView()));
    connect(nextButton, SIGNAL(triggered()),
            this, SLOT(nextStackView()));

    searchButton = new QAction(0);
    searchButton->setIcon(QIcon(":/icons/mediaport/search.png"));

    ui.searchBar->addAction(nextButton);
    ui.searchBar->addAction(prevButton);

    connect(searchButton,SIGNAL(triggered()),
            this,SLOT(searchMedia()));

    searchBox = new QLineEdit;
    searchBox->setMaximumWidth(250);
    searchBox->setMinimumWidth(250);

    connect(searchBox,SIGNAL(returnPressed()),
            this,SLOT(searchMedia()));

    ui.searchBar->addWidget(searchBox);
    ui.searchBar->addAction(searchButton);

    volumeSlider = new QSlider(Qt::Horizontal,this);
    volumeSlider->setMaximum(100); //the volume is between 0 and 100
    volumeSlider->setToolTip("Audio slider");
    volumeSlider->setMaximumWidth(80);
    volumeSlider->setValue(settings.getVolume());

    // Note: if you use streaming, there is no ability to use the position slider
    positionSlider = new QSlider(Qt::Horizontal,this);
    positionSlider->setMaximum(POSITION_RESOLUTION);
    positionSlider->setMaximumWidth(400);

    m_playerRewind = new QAction(this);
    m_playerRewind->setIcon(QIcon(":/icons/mediaport/backward.png"));

    m_playerPlay = new QAction(this);
    m_playerPlay->setIcon(QIcon(":/icons/mediaport/play.png"));


    m_playerForward = new QAction(this);
    m_playerForward->setIcon(QIcon(":/icons/mediaport/forward.png"));

    QAction *m_volumeIcon = new QAction(this);
    m_volumeIcon->setIcon(QIcon(":/icons/mediaport/loud.png"));
    m_volumeIcon->setDisabled(true);

    QAction *m_fullscreen = new QAction(this);
    m_fullscreen->setIcon(QIcon(":/icons/mediaport/fullscreen.png"));
    m_fullscreen->setShortcut(QKeySequence("F11"));


    connect(m_playerPlay, SIGNAL(triggered()),
            this, SLOT(togglePlay()));

    connect(m_playerForward, SIGNAL(triggered()),
            this, SLOT(playerForward()));

    connect(m_playerRewind, SIGNAL(triggered()),
            this, SLOT(playerRewind()));

    connect(m_fullscreen, SIGNAL(triggered()),
            this, SLOT(toggleFullscreen()));

    QWidget* spacer = new QWidget();
    spacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    // toolBar is a pointer to an existing toolbar
    ui.searchBar->addWidget(spacer);

    ui.searchBar->addAction(m_playerRewind);
    ui.searchBar->addAction(m_playerPlay);
    ui.searchBar->addAction(m_playerForward);
    ui.searchBar->addWidget(positionSlider);
    ui.searchBar->addSeparator();
    ui.searchBar->addWidget(volumeSlider);
    ui.searchBar->addAction(m_volumeIcon);
    ui.searchBar->addAction(m_fullscreen);
    ui.searchBar->setMinimumHeight(38);

}

void MainWindow::createMainWidgets()
{
    vlcPlayer   = new VLCPlayer(this);

    videoWidget = new QLabel(stackView);
    //overlayWidget = new Overlay(this);
    //overlayWidget->setGeometry(x()+300,y()+65,width(),height()+25);
    //overlayWidget->hide();


    movie = new QMovie(":icons/mediaport/loading.gif");
    videoWidget->setStyleSheet("background-color:transparent;color:white;font: bold 14px;");
    videoWidget->setAlignment(Qt::AlignCenter);

    mainWebView = new WebView(this);
    connect(mainWebView->page(),SIGNAL(linkClicked(QUrl)),
            this,SLOT(playSelectedUrl(QUrl)));
    mainWebView->setUrl(QUrl("http://www.mediaport.com/app/main.html"));



    stackView->addWidget(videoWidget);
    stackView->addWidget(mainWebView);
    stackView->setCurrentWidget(mainWebView);


    webAPI = new WebAPI(vlcPlayer,this);
    webAPI->setWebView(mainWebView);

    connect(webAPI,SIGNAL(showVideo(int)),this,SLOT(toggleToVideo(int)));
    connect(stackView,SIGNAL(currentChanged(int)),webAPI,SLOT(setCurrentView(int)));
    //connect(stackView,SIGNAL(currentChanged(int)),this,SLOT(showOverlay(int)));
    //overlayWidget->hide();


}
void MainWindow::searchMedia()
{
    //playList->updatePlayList(searchBox->text());
    mainWebView->setObject(searchBox->text());
}
void MainWindow::showAds()
{
}
void MainWindow::stopAds()
{
}
void MainWindow::updatePlayList()
{
    mainWebView->externalObj = playList->getPlayList();
    if(this->isVisible())
        mainWebView->setObject(playList->getPlayList());
}

void MainWindow::startP2pPlay(){
    QSettings m_setting;
    QString cmd_value = m_setting.value("cmd").toString();
    QUrl cmd_url = QUrl(cmd_value);
    //qDebug() <<  "PORT " << cmd_url.port();
    if (!cmd_url.isEmpty()) {
      m_rlp->mrl = QString("http://127.0.0.1:%1/Rlp/%2").arg(cmd_url.port()).arg(m_rlp->fileID);
    }else{
      m_rlp->mrl = QString("http://127.0.0.1/Rlp/%1").arg(m_rlp->fileID);
    }
    //qDebug() <<  "MRL " << m_rlp->mrl;
    if(!vlcPlayer->isPlaying() &&
        vlcPlayer->currentMrl != m_rlp->mrl ){
        playMedia(m_rlp->mrl);
    }
}

void MainWindow::playP2p()
{
    m_p2pTimer = new QTimer(this);
    connect(m_p2pTimer,SIGNAL(timeout()),this,SLOT(startP2pPlay()));
    m_p2pTimer->start(5000);
}
void MainWindow::playSelectedUrl(QUrl url)
{    
    qDebug()<< "URL IS " << url;
    if(!url.encodedQuery().isEmpty())
    {
        qDebug()<< "Playing "<<url.toString();
        QString fileID = url.encodedQuery();
        m_rlp = new RlpManager(this);
        connect(m_rlp, SIGNAL(rlpExecuted()),this,SLOT(playP2p()));
        m_rlp->stop();
        vlcPlayer->stop();
        m_rlp->play(fileID);
        return;
    }
    if(url.scheme().contains("play"))
    {
        playMedia(url.toString().replace("play",""));

    }
    else if(url.host().contains("update.mediaport.com"))
    {
       QDesktopServices::openUrl(url);
    }
    else if(!url.host().contains("mediaport.com") &&
             url.scheme().contains("http"))
    {
      QDesktopServices::openUrl(url);
    }
}

void MainWindow::showOverlay(int currentIndex )
{
    if ( currentIndex == 0 )
    {        
        overlayWidget->show();
    }
    if ( currentIndex == 1 )
        overlayWidget->hide();
}
void MainWindow::nextStackView()
{
    if (stackView->currentIndex() < stackView->count())
        stackView->setCurrentIndex(stackView->currentIndex()+1);
    if (stackView->currentIndex() > stackView->count())
        stackView->setCurrentIndex(stackView->currentIndex()-1);
}

void MainWindow::prevStackView()
{
    if (stackView->currentIndex() < stackView->count())
        stackView->setCurrentIndex(stackView->currentIndex()-1);
    if (stackView->currentIndex() > stackView->count())
        stackView->setCurrentIndex(stackView->currentIndex()+1);

}

QString MainWindow::fromBase64(QString base64){
    QByteArray temp = QByteArray();
    temp.append(base64.toAscii());
    temp = QByteArray::fromBase64(temp);
    return(QString(QLatin1String(temp)));
}

void MainWindow::loadStyleSheet()
 {
     QFile file(":qss/app.qss");
     file.open(QFile::ReadOnly);
     QString styleSheet = QLatin1String(file.readAll());
     setStyleSheet(styleSheet);
 }

void MainWindow::updateInterface(){

    if (!isVisible())
        return;
    int status = vlcPlayer->getState();
    switch (status)
    {
        case 0 : // Nothing
            videoWidget->setText("");
            break;
        case 3 : // Playing
             //overlayWidget->show();
             //overlayWidget->setWindowFlags(Qt::WindowStaysOnTopHint);
             //updateLogoPosition();
             m_playerPlay->setIcon(QIcon(":/icons/mediaport/pause.png"));
             if(m_p2pTimer->isActive()){
                 m_p2pTimer->stop();
                 qDebug() << "Timer Stopped";
             }
             break;
        case 2 : // Buffering

             videoWidget->setText("Buffering");
             videoWidget->setMovie(movie);
             movie->start();
             break;
        case 4 : // Paused
             m_playerPlay->setIcon(QIcon(":/icons/mediaport/play.png"));
             videoWidget->setText("Paused");
             break;
        case 5 : // Stopped
             m_playerPlay->setIcon(QIcon(":/icons/mediaport/play.png"));
             videoWidget->setText("");
             stackView->setCurrentWidget(mainWebView);
             break;
        case 1:  // Opening
             videoWidget->setText("Opening");
             videoWidget->setMovie(movie);
             movie->start();
             break;
        case 7: //Error
             videoWidget->setText("Error in playing Channel");
             break;
        case 6: //Ended
             break;
        default:

            break;
    }
}

void MainWindow::toggleToVideo(int toVideo)
{
    if ( toVideo && stackView->currentWidget() != videoWidget )
        stackView->setCurrentWidget(videoWidget);

    if ( !toVideo && stackView->currentWidget() != mainWebView )
        stackView->setCurrentWidget(mainWebView);
}

void MainWindow::togglePlay()
{
    if (vlcPlayer->isPlaying())
    {
        vlcPlayer->pause(1);
    }else
    {
        vlcPlayer->pause(0);
    }
}
void MainWindow::playerForward()
{
    QString urlString = mainWebView->page()->mainFrame()->evaluateJavaScript("selectNext();").toString();
    //playMedia(urlString);
    playSelectedUrl(QUrl(urlString));
}
void MainWindow::playerRewind()
{
    QString urlString = mainWebView->page()->mainFrame()->evaluateJavaScript("selectPrev();").toString();
    //playMedia(urlString);
    playSelectedUrl(QUrl(urlString));
}

void MainWindow::playMedia(QString mrl)
{
    vlcPlayer->changeVolume(volumeSlider->value());
    if(vlcPlayer->isPlaying())
    {
        vlcPlayer->stop();
    }

    if(mrl.contains("play"))
    {
      mrl.replace("play","");
    }

    vlcPlayer->playFile(mrl);
    toggleToVideo(1);
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {

    case Qt::Key_F11:
        toggleFullscreen();
        event->accept();
        break;

    case Qt::Key_Escape:
        toggleFullscreen();
        event->accept();
        break;

    default:
        QMainWindow::keyPressEvent(event);
        break;
    }
}

void MainWindow::toggleFullscreen()
{
    if (stackView->currentWidget() == mainWebView )
        return; //no fullscreen in webview mode

    if (!vlcPlayer->isPlaying())
        return;

    if (isFullScreen())
    {
       showNormal();
       menuBar()->show();
       statusBar()->show();
       searchBar()->show();
       if (!m_overlayControl->isHidden())
            m_overlayControl->hide();
    }else{

        /*Qt::WindowFlags windowFlags;

        // get active desktop widget ...
        QDesktopWidget *pDesktop    = QApplication::desktop ();
        int             screenNumber     = pDesktop->screenNumber (this);
        QWidget        *activeScreen  = pDesktop->screen (screenNumber);
        QRect           sizeDesktop = pDesktop->screenGeometry (this);

        windowFlags  = Qt::Window |
                       Qt::FramelessWindowHint |
                       Qt::CustomizeWindowHint ;// |
                       //Qt::WindowStaysOnTopHint;
#ifdef Q_OS_LINUX
        windowFlags |= Qt::X11BypassWindowManagerHint;
#endif // Q_OS_LINUX
        //hide();
        stackView->setParent(activeScreen,windowFlags);
        stackView->setGeometry(sizeDesktop);
        stackView->showFullScreen();
        activeScreen->setAttribute(Qt::WA_TranslucentBackground, true);
        overlayWidget->setParent(activeScreen,Qt::Window|Qt::WindowStaysOnTopHint);
        overlayWidget->show();
        setFocusPolicy(Qt::StrongFocus);
        // get the focus ...
        setFocus(Qt::OtherFocusReason);*/
        menuBar()->hide();
        statusBar()->hide();
        searchBar()->hide();
        showFullScreen();
        m_overlayControl = new OverlayControl();
        connect(m_overlayControl->ui->m_playerPlay, SIGNAL(clicked()),
                this, SLOT(togglePlay()));
        connect(m_overlayControl->ui->m_playerForward, SIGNAL(clicked()),
                this, SLOT(playerForward()));
        connect(m_overlayControl->ui->m_playerBackward, SIGNAL(clicked()),
                this, SLOT(playerRewind()));
        connect(m_overlayControl->ui->m_fullscreen, SIGNAL(clicked()),
                this, SLOT(toggleFullscreen()));
        m_overlayControl->show();
        setFocusPolicy(Qt::StrongFocus);
        // get the focus ...
        setFocus(Qt::OtherFocusReason);
    }
}

void MainWindow::on_actionAbout_mediaport_triggered()
{
   AboutDialog *about = new AboutDialog();
   about->show();
}

void MainWindow::on_actionCut_triggered()
{
     this->searchBox->cut();
}

void MainWindow::on_actionPaste_triggered()
{
     this->searchBox->paste();
}

void MainWindow::resizeEvent(QResizeEvent *event)
{

    //updateLogoPosition();
    QMainWindow::resizeEvent(event);
}

void MainWindow::updateLogoPosition()
{
    int widgetWidth = stackView->size().width();
    int videoWidth = vlcPlayer->videoSize(stackView->size()).width();
    int logoPosX;
    int borderSize = abs(widgetWidth/2 - videoWidth/2);
    logoPosX = widgetWidth - borderSize;
    overlayWidget->move( logoPosX - 45, 75);
}

void MainWindow::on_actionExit_triggered()
{
     qApp->quit();
}

void MainWindow::on_actionLogout_triggered()
{
    webAPI->logout();
}

void MainWindow::on_actionPlay_triggered()
{
    webAPI->play(webAPI->getCurrentMrl());
}

void MainWindow::on_actionNext_triggered()
{
     playerForward();
}

void MainWindow::on_actionPrevious_triggered()
{
     playerRewind();
}

void MainWindow::on_actionPause_triggered()
{
     webAPI->pause();
}

void MainWindow::on_actionCheck_for_update_triggered()
{
    webAPI->checkUpdate();
}
