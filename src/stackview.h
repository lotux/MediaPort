#ifndef STACKVIEW_H
#define STACKVIEW_H

#include <QStackedWidget>

class StackView : public QStackedWidget
{
    Q_OBJECT
public:
    explicit StackView(QWidget *parent = 0);

signals:
    void toggleFullscreen();

public slots:

protected:
    void keyPressEvent(QKeyEvent *event);

};

#endif // STACKVIEW_H
