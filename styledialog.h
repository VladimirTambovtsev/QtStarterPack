#ifndef STYLEDIALOG_H
#define STYLEDIALOG_H

#include <QDialog>

namespace Ui {
class StyleDialog;
}

class StyleDialog : public QDialog
{
    Q_OBJECT

public:
    explicit StyleDialog(QWidget *parent = nullptr);
    ~StyleDialog();

private slots:
    void on_buttonBox_rejected();

    void on_textColorButton_clicked();

    void on_backgroundButton_clicked();

    void on_fontButton_clicked();

private:
    Ui::StyleDialog *ui;
};

#endif // STYLEDIALOG_H
