#include "aboutdialog.h"
#include "ui_aboutdialog.h"
#include "QDesktopServices"
#include <QUrl>

AboutDialog::AboutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutDialog)
{
    setAttribute(Qt::WA_TranslucentBackground, true);
    setWindowFlags(Qt::FramelessWindowHint);
    ui->setupUi(this);
    ui->version_label->setText(qApp->applicationVersion());
}

AboutDialog::~AboutDialog()
{
    delete ui;
}

void AboutDialog::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void AboutDialog::on_pushButton_clicked()
{
    close();
}

void AboutDialog::on_label_3_linkActivated(QString link)
{
    QDesktopServices::openUrl(QUrl(link, QUrl::TolerantMode));
}

void AboutDialog::on_label_4_linkActivated(QString link)
{
    QDesktopServices::openUrl(QUrl(link, QUrl::TolerantMode));
}
