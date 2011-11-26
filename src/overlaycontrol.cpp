#include "overlaycontrol.h"
#include "ui_overlaycontrol.h"
#include <QDesktopWidget>

OverlayControl::OverlayControl(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OverlayControl)
{
    ui->setupUi(this);
    setWindowFlags(Qt::WindowStaysOnTopHint|Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
    QDesktopWidget *pDesktop    = QApplication::desktop ();
    //int             screenNumber     = pDesktop->screenNumber (this);
    //QWidget        *activeScreen  = pDesktop->screen (screenNumber);
    QRect           sizeDesktop = pDesktop->screenGeometry (this);
    QRect rect = this->rect();
    rect.setY(sizeDesktop.height()-100);
    rect.setX(sizeDesktop.width()/2 - rect.width()/2);
    setGeometry(rect);
}
void OverlayControl::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {

    case Qt::Key_F11:
        event->accept();
        break;

    case Qt::Key_Escape:
        break;
    }
}
OverlayControl::~OverlayControl()
{
    delete ui;
}
