#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include "styledialog.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->positionLabel->setAutoFillBackground(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    qDebug() << "Submitting data..";


    // open new dialog
    Dialog * dialog = new Dialog(this);
    int ret = dialog->exec();

    if (ret == QDialog::Accepted)
    {
        QString position = dialog->getPosition();
        QString os = dialog->getFavoriteOs();

        qDebug() << "Dialog accepted; position: " << position;
        qDebug() << "Dialog accepted; os: " << os;


        ui->positionLabel->setText("Position: " + position);
        ui->osLabel->setText("OS: " + os);

        ui->pushButton->setText("Change");

    }

    if (ret == QDialog::Rejected)
    {
        qDebug() << "Dialog rejected";
    }

}

void MainWindow::on_pushButton_2_clicked()
{
    StyleDialog * styleDialog = new StyleDialog(this);

    // lambda style
    connect(styleDialog, &StyleDialog::accepted,[=](){

        // set font from styledialog
        QFont font = styleDialog->getFont();
        ui->positionLabel->setFont(font);
        ui->osLabel->setFont(font);
        ui->pushButton->setFont(font);
        ui->pushButton_2->setFont(font);

        // set textColor & background color from styledialog
        QPalette textColor = styleDialog->getTextColor();

        // set autofill for background color
        ui->positionLabel->setAutoFillBackground(true);
        ui->osLabel->setAutoFillBackground(true);

        // set and apply color & background to labels
        ui->positionLabel->setPalette(textColor);
        ui->osLabel->setPalette(textColor);

        // set stylesheets for buttons
        ui->pushButton->setStyleSheet("QPushButton{background-color: #000; color: grey; border-radius: 5px; padding: 5px 10px}");
        ui->pushButton_2->setStyleSheet("QPushButton{background-color: brown; color: grey; border-radius: 5px; padding: 5px 10px}");


    });

    connect(styleDialog, &StyleDialog::rejected,[=](){
        qDebug() << "StyleDialog Rejected";
    });

    styleDialog->exec();
}
