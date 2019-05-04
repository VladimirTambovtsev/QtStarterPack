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

    QFont getFont() const;

    QPalette getTextColor() const;

private slots:
    void on_buttonBox_rejected();

    void on_textColorButton_clicked();

    void on_backgroundButton_clicked();

    void on_fontButton_clicked();

    void on_buttonBox_accepted();

private:
    Ui::StyleDialog *ui;
    QFont font;
    QPalette textColor;
    QString backgroundColor;
};

#endif // STYLEDIALOG_H
