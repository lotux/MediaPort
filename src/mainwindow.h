#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "playlist.h"
#include "vlcplayer.h"
#include "webview.h"
#include "ui_mainwindow.h"
#include "settings.h"
#include "overlay.h"
#include <QtGui>
#include "webapi.h"
#include "stackview.h"
#include "overlaycontrol.h"
//#include <QtDeclarative/QDeclarativeView>
#include <QLabel>
#include "ui_overlaycontrol.h"
#include "rlpmanager.h"

class QTimer;
class QStackedWidget;
class QStackedLayout;
//class PictureBrowser;

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    Ui::MainWindow ui;

public:
    MainWindow();
    QSlider *positionSlider;
    QSlider *volumeSlider;
    PlayList *playList;
    QLabel   *videoWidget;
    QFrame   *frameWidget;
    Overlay  *overlayWidget;
    StackView *stackView;
    WebView *mainWebView;
    QToolBar *searchBar(){ return ui.searchBar; }

    //QDeclarativeView *dynamicView;
    VLCPlayer *vlcPlayer;
    QString currentMrl;
    QString fromBase64(QString base64);
    WebAPI *webAPI;
    RlpManager *m_rlp;


signals:
private:
    //QToolBar *m_searchBar; NOT USED
    QMovie *movie;
    //PictureBrowser *pictureView;
    QLineEdit *searchBox;

    QAction *prevButton;
    QAction *nextButton;
    QAction *searchButton;
    OverlayControl *m_overlayControl;

    QAction *m_playerPlay;
    QAction *m_playerForward;
    QAction *m_playerRewind;
    void createToolBar();
    void createMainWidgets();
    void aboutApplication();
    void loadStyleSheet();
    Settings settings;
    QTimer *m_p2pTimer;

public slots:    
    void showAds();
    void playdummy();
    void stopAds();
    void updatePlayList();
    void updateInterface();
    void playSelectedUrl(QUrl url);
    void searchMedia();
    void prevStackView();
    void nextStackView();
    void togglePlay();
    void toggleToVideo(int);
    void toggleFullscreen();
    void playerForward();
    void playerRewind();
    void playMedia(QString mrl);
    void showOverlay(int currentIndex);
    void updateLogoPosition();
    void startP2pPlay();






private slots:
    void on_actionCheck_for_update_triggered();
    void on_actionPause_triggered();
    void on_actionPrevious_triggered();
    void on_actionNext_triggered();
    void on_actionPlay_triggered();
    void on_actionLogout_triggered();
    void on_actionExit_triggered();
    void on_actionPaste_triggered();
    void on_actionCut_triggered();
    void on_actionAbout_Farsima_triggered();
    void playP2p();

protected:
    void keyPressEvent(QKeyEvent *event);
    void resizeEvent(QResizeEvent *event);
};

#endif // MAINWINDOW_H
