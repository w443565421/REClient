#ifndef CONTENTDIALOG_2_H
#define CONTENTDIALOG_2_H

#include <QDialog>
#include <string>

namespace Ui {
class contentDialog_2;
}

class contentDialog_2 : public QDialog
{
	Q_OBJECT

public:
    explicit contentDialog_2(QWidget *parent = 0);
    ~contentDialog_2();
	bool setLabelText(QString);
	bool setButtonEnabled();
	bool setButtonDisabled();
//	std::string acceptString();
	std::string labelStr, getStr;

signals:
	void strStatusChanged();

private slots:
	void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::contentDialog_2 *ui;
};

#endif // CONTENTDIALOG_2_H
