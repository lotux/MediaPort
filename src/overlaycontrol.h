#ifndef OVERLAYCONTROL_H
#define OVERLAYCONTROL_H

#include <QDialog>
#include <QKeyEvent>

namespace Ui {
    class OverlayControl;
}

class OverlayControl : public QDialog
{
    Q_OBJECT

public:
    explicit OverlayControl(QWidget *parent = 0);
    ~OverlayControl();
    Ui::OverlayControl *ui;
    void keyPressEvent(QKeyEvent *event);

private slots:
};

#endif // OVERLAYCONTROL_H
