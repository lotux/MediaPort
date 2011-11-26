#include "loginwindow.h"
#include <QDesktopServices>
#include <QUrl>
//#ifdef DEBUG
//#include <QDebug>
//#endif
#include <QtNetwork>
#include <QKeyEvent>
#include "constants.h"

LoginWindow::LoginWindow(QWidget *parent) :
    QDialog(parent)
{
    setAttribute(Qt::WA_TranslucentBackground, true);
    setWindowFlags(Qt::FramelessWindowHint);
    ui.setupUi(this);

    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    //connect(manager, SIGNAL(finished(QNetworkReply*)),
    //         this, SLOT(replyFinished(QNetworkReply*)));
    loginInProgress = false;

    connect(ui.password,SIGNAL(returnPressed()),
            this,SLOT(on_signInButton_clicked()));
    connect(ui.saveAccountCheck,SIGNAL(toggled(bool)),
            this,SLOT(saveAccount(bool)));

    connect(ui.password,SIGNAL(textChanged(QString)),ui.message,SLOT(clear()));
    connect(ui.username,SIGNAL(textChanged(QString)),ui.message,SLOT(clear()));
    connect(ui.signInButton,SIGNAL(clicked()),ui.message,SLOT(clear()));

    loadUserInfo();
}


void LoginWindow::saveAccount(bool state)
{
    QSettings settings;

    if(state){

        settings.setValue("username",ui.username->text());
        settings.setValue("password",ui.password->text());
        settings.setValue("saveAccount",1);
    }else{
        settings.remove("username");
        settings.remove("password");
        settings.setValue("saveAccount",0);
    }
}

void LoginWindow::loadUserInfo()
{
    QSettings settings;
    QString username = settings.value("username").toString();
    QString password = settings.value("password").toString();
    bool isRemember = settings.value("saveAccount").toBool();
    if (isRemember)
    {
        ui.username->setText(username);
        ui.password->setText(password);
        ui.saveAccountCheck->setChecked(1);
        doSignIn(username,password);
    }
}

void LoginWindow::on_forgotLink_linkActivated(QString link)
{
     QDesktopServices::openUrl(QUrl(link, QUrl::TolerantMode));
}

void LoginWindow::on_registerLink_linkActivated(QString link)
{
    registerUser = new RegisterUser(this);
    registerUser->show();
}

void LoginWindow::on_signInButton_clicked()
{
    username = ui.username->text();
    doSignIn(ui.username->text(),ui.password->text());
    loginInProgress = true;
}

void LoginWindow::doSignIn(QString username,QString password)
{
    if(loginInProgress)
       return;

    if (!username.isEmpty() && !password.isEmpty())
    {
        QUrl m_loginUrl = QUrl ( QString(Constants::LOGIN_PATH) +
                             "u=" + username + "&p=" + password );
        reply = manager.get(QNetworkRequest(m_loginUrl));

        connect(reply, SIGNAL(finished()),
                this, SLOT(httpFinished()));
        connect(reply, SIGNAL(readyRead()),
                this, SLOT(httpReadyRead()));
        connect(reply, SIGNAL(downloadProgress(qint64,qint64)),
                this, SLOT(updateProgress(qint64,qint64)));
    }
}

void LoginWindow::httpFinished()
{
    reply->deleteLater();
}
void LoginWindow::updateProgress(qint64,qint64)
{
    ui.message->setText("Trying to Sign In...");
}
void LoginWindow::httpReadyRead(){
    this->accept();
    QByteArray response = reply->readAll();
    //qDebug() << response;
    if(response.contains("ok")){
        username = ui.username->text();
        ui.message->setText("");
        this->accept();
    }else if(response.contains("fail")){
        ui.message->setText("SignIn Failed!");
    }else{
        ui.message->setText("");
    }
    loginInProgress = false;
}

void LoginWindow::keyPressEvent(QKeyEvent *e)
{
     ui.message->setText("");
}
