#include "styledialog.h"
#include "ui_styledialog.h"
#include <QColorDialog>
#include <QDebug>


StyleDialog::StyleDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StyleDialog)
{
    ui->setupUi(this);
    ui->label->setAutoFillBackground(true);
}

StyleDialog::~StyleDialog()
{
    delete ui;
}

void StyleDialog::on_buttonBox_rejected()
{
    reject();
}

void StyleDialog::on_buttonBox_accepted()
{
    qDebug() << "StyleDialog accepted";
}

void StyleDialog::on_textButton_clicked()
{
    QPalette palette = ui->label->palette();
}

void StyleDialog::on_backgroundButton_clicked()
{

}

void StyleDialog::on_fontButton_clicked()
{

}
