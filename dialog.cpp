#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_submitDialogButton_clicked()
{

 // Collect Infotmation
 QString userPosition = ui->positionLineEdit->text();
 if(!userPosition.isEmpty()) {
     position = userPosition;

     qDebug() << "position: " << position;

     if(ui->windowsRadioButton->isChecked()) {
         favoriteOs = 'w';
     }
     if(ui->macRadioButton->isChecked()) {
         favoriteOs = 'm';
     }
     if(ui->linuxRadioButton->isChecked()) {
         favoriteOs = 'l';
     }
 }

 // Accept the dialog
 accept();
}

void Dialog::on_cancelDialogButton_clicked()
{
    reject();
}

QString Dialog::getPosition() const
{
    return position;
}

QString Dialog::getFavoriteOs() const
{
    return favoriteOs;
}
