/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created: Sat Nov 26 10:41:28 2011
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QLineEdit *username;
    QLineEdit *password;
    QLabel *usernameLabel;
    QLabel *passwordLabel;
    QPushButton *signInButton;
    QFrame *frame;
    QCheckBox *saveAccountCheck;
    QLabel *registerLink;
    QLabel *forgotLink;
    QLabel *message;

    void setupUi(QDialog *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName(QString::fromUtf8("LoginWindow"));
        LoginWindow->resize(350, 350);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(LoginWindow->sizePolicy().hasHeightForWidth());
        LoginWindow->setSizePolicy(sizePolicy);
        LoginWindow->setMinimumSize(QSize(350, 350));
        LoginWindow->setMaximumSize(QSize(350, 350));
        LoginWindow->setWindowOpacity(200);
        LoginWindow->setStyleSheet(QString::fromUtf8(""));
        username = new QLineEdit(LoginWindow);
        username->setObjectName(QString::fromUtf8("username"));
        username->setGeometry(QRect(70, 110, 221, 31));
        username->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
"border:1px solid #dddddd;\n"
"background-color: qlineargradient(spread:repeat, x1:0.486975, y1:0, x2:0.492462, y2:1, stop:0 rgba(144, 152, 149, 255), stop:0.19598 rgba(255, 255, 255, 255));"));
        password = new QLineEdit(LoginWindow);
        password->setObjectName(QString::fromUtf8("password"));
        password->setGeometry(QRect(70, 200, 221, 31));
        password->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
"border:1px solid #dddddd;\n"
"background-color: qlineargradient(spread:repeat, x1:0.486975, y1:0, x2:0.492462, y2:1, stop:0 rgba(144, 152, 149, 255), stop:0.19598 rgba(255, 255, 255, 255));"));
        password->setEchoMode(QLineEdit::Password);
        usernameLabel = new QLabel(LoginWindow);
        usernameLabel->setObjectName(QString::fromUtf8("usernameLabel"));
        usernameLabel->setGeometry(QRect(70, 90, 71, 16));
        usernameLabel->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: rgb(26, 25, 15);\n"
"font-weight:bold;"));
        passwordLabel = new QLabel(LoginWindow);
        passwordLabel->setObjectName(QString::fromUtf8("passwordLabel"));
        passwordLabel->setGeometry(QRect(70, 180, 71, 16));
        passwordLabel->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: rgb(26, 25, 15);\n"
"font-weight:bold;"));
        signInButton = new QPushButton(LoginWindow);
        signInButton->setObjectName(QString::fromUtf8("signInButton"));
        signInButton->setGeometry(QRect(210, 280, 93, 28));
        signInButton->setStyleSheet(QString::fromUtf8(""));
        signInButton->setFlat(false);
        frame = new QFrame(LoginWindow);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(20, 10, 311, 321));
        frame->setStyleSheet(QString::fromUtf8("background-color:qlineargradient(spread:repeat, x1:0.498, y1:0, x2:0.498, y2:1, stop:0 rgba(175, 239, 255, 255), stop:0.145729 rgba(140, 205, 241, 255), stop:1 rgba(73, 139, 215, 255));\n"
"border-radius:14px;\n"
"border: 3px solid #eeeeee;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        saveAccountCheck = new QCheckBox(frame);
        saveAccountCheck->setObjectName(QString::fromUtf8("saveAccountCheck"));
        saveAccountCheck->setGeometry(QRect(50, 270, 121, 21));
        saveAccountCheck->setStyleSheet(QString::fromUtf8("background-color:transparent;\n"
"border:none;\n"
"color:#444444;\n"
"font-weight:bold;"));
        registerLink = new QLabel(frame);
        registerLink->setObjectName(QString::fromUtf8("registerLink"));
        registerLink->setGeometry(QRect(70, 140, 151, 21));
        registerLink->setStyleSheet(QString::fromUtf8("background-color:transparent;\n"
"border:none;"));
        registerLink->setTextFormat(Qt::RichText);
        forgotLink = new QLabel(frame);
        forgotLink->setObjectName(QString::fromUtf8("forgotLink"));
        forgotLink->setGeometry(QRect(70, 230, 171, 21));
        forgotLink->setStyleSheet(QString::fromUtf8("background-color:transparent;\n"
"border:none;"));
        message = new QLabel(LoginWindow);
        message->setObjectName(QString::fromUtf8("message"));
        message->setGeometry(QRect(70, 300, 221, 21));
        message->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: red;\n"
"font-weight:bold;\n"
"border:none;"));
        frame->raise();
        username->raise();
        password->raise();
        usernameLabel->raise();
        passwordLabel->raise();
        signInButton->raise();
        message->raise();

        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QDialog *LoginWindow)
    {
        LoginWindow->setWindowTitle(QApplication::translate("LoginWindow", "Dialog", 0, QApplication::UnicodeUTF8));
        usernameLabel->setText(QApplication::translate("LoginWindow", "Username", 0, QApplication::UnicodeUTF8));
        passwordLabel->setText(QApplication::translate("LoginWindow", "Password", 0, QApplication::UnicodeUTF8));
        signInButton->setText(QApplication::translate("LoginWindow", "Sign In", 0, QApplication::UnicodeUTF8));
        saveAccountCheck->setText(QApplication::translate("LoginWindow", "Remember me", 0, QApplication::UnicodeUTF8));
        registerLink->setText(QApplication::translate("LoginWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><a href=\"http://mediaport.com/register\"><span style=\" font-size:8pt; text-decoration: underline; color:#0000ff;\">I don't have username</span></a></p></body></html>", 0, QApplication::UnicodeUTF8));
        forgotLink->setText(QApplication::translate("LoginWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><a href=\"http://mediaport.com/recorver\"><span style=\" font-size:8pt; text-decoration: underline; color:#0000ff;\">Forgot Username/Password?</span></a></p></body></html>", 0, QApplication::UnicodeUTF8));
        message->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
