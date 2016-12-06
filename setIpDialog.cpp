#include "utils.h"
#include "dealCsv.h"
#include "setIpDialog.h"
#include "contentDialog.h"
#include "ui_setIpDialog.h"

SetIpDialog::SetIpDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SetIpDialog)
{
    ui->setupUi(this);
}

SetIpDialog::~SetIpDialog()
{
    delete ui;
}

void SetIpDialog::on_pushButton_clicked()
{
	contentDialog * cDialog = new contentDialog();
	QString ip = ui->lineEdit->text();
	cout << ip.toStdString() << endl;
	if(isValidV4IP(ip.toStdString())) {
		string settingsPath = initClientSettingsPath();
		setStringValue(settingsPath, "MasterIp", 1, ip.toStdString());
		cDialog->setLabelText("IP设置成功，请重新登录。");
		cDialog->setButtonEnabled();
		cDialog->setModal(true);
		cDialog->show();
		close();
	}
	else {
		cDialog->setLabelText("请输入合法的IP地址。");
		cDialog->setButtonEnabled();
		cDialog->setModal(true);
		cDialog->show();
	}
}

void SetIpDialog::on_pushButton_2_clicked()
{
	close();
}
