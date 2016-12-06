#include <QString>
#include <string>
#include <acceptStringThenReply.h>
#include "contentDialog_2.h"
#include "setIpDialog.h"
#include "ui_contentDialog_2.h"

contentDialog_2::contentDialog_2(QWidget *parent) :
	QDialog(parent),
    ui(new Ui::contentDialog_2)
{
	ui->setupUi(this);
	setFixedSize(this->width(), this->height());
//    connect(this, SIGNAL(strStatusChanged()), this, SLOT(setLabelText(getStr)));
}

contentDialog_2::~contentDialog_2()
{
	delete ui;
}

bool contentDialog_2::setLabelText(QString QStr)
{
	ui->label->setText(QStr);
	this->update();
	return true;
}

bool contentDialog_2::setButtonEnabled()
{
	ui->pushButton->setEnabled(true);
	return true;
}

bool contentDialog_2::setButtonDisabled()
{
	ui->pushButton->setDisabled(true);
	return true;
}

void contentDialog_2::on_pushButton_clicked()
{
	close();
}


void contentDialog_2::on_pushButton_2_clicked()
{
    SetIpDialog * sDialog = new SetIpDialog();
	sDialog->setModal(true);
	sDialog->show();
	close();
}
/*
std::string contentDialog_2::acceptString()
{
	string getStr = acceptStringThenReply();
	emit strStatusChanged();
	return getStr;
}
*/
