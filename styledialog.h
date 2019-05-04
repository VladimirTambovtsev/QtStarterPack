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

<<<<<<< HEAD
    void on_buttonBox_accepted();

    void on_pushButton_3_clicked();

    void on_backgroundButton_clicked();

    void on_textButton_clicked();

    void on_fontButton_clicked();

=======
>>>>>>> d209007ad01667ba492a82f4f9fba527737ab340
private:
    Ui::StyleDialog *ui;
};

#endif // STYLEDIALOG_H
