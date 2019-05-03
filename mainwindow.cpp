#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    qDebug() << "Submitting data..";
    qDebug() << "First Name is " << ui->firstNameLineEdit->text();
    qDebug() << "Last Name is " << ui->lastNameLineEdit->text();
    qDebug() << "Message is " << ui->messageLineEdit->text();

    ui->pushButton->setText("Loading..");

    // open new dialog
    Dialog * dialog = new Dialog(this);
    int ret = dialog->exec();

    if (ret == QDialog::Accepted) {
        qDebug() << "Dialog accepted";
    }

    if (ret == QDialog::Rejected) {
        qDebug() << "Dialog rejected";
    }

}
