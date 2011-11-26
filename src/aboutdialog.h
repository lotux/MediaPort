#ifndef ABOUTDIALOG_H
#define ABOUTDIALOG_H

#include <QDialog>

namespace Ui {
    class AboutDialog;
}

class AboutDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AboutDialog(QWidget *parent = 0);
    ~AboutDialog();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::AboutDialog *ui;

private slots:
    void on_label_4_linkActivated(QString link);
    void on_label_3_linkActivated(QString link);
    void on_pushButton_clicked();
};

#endif // ABOUTDIALOG_H
