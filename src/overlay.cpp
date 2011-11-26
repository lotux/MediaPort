#include "overlay.h"
#include <QDesktopWidget>
#include <QPainter>
#include <QEvent>
#include <QtGui>
#include <QSvgRenderer>
#include <QPaintEvent>
#include <QPen>
#include <QBrush>
#include "mainapplication.h"
#include "mainwindow.h"

#ifdef DEBUG
//#include <QDebug>
#endif


Overlay::Overlay(QWidget *parent) :
    QLabel(parent)
{
    setPixmap(QPixmap(":/icons/mediaport/mediaport_osd.png"));
    resize(pixmap()->size());
    setAttribute(Qt::WA_TransparentForMouseEvents);
    setFocusPolicy( Qt::NoFocus );
}

void Overlay::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    QLabel::paintEvent(event);
}

void Overlay::resizeEvent(QResizeEvent *e)
{
      QPixmap pixmap(size());
      pixmap.fill(Qt::transparent);

      QPainter::setRedirected(this, &pixmap);
      QPaintEvent pe(rect());

      paintEvent(&pe);

      QPainter::restoreRedirected(this);

      setMask(pixmap.mask());
}
