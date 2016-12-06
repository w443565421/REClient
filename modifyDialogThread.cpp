#include "modifyDialogThread.h"

using namespace::std;

ModifyDialogThread::ModifyDialogThread(registerWindow * rWindow, contentDialog * cDialog, QObject *parent) :
	QThread(parent)
{
	this->cDialog = cDialog;
	this->rWindow = rWindow;
	this->uFunction = NULL;
}

ModifyDialogThread::ModifyDialogThread(UserFunction * uFunction, contentDialog * cDialog, QObject *parent) :
	QThread(parent)
{
	this->cDialog = cDialog;
	this->rWindow = NULL;
	this->uFunction = uFunction;
}

void ModifyDialogThread::run()
{
	if(rWindow != NULL) {
		connect(rWindow, SIGNAL(stopdocker_process_finished_signal()), this, SLOT(stopdocker_process_finished_slot()), Qt::AutoConnection);
	}
}

void ModifyDialogThread::stopdocker_process_finished_slot()
{
	cDialog->setLabelText(QObject::tr("注册成功！"));
	cDialog->setButtonEnabled();
	cDialog->show();
}
