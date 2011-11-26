#include "stackview.h"
#include <QtGui>

StackView::StackView(QWidget *parent) :
    QStackedWidget(parent)
{
}
void StackView::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_F:
    case Qt::Key_F11:
        emit toggleFullscreen();
        event->accept();
        break;

    case Qt::Key_Escape:
        emit toggleFullscreen();
        event->accept();
        break;

    default:
        QStackedWidget::keyPressEvent(event);
        break;
    }
}
