/********************************************************************************
** Form generated from reading UI file 'overlaycontrol.ui'
**
** Created: Fri Nov 25 23:35:45 2011
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OVERLAYCONTROL_H
#define UI_OVERLAYCONTROL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_OverlayControl
{
public:
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;

    void setupUi(QDialog *OverlayControl)
    {
        if (OverlayControl->objectName().isEmpty())
            OverlayControl->setObjectName(QString::fromUtf8("OverlayControl"));
        OverlayControl->resize(203, 71);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(OverlayControl->sizePolicy().hasHeightForWidth());
        OverlayControl->setSizePolicy(sizePolicy);
        OverlayControl->setMinimumSize(QSize(200, 0));
        OverlayControl->setMaximumSize(QSize(203, 71));
        OverlayControl->setBaseSize(QSize(400, 71));
        OverlayControl->setWindowOpacity(0.5);
        OverlayControl->setStyleSheet(QString::fromUtf8("border-radius:5px;\n"
"border:2px solid white;"));
        horizontalLayout_2 = new QHBoxLayout(OverlayControl);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));

        horizontalLayout_2->addLayout(horizontalLayout);


        retranslateUi(OverlayControl);

        QMetaObject::connectSlotsByName(OverlayControl);
    } // setupUi

    void retranslateUi(QDialog *OverlayControl)
    {
        OverlayControl->setWindowTitle(QApplication::translate("OverlayControl", "Dialog", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class OverlayControl: public Ui_OverlayControl {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OVERLAYCONTROL_H
