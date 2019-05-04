#include "styledialog.h"
#include "ui_styledialog.h"
#include <QColorDialog>
#include <QFontDialog>
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
        palette.setColor(QPalette::WindowText, chosenColor);
        ui->label->setPalette(palette);

        qDebug() << "chosen color is valid";
    } else {
        qDebug() << "chosen color is unvalid";
    }
}


void StyleDialog::on_backgroundButton_clicked()
{
    QPalette palette = ui->label->palette();
    QColor color = palette.color(QPalette::Window);

    QColor chosenColor = QColorDialog::getColor(color, this, "Choose text color");

    if(chosenColor.isValid()) {
        palette.setColor(QPalette::Window, chosenColor);
        ui->label->setPalette(palette);

        qDebug() << "chosen color is valid";
    } else {
        qDebug() << "chosen color is unvalid";
    }
}

void StyleDialog::on_fontButton_clicked()
{
    bool ok;
    QFont font = QFontDialog::getFont(
                &ok, QFont("Helvetica [Cronyx]", 10), this);

    if(ok) {
        ui->label->setFont(font);
    } else {
        qDebug() << "Error setting font";
    }

}
