#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

    QString getFavoriteOs() const;

    QString getPosition() const;

private slots:
    void on_submitDialogButton_clicked();

    void on_cancelDialogButton_clicked();

private:
    Ui::Dialog *ui;
    QString position;
    QString favoriteOs;
};

#endif // DIALOG_H
