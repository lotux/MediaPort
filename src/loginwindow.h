#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QDialog>
#include "ui_loginwindow.h"
#include "registeruser.h"
#include <QNetworkAccessManager>
#include <QNetworkReply>

class LoginWindow : public QDialog
{
    Q_OBJECT
public:
    explicit LoginWindow(QWidget *parent = 0);
    QString username;

signals:

public slots:
    //void replyFinished(QNetworkReply* reply);
    void httpFinished();
    void httpReadyRead();
    void updateProgress(qint64,qint64);

private:
    Ui::LoginWindow ui;
    RegisterUser *registerUser;
    bool loginInProgress;

    void doSignIn(QString username,QString password);
    void loadUserInfo();


    QNetworkAccessManager manager;
    QNetworkReply *reply;

private slots:
    void on_signInButton_clicked();
    void on_registerLink_linkActivated(QString link);
    void on_forgotLink_linkActivated(QString link);
    void saveAccount(bool state);


protected:
    void keyPressEvent(QKeyEvent *);

};

#endif // LOGINWINDOW_H
