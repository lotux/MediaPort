#ifndef OVERLAY_H
#define OVERLAY_H

#include <QWidget>
#include <QTimer>
#include <QtGui>
#include <QtSvg/QSvgRenderer>

class Overlay : public QLabel
{
    Q_OBJECT
public:
    explicit Overlay(QWidget *parent = 0);
    QTimer *poller;

private:
        QPixmap  cache;
        QPixmap  icon;
        QLabel   *label;
        QPushButton *button;
        QSvgRenderer *renderer;

signals:

public slots:

protected:
    void paintEvent(QPaintEvent *);
    void resizeEvent(QResizeEvent *e);

};

#endif // OVERLAY_H
