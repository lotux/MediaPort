#include "mainapplication.h"
#include <QCoreApplication>
#include <qdesktopservices.h>
#include <qdir.h>
#include <qevent.h>
#include <qlibraryinfo.h>
#include <qlocalsocket.h>
#include <qmessagebox.h>
#include <qsettings.h>
#include <qwebsettings.h>
#include <QDesktopWidget>
#include "loginwindow.h"
#include "usbmonitor.h"
#include <QDebug>

MainApplication::MainApplication(int &argc, char **argv)
        : SingleApplication(argc, argv)
{    
    QCoreApplication::setOrganizationDomain(Constants::DOMAIN_NAME);
    QCoreApplication::setApplicationName(Constants::APP_NAME);
    QCoreApplication::setApplicationVersion(Constants::VERSION);



    setWindowIcon(QIcon(QLatin1String(":icons/mediaport/mediaport_icon.png")));

    m_mainWindow = new MainWindow();
    //connect(m_mainWindow->mainWebView,SIGNAL(loadFinished(bool)),
    //        this,SLOT(showLoginWindow()));
    //mainWindow->setWindowState(Qt::WindowMaximized);
    //m_mainWindow->hide();

    m_mainWindow->setWindowTitle("Farsima");

    //mainWindow->setMinimumHeight(768);
    //cheap and deep hack to make vlcplayer work for now
    m_mainWindow->vlcPlayer->setWindowID(m_mainWindow->videoWidget->winId());

    m_mainWindow->showMaximized();

    login = new LoginWindow();
    //connect(login,SIGNAL(accepted()),this,SLOT(setAppUser()));
    //login->show();

    connect(login,SIGNAL(accepted()),this,SLOT(showMainWindow()));
    connect(this,SIGNAL(aboutToQuit()),this,SLOT(killAndQuit()));

    eventTimer = new QTimer(this);
    connect(eventTimer, SIGNAL(timeout()), this, SLOT(processEvent()));
    eventTimer->start(1000);

}
void MainApplication::killAndQuit(){
     RlpManager *rlp = new RlpManager();
     rlp->stop();
     quit();
}
void MainApplication::processEvent(){
    processEvents();
    USBMonitor usbmon;
    QSettings m_setting;
    QString key = m_setting.value("key").toString();
    if(key.isEmpty())
        key = QString("9B2001103010005466");
    if(!usbmon.is_usbkey_plugged(key)){
           //QMessageBox msgBox;
           //msgBox.setText("Please Insert Farsima USB Key");
           //msgBox.exec();
           qDebug()<< "Exiting....";
           //exit();
    }
}

void MainApplication::showMainWindow(){
    m_mainWindow->showMaximized();
    //QTimer::singleShot(30,this,checkForUpdate());
}

void MainApplication::showLoginWindow()
{
   if (m_mainWindow->isHidden())
       login->exec();
}

MainWindow *MainApplication::mainWindow()
{
    MainWindow *activeWindow = 0;

    if (m_mainWindow) {
        activeWindow = m_mainWindow;
    } else {
        activeWindow = qobject_cast<MainWindow*>(QApplication::activeWindow());
        if (!activeWindow)
            activeWindow = m_mainWindow;
    }

    return activeWindow;
}

MainApplication *MainApplication::instance()
{
    return (static_cast<MainApplication*>(QCoreApplication::instance()));
}

void MainApplication::setAppUser()
{
     m_appUser = login->username;
}

void MainApplication::doLogout()
{

   QSettings settings;

   m_mainWindow->hide();
   settings.remove("username");
   settings.remove("password");
   settings.setValue("saveAccount",0);
   login->show();

}
