/********************************************************************************
** Form generated from reading UI file 'aboutdialog.ui'
**
** Created: Fri Nov 25 23:35:45 2011
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTDIALOG_H
#define UI_ABOUTDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AboutDialog
{
public:
    QDialogButtonBox *buttonBox;
    QFrame *frame;
    QLabel *label_2;
    QLabel *label_6;
    QLabel *version_label;
    QPushButton *pushButton;

    void setupUi(QDialog *AboutDialog)
    {
        if (AboutDialog->objectName().isEmpty())
            AboutDialog->setObjectName(QString::fromUtf8("AboutDialog"));
        AboutDialog->resize(400, 341);
        buttonBox = new QDialogButtonBox(AboutDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        frame = new QFrame(AboutDialog);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(10, 10, 378, 321));
        frame->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0.507975, y1:0.778, x2:0.487, y2:0.00531818, stop:0 rgba(71, 71, 71, 255), stop:1 rgba(158, 158, 158, 255));\n"
"border-radius:16px;\n"
"border:2px solid #cccc;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(90, 110, 201, 20));
        label_2->setStyleSheet(QString::fromUtf8("background:none;\n"
"color:white;\n"
"font-weight:bold;\n"
""));
        label_6 = new QLabel(frame);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(90, 150, 61, 20));
        label_6->setStyleSheet(QString::fromUtf8("background:none;\n"
"color:white;\n"
"font-weight:bold;\n"
""));
        version_label = new QLabel(frame);
        version_label->setObjectName(QString::fromUtf8("version_label"));
        version_label->setGeometry(QRect(170, 150, 61, 20));
        version_label->setStyleSheet(QString::fromUtf8("background:none;\n"
"color:white;\n"
"font-weight:bold;\n"
""));
        pushButton = new QPushButton(AboutDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(160, 290, 93, 28));

        retranslateUi(AboutDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), AboutDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AboutDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(AboutDialog);
    } // setupUi

    void retranslateUi(QDialog *AboutDialog)
    {
        AboutDialog->setWindowTitle(QApplication::translate("AboutDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("AboutDialog", "MediaPort", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("AboutDialog", "Version:", 0, QApplication::UnicodeUTF8));
        version_label->setText(QString());
        pushButton->setText(QApplication::translate("AboutDialog", "Close", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AboutDialog: public Ui_AboutDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTDIALOG_H
