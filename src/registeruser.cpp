#include "registeruser.h"
#include "ui_registeruser.h"
#include "constants.h"

RegisterUser::RegisterUser(QWidget *parent) :
    QWizard(parent),
    ui(new Ui::RegisterUser)
{
    ui->setupUi(this);

    QRegExp emailRegex( "^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+.[a-zA-Z]{2,4}$" );
    emailValidator = new QRegExpValidator(emailRegex,this);
    ui->email->setValidator(emailValidator);
    ui->confirmEmail->setValidator(emailValidator);

    QRegExp nameRegex( "^.{3,50}$" );
    nameValidator = new QRegExpValidator( nameRegex, this);
    ui->firstName->setValidator(nameValidator);
    ui->lastName->setValidator(nameValidator);

    QRegExp passwordRegex( "^.{5,50}$" );
    passwordValidator = new QRegExpValidator( passwordRegex, 0 );
    ui->password->setValidator(passwordValidator);
    ui->confirmPassword->setValidator(passwordValidator);
    connect(this,SIGNAL(currentIdChanged(int)),this,SLOT(checkUserInput(int)));

    connect(ui->firstName,SIGNAL(textChanged(QString)),this,SLOT(clearError(QString)));
    connect(ui->lastName,SIGNAL(textChanged(QString)),this,SLOT(clearError(QString)));
    connect(ui->email,SIGNAL(textChanged(QString)),this,SLOT(clearError(QString)));
    connect(ui->password,SIGNAL(textChanged(QString)),this,SLOT(clearError(QString)));
    connect(ui->confirmEmail,SIGNAL(textChanged(QString)),this,SLOT(clearError(QString)));
    connect(ui->confirmPassword,SIGNAL(textChanged(QString)),this,SLOT(clearError(QString)));

    QNetworkAccessManager *manager = new QNetworkAccessManager(this);

}
void RegisterUser::clearError(QString)
{
     ui->email->setStyleSheet(ui->email->styleSheet()+"border-color:#999999;");
     ui->password->setStyleSheet(ui->password->styleSheet()+"border-color:#999999;");
     ui->firstName->setStyleSheet(ui->firstName->styleSheet()+"border-color:#999999;");
     ui->confirmEmail->setStyleSheet(ui->confirmEmail->styleSheet()+"border-color:#999999;");
     ui->confirmPassword->setStyleSheet(ui->confirmPassword->styleSheet()+"border-color:#999999;");
     ui->lastName->setStyleSheet(ui->lastName->styleSheet()+"border-color:#999999;");
     ui->message->clear();
}

void RegisterUser::checkUserInput(int pageId)
{

    int pos = 0;
    bool isValid = true;
    if (pageId == 1)
    {

        if (emailValidator->validate(ui->email->text(),pos) !=  QValidator::Acceptable ||
            ui->email->text() != ui->confirmEmail->text())
        {

           ui->message->setText("Please Enter Your Email and Repeat it, Both <b>Must</b> be same.");
           ui->email->setStyleSheet(ui->email->styleSheet()+"border-color:red;");
           ui->confirmEmail->setStyleSheet(ui->confirmEmail->styleSheet()+"border-color:red;");
           isValid = false;
           back();
        }

        if (passwordValidator->validate(ui->password->text(),pos) !=  QValidator::Acceptable ||
            ui->password->text() != ui->confirmPassword->text())
        {

            ui->message->setText("Please Enter Your Email and Repeat it, Both <b>Must</b> be same.");
            ui->password->setStyleSheet(ui->password->styleSheet()+"border-color:red;");
            ui->confirmPassword->setStyleSheet(ui->confirmPassword->styleSheet()+"border-color:red;");
            isValid = false;
            back();
        }

        if (nameValidator->validate(ui->firstName->text(),pos) !=  QValidator::Acceptable)
        {
            ui->message->setText("Please Enter Your First Name.");
            ui->firstName->setStyleSheet(ui->firstName->styleSheet()+"border-color:red;");
            isValid = false;
            back();
        }

        if (nameValidator->validate(ui->lastName->text(),pos) !=  QValidator::Acceptable)
        {
            ui->message->setText("Please Enter Your Last Name.");
            ui->lastName->setStyleSheet(ui->lastName->styleSheet()+"border-color:red;");
            isValid = false;
            back();
        }

        if (isValid)
            doRegister();

    }
}

RegisterUser::~RegisterUser()
{
    delete ui;
}

void RegisterUser::changeEvent(QEvent *e)
{
    QWizard::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void RegisterUser::doRegister()
{


    QUrl m_registerUrl = QUrl( QString( Constants::REGISTER_PATH ) +
                               "fname=" + ui->firstName->text() +
                               "&lname=" + ui->lastName->text() +
                               "&pass=" + ui->password->text()+
                               "&email="+ui->email->text()
                   );

   reply = manager.get(QNetworkRequest(m_registerUrl));
   ui->progressMessage->setText("Registeration in progress...");

   connect(reply, SIGNAL(finished()),
              this, SLOT(httpFinished()));
   connect(reply, SIGNAL(readyRead()),
              this, SLOT(httpReadyRead()));
   connect(reply, SIGNAL(downloadProgress(qint64,qint64)),
              this, SLOT(updateProgress(qint64,qint64)));
}

void RegisterUser::httpFinished()
{
    reply->deleteLater();
}
void RegisterUser::updateProgress(qint64,qint64)
{
    //ui->progressMessage->setText("Registeration in progress...");
}
void RegisterUser::httpReadyRead(){
    QByteArray response = reply->readAll();
    if(response.contains("ok")){
        ui->progressMessage->setText("Your Registration is done. Please check you email and confirm it.");
    }else{
        ui->progressMessage->setText("Registration Failed!, Please try later.");
    }
}
