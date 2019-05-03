#include "dialog.h"
#include "ui_dialog.h"

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

     if(ui->windowsRadioButton->isChecked()) {
         favoriteOs = 'Windows';
     }
     if(ui->macRadioButton->isChecked()) {
         favoriteOs = 'MacOS';
     }
     if(ui->linuxRadioButton->isChecked()) {
         favoriteOs = 'Linux';
     }
 }

 // Accept the dialog
 accept();
}

void Dialog::on_cancelDialogButton_clicked()
{
    reject();
}
