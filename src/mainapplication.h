#ifndef MAINAPPLICATION_H
#define MAINAPPLICATION_H

#include "singleapplication.h"
#include "mainwindow.h"
#include "loginwindow.h"
#include "constants.h"

class QLocalSocket;
class MainApplication : public SingleApplication
{
   Q_OBJECT

public:
    MainApplication(int &argc, char **argv);
    MainWindow *m_mainWindow;
    MainWindow *mainWindow();
    MainApplication *instance();
    LoginWindow *login;
    QString m_appUser;
    QString user(){ return m_appUser; }

public slots:
    void doLogout();


private:
    QTimer *eventTimer;

private slots:
    void showMainWindow();
    void showLoginWindow();
    void processEvent();
    void setAppUser();
    void killAndQuit();


};

#endif // MAINAPPLICATION_H
