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

void StyleDialog::on_textColorButton_clicked()
{
    QPalette palette = ui->label->palette();
    QColor color = palette.color(QPalette::WindowText);

    QColor chosenColor = QColorDialog::getColor(color, this, "Choose text color");

    if(chosenColor.isValid()) {
        qDebug() << "chosen color is valid";
    } else {
        qDebug() << "chosen color is unvalid";
    }
}

