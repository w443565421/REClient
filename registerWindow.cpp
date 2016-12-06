#include "md5.h"
#include "utils.h"
#include "dealCsv.h"
#include "sendString.h"
#include "sendThread.h"
#include "registerWindow.h"
#include "modifyDialogThread.h"
#include "acceptStringThenReply.h"
#include "ui_registerWindow.h"
#include <QProcess>
#include <QDebug>

registerWindow::registerWindow(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::registerWindow)
{
	ui->setupUi(this);
	setFixedSize(this->width(), this->height());//设置窗口大小固定
}

registerWindow::~registerWindow()
{
	delete ui;
}

void registerWindow::on_pushButton_clicked()
{
	cDialog = new contentDialog();
	cDialog_2 = new contentDialog_2();
	cDialog->setModal(true);
//    printf("ready to abc");
	if(ui->lineEdit->text().isEmpty()) {
		cDialog->setLabelText(QObject::tr("用户名不可为空！"));
		cDialog->setButtonEnabled();
		cDialog->show();
	}
	else if(! isValidUsername(ui->lineEdit->text())) {
		cDialog->setLabelText(QObject::tr("您的用户名必须以英文字母开头，\n且只能包含下划线、字母和数字。"));
		cDialog->setButtonEnabled();
		cDialog->show();
	}
	else if(ui->lineEdit->text().length() < 3) {
		cDialog->setLabelText(QObject::tr("您的用户名长度不得小于3。"));
		cDialog->setButtonEnabled();
		cDialog->show();
	}
	else if(ui->lineEdit_2->text() != ui->lineEdit_3->text()) {
		cDialog->setLabelText(QObject::tr("密码填写不一致！"));
		cDialog->setButtonEnabled();
		cDialog->show();
	}
	else {
		cDialog->setLabelText(QObject::tr("正在连接服务器……"));
		cDialog->setButtonDisabled();
		cDialog->show();
		SendThread * sendThread = new SendThread(ui->lineEdit->text().toStdString(),
											   MD5(ui->lineEdit_2->text().toStdString()).toString(),
											   this, cDialog);
		//
		ModifyDialogThread * modifyDialogThread = new ModifyDialogThread(this, cDialog);
		connect(sendThread, SIGNAL(registered(QString)), this, SLOT(ready_to_newdocker(QString)), Qt::AutoConnection);
		connect(sendThread, SIGNAL(send_failed()), this, SLOT(after_send_failed()), Qt::AutoConnection);
		connect(this, SIGNAL(newdocker_process_finished_signal()), this, SLOT(ready_to_stopdocker()), Qt::AutoConnection);
		modifyDialogThread->start();
		sendThread->start();

	}
}

void registerWindow::on_pushButton_2_clicked()
{
	close();
}

void registerWindow::ready_to_newdocker(QString content_from_send_thread)
{
	content = split(content_from_send_thread.toStdString(), ',');
	/*QProcess **/p = new QProcess(this);
	connect(p , SIGNAL(started()) , this ,
			SLOT(newdocker_process_started()));
	connect(p , SIGNAL(finished(int,QProcess::ExitStatus)) , this ,
			SLOT(newdocker_process_finished(int,QProcess::ExitStatus)));
/*
	connect(p , SIGNAL(readyReadStandardOutput()) , this ,
			SLOT(printOutput_p()));
*/
	QString servername = QString::fromStdString(content[4]);
	QString password = QString::fromStdString(content[5]);
	QString ipaddress = QString::fromStdString(content[1]);
	QString username = QString::fromStdString(ui->lineEdit->text().toStdString());
	QString portnum = QString::fromStdString(content[2]);
//		QString tempPortnum = QString::fromStdString(content[3]);
	QFile::copy(":/shell/shell/new_docker", "/tmp/new_docker");
	QFile::copy(":/shell/shell/new_docker.ep", "/tmp/new_docker.ep");
	QString command = "sh /tmp/new_docker";
	command += " " + servername;
	command += " " + password;
	command += " " + ipaddress;
	command += " " + username;
	command += " " + portnum;
	cout << "ready to newdocker: command = " << command.toStdString() << endl;
	p->start(command);
}

void registerWindow::newdocker_process_started() {
	qDebug() << "newdocker process started !" << endl;
	//qDebug() << "servername: " << servername << ", password: " << password
			 //<< endl;
}

void registerWindow::newdocker_process_finished(int exitCode, QProcess::ExitStatus exitStatus) {
	if(exitStatus == QProcess::NormalExit) {
		qDebug() << "newdocker process finished !" << endl;
		emit newdocker_process_finished_signal();
	} else {
		qDebug() << "newdocker process failed !" << endl;
	}
//	delete p;
	QFile::remove("/tmp/new_docker");
	QFile::remove("/tmp/new_docker.ep");
}

void registerWindow::ready_to_stopdocker()
{
	p = new QProcess(this);
	connect(p , SIGNAL(started()) , this ,
			SLOT(stopdocker_process_started()));
	connect(p , SIGNAL(finished(int,QProcess::ExitStatus)) , this ,
			SLOT(stopdocker_process_finished(int,QProcess::ExitStatus)));
/*
	connect(p , SIGNAL(readyReadStandardOutput()) , this ,
			SLOT(printOutput_p()));
*/
	QString servername = QString::fromStdString(content[4]);
	QString password = QString::fromStdString(content[5]);
	QString ipaddress = QString::fromStdString(content[1]);
	QString username = QString::fromStdString(ui->lineEdit->text().toStdString());
	QFile::copy(":/shell/shell/stop_docker", "/tmp/stop_docker");
	QFile::copy(":/shell/shell/stop_docker.ep", "/tmp/stop_docker.ep");
	QString command = "sh /tmp/stop_docker";
	command += " " + servername;
	command += " " + password;
	command += " " + ipaddress;
	command += " " + username;
	cout << "ready to stopdocker: command = " << command.toStdString() << endl;
	p->start(command);
}

void registerWindow::stopdocker_process_started() {
	qDebug() << "stopdocker process started !" << endl;
	//qDebug() << "servername: " << servername << ", password: " << password
			 //<< endl;
}

void registerWindow::stopdocker_process_finished(int exitCode, QProcess::ExitStatus exitStatus) {
	if(exitStatus == QProcess::NormalExit) {
		qDebug() << "stopdocker process finished !" << endl;
		emit stopdocker_process_finished_signal();
	} else {
		qDebug() << "stopdocker process failed !" << endl;
	}
	QFile::remove("/tmp/stop_docker");
	QFile::remove("/tmp/stop_docker.ep");
	close();
}

void registerWindow::after_send_failed()
{
//	contentDialog_2 * cDialog_2 = new contentDialog_2();
	cDialog_2->setModal(true);
	cDialog_2->setLabelText(QObject::tr("服务器连接失败，请确定服务器已开启"));
	cDialog_2->setButtonEnabled();
	cDialog_2->show();
}

/*
void registerWindow::printOutput_p()
{
	QString log = p->readAllStandardOutput();
	qDebug() << log << endl;
}
*/
