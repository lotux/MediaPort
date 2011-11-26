#ifndef REGISTERUSER_H
#define REGISTERUSER_H

#include <QWizard>
#include <QtGui>
#include <QNetworkAccessManager>
#include <QNetworkReply>

namespace Ui {
    class RegisterUser;
}

class RegisterUser : public QWizard
{
    Q_OBJECT

public:
    explicit RegisterUser(QWidget *parent = 0);
    ~RegisterUser();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::RegisterUser *ui;

    void doRegister();

    QRegExpValidator *emailValidator;
    QRegExpValidator *nameValidator;
    QRegExpValidator *passwordValidator;

    QNetworkAccessManager manager;
    QNetworkReply *reply;


private slots:
    void checkUserInput(int);
    void clearError(QString);

public slots:
    //void replyFinished(QNetworkReply* reply);
    void httpFinished();
    void httpReadyRead();
    void updateProgress(qint64,qint64);
};

#endif // REGISTERUSER_H
