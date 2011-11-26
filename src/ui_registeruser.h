/********************************************************************************
** Form generated from reading UI file 'registeruser.ui'
**
** Created: Fri Nov 25 23:17:11 2011
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERUSER_H
#define UI_REGISTERUSER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QWizard>
#include <QtGui/QWizardPage>

QT_BEGIN_NAMESPACE

class Ui_RegisterUser
{
public:
    QWizardPage *userWizard;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lastName;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *firstName;
    QLineEdit *email;
    QLineEdit *confirmEmail;
    QLineEdit *password;
    QLineEdit *confirmPassword;
    QFrame *backgroundFrame;
    QLabel *message;
    QWizardPage *userWizardFinish;
    QFrame *backgroundFrame2;
    QLabel *progressMessage;

    void setupUi(QWizard *RegisterUser)
    {
        if (RegisterUser->objectName().isEmpty())
            RegisterUser->setObjectName(QString::fromUtf8("RegisterUser"));
        RegisterUser->resize(713, 440);
        RegisterUser->setStyleSheet(QString::fromUtf8("background-color:#cccccc;\n"
""));
        userWizard = new QWizardPage();
        userWizard->setObjectName(QString::fromUtf8("userWizard"));
        label = new QLabel(userWizard);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(90, 60, 251, 16));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("background-color:white;"));
        label_2 = new QLabel(userWizard);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(380, 60, 251, 16));
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("background-color:white;"));
        lastName = new QLineEdit(userWizard);
        lastName->setObjectName(QString::fromUtf8("lastName"));
        lastName->setGeometry(QRect(380, 80, 251, 31));
        lastName->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
"border:1px solid #999999;\n"
"background-color: qlineargradient(spread:repeat, x1:0.486975, y1:0, x2:0.492462, y2:1, stop:0 rgba(144, 152, 149, 255), stop:0.19598 rgba(255, 255, 255, 255));"));
        label_3 = new QLabel(userWizard);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(90, 170, 251, 16));
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("background-color:white;"));
        label_4 = new QLabel(userWizard);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(90, 240, 251, 16));
        label_4->setFont(font);
        label_4->setStyleSheet(QString::fromUtf8("background-color:white;"));
        label_5 = new QLabel(userWizard);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(380, 240, 251, 16));
        label_5->setFont(font);
        label_5->setStyleSheet(QString::fromUtf8("background-color:white;"));
        label_6 = new QLabel(userWizard);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(380, 170, 251, 16));
        label_6->setFont(font);
        label_6->setStyleSheet(QString::fromUtf8("background-color:white;"));
        firstName = new QLineEdit(userWizard);
        firstName->setObjectName(QString::fromUtf8("firstName"));
        firstName->setGeometry(QRect(90, 80, 251, 31));
        firstName->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
"border:1px solid #999999;\n"
"background-color: qlineargradient(spread:repeat, x1:0.486975, y1:0, x2:0.492462, y2:1, stop:0 rgba(144, 152, 149, 255), stop:0.19598 rgba(255, 255, 255, 255));"));
        email = new QLineEdit(userWizard);
        email->setObjectName(QString::fromUtf8("email"));
        email->setGeometry(QRect(90, 190, 251, 31));
        email->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
"border:1px solid #999999;\n"
"background-color: qlineargradient(spread:repeat, x1:0.486975, y1:0, x2:0.492462, y2:1, stop:0 rgba(144, 152, 149, 255), stop:0.19598 rgba(255, 255, 255, 255));"));
        confirmEmail = new QLineEdit(userWizard);
        confirmEmail->setObjectName(QString::fromUtf8("confirmEmail"));
        confirmEmail->setGeometry(QRect(380, 190, 251, 31));
        confirmEmail->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
"border:1px solid #999999;\n"
"background-color: qlineargradient(spread:repeat, x1:0.486975, y1:0, x2:0.492462, y2:1, stop:0 rgba(144, 152, 149, 255), stop:0.19598 rgba(255, 255, 255, 255));"));
        password = new QLineEdit(userWizard);
        password->setObjectName(QString::fromUtf8("password"));
        password->setGeometry(QRect(90, 260, 251, 31));
        password->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
"border:1px solid #999999;\n"
"background-color: qlineargradient(spread:repeat, x1:0.486975, y1:0, x2:0.492462, y2:1, stop:0 rgba(144, 152, 149, 255), stop:0.19598 rgba(255, 255, 255, 255));"));
        password->setEchoMode(QLineEdit::Password);
        confirmPassword = new QLineEdit(userWizard);
        confirmPassword->setObjectName(QString::fromUtf8("confirmPassword"));
        confirmPassword->setGeometry(QRect(380, 260, 251, 31));
        confirmPassword->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
"border:1px solid #999999;\n"
"background-color: qlineargradient(spread:repeat, x1:0.486975, y1:0, x2:0.492462, y2:1, stop:0 rgba(144, 152, 149, 255), stop:0.19598 rgba(255, 255, 255, 255));"));
        confirmPassword->setEchoMode(QLineEdit::Password);
        backgroundFrame = new QFrame(userWizard);
        backgroundFrame->setObjectName(QString::fromUtf8("backgroundFrame"));
        backgroundFrame->setGeometry(QRect(30, 20, 641, 321));
        backgroundFrame->setStyleSheet(QString::fromUtf8("border:1px solid white;\n"
"border-radius:18px;\n"
"background-color:white;"));
        backgroundFrame->setFrameShape(QFrame::StyledPanel);
        backgroundFrame->setFrameShadow(QFrame::Raised);
        message = new QLabel(backgroundFrame);
        message->setObjectName(QString::fromUtf8("message"));
        message->setGeometry(QRect(60, 290, 541, 20));
        RegisterUser->addPage(userWizard);
        backgroundFrame->raise();
        label->raise();
        label_2->raise();
        lastName->raise();
        label_3->raise();
        label_4->raise();
        label_5->raise();
        label_6->raise();
        firstName->raise();
        email->raise();
        confirmEmail->raise();
        password->raise();
        confirmPassword->raise();
        userWizardFinish = new QWizardPage();
        userWizardFinish->setObjectName(QString::fromUtf8("userWizardFinish"));
        backgroundFrame2 = new QFrame(userWizardFinish);
        backgroundFrame2->setObjectName(QString::fromUtf8("backgroundFrame2"));
        backgroundFrame2->setGeometry(QRect(30, 20, 641, 321));
        backgroundFrame2->setStyleSheet(QString::fromUtf8("border:1px solid white;\n"
"border-radius:18px;\n"
"background-color:white;"));
        backgroundFrame2->setFrameShape(QFrame::StyledPanel);
        backgroundFrame2->setFrameShadow(QFrame::Raised);
        progressMessage = new QLabel(backgroundFrame2);
        progressMessage->setObjectName(QString::fromUtf8("progressMessage"));
        progressMessage->setGeometry(QRect(50, 50, 541, 20));
        progressMessage->setFont(font);
        RegisterUser->addPage(userWizardFinish);
        QWidget::setTabOrder(firstName, lastName);
        QWidget::setTabOrder(lastName, email);
        QWidget::setTabOrder(email, confirmEmail);
        QWidget::setTabOrder(confirmEmail, password);
        QWidget::setTabOrder(password, confirmPassword);

        retranslateUi(RegisterUser);

        QMetaObject::connectSlotsByName(RegisterUser);
    } // setupUi

    void retranslateUi(QWizard *RegisterUser)
    {
        RegisterUser->setWindowTitle(QApplication::translate("RegisterUser", "Wizard", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("RegisterUser", "First Name", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("RegisterUser", "Last Name", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("RegisterUser", "Email", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("RegisterUser", "Password", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("RegisterUser", "Confirm Password", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("RegisterUser", "Repeat Email", 0, QApplication::UnicodeUTF8));
        message->setText(QString());
        progressMessage->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class RegisterUser: public Ui_RegisterUser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERUSER_H
