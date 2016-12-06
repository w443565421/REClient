#ifndef SETIPDIALOG_H
#define SETIPDIALOG_H

#include <QDialog>

namespace Ui {
class SetIpDialog;
}

class SetIpDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SetIpDialog(QWidget *parent = 0);
    ~SetIpDialog();

private slots:
	void on_pushButton_clicked();
	void on_pushButton_2_clicked();

private:
    Ui::SetIpDialog *ui;
};

#endif // SETIPDIALOG_H
