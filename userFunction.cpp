#include "dealCsv.h"
#include "sendThread.h"
#include "sendString.h"
#include "userFunction.h"
#include "mainInterface.h"
#include "ui_userFunction.h"
#include <QFile>
#include <QDebug>
#include <QAction>
#include <QMessageBox>
#include <QFileDialog>
#include <QDesktopWidget>

UserFunction::UserFunction(QString serverName, QString passWord, QString ipAddress, QString userName, QString portNum, QString tempPortNum, QWidget *parent):
	QMainWindow(parent),
	ui(new Ui::UserFunction)
{
	ui->setupUi(this);
	QDesktopWidget *pos = QApplication::desktop();
	move((pos->width() - this->width())/2, (pos->height() - this->height())/2);
	setFixedSize(this->width(), this->height());
	setWindowTitle(QObject::tr("Rendering Express"));
	QIcon qIcon;
	qIcon.addFile(":/res/res/uploadAndRender.png");
	ui->pushButton->setIcon(qIcon);
	QIcon qIcon_2;
	qIcon_2.addFile(":/res/res/render.png");
	ui->pushButton_2->setIcon(qIcon_2);
	ui->outputDialog->setReadOnly(true);

	servername = serverName;
	password = passWord;
	ipaddress = ipAddress;
	username = userName;
	portnum = portNum;
	tempPortnum = tempPortNum;
	//

	QAction *upload = ui->action_2;
	QAction *exit = ui->action_3;
	QAction *newdocker = ui->action_4;
	QAction *startdocker = ui->action_5;
	QAction *download = ui->action_6;
	QAction *resetdocker = ui->action_7;
	QAction *logout = ui->action_8;
	QPushButton *uploadbutton = ui->pushButton;
	QPushButton *startdockerbutton = ui->pushButton_2;

	//创建上传文件进程
	upload_process = new QProcess(this);
	connect(upload_process , SIGNAL(started()) , this ,
			SLOT(upload_process_started()));
	connect(upload_process , SIGNAL(finished(int,QProcess::ExitStatus)) , this ,
			SLOT(upload_process_finished(int,QProcess::ExitStatus)));

	//创建上传并渲染进程
	upload_and_render_process = new QProcess(this);
	connect(upload_and_render_process , SIGNAL(started()) , this ,
			SLOT(upload_and_render_process_started()));
	connect(upload_and_render_process , SIGNAL(finished(int,QProcess::ExitStatus)) , this ,
			SLOT(upload_and_render_process_finished(int,QProcess::ExitStatus)));

	//创建下载文件进程
	download_process = new QProcess(this);
	connect(download_process , SIGNAL(started()) , this ,
			SLOT(download_process_started()));
	connect(download_process , SIGNAL(finished(int,QProcess::ExitStatus)) , this ,
			SLOT(download_process_finished(int,QProcess::ExitStatus)));

	//创建新建docker进程
/*
	newdocker_process = new QProcess(this);
	connect(newdocker_process , SIGNAL(started()) , this ,
			SLOT(newdocker_process_started()));
	connect(newdocker_process , SIGNAL(finished(int,QProcess::ExitStatus)) , this ,
			SLOT(newdocker_process_finished(int,QProcess::ExitStatus)));
	connect(newdocker_process , SIGNAL(readyReadStandardOutput()) , this ,
			SLOT(printOutput_rander()));
*/

	//创建停止docker进程
	stopdocker_process = new QProcess(this);
	connect(stopdocker_process , SIGNAL(started()) , this ,
			SLOT(stopdocker_process_started()));
	connect(stopdocker_process , SIGNAL(finished(int,QProcess::ExitStatus)) , this ,
			SLOT(stopdocker_process_finished(int,QProcess::ExitStatus)));
	connect(stopdocker_process , SIGNAL(readyReadStandardOutput()) , this ,
			SLOT(printOutput_stop()));

	//创建开启docker进程
	startdocker_process = new QProcess(this);
	connect(startdocker_process , SIGNAL(started()) , this ,
			SLOT(startdocker_process_started()));
	connect(startdocker_process , SIGNAL(finished(int,QProcess::ExitStatus)) , this ,
			SLOT(startdocker_process_finished(int,QProcess::ExitStatus)));
	connect(startdocker_process , SIGNAL(readyReadStandardOutput()) , this ,
			SLOT(printOutput_start()));

	//创建makedocker进程
	makedocker_process = new QProcess(this);
	connect(makedocker_process , SIGNAL(started()) , this ,
			SLOT(makedocker_process_started()));
	connect(makedocker_process , SIGNAL(finished(int,QProcess::ExitStatus)) , this ,
			SLOT(makedocker_process_finished(int,QProcess::ExitStatus)));
	connect(makedocker_process , SIGNAL(readyReadStandardOutput()) , this ,
			SLOT(printOutput_make()));

	//创建重置docker进程
	resetdocker_process = new QProcess(this);
	connect(resetdocker_process , SIGNAL(started()) , this ,
			SLOT(resetdocker_process_started()));
	connect(resetdocker_process , SIGNAL(finished(int,QProcess::ExitStatus)) , this ,
			SLOT(resetdocker_process_finished(int,QProcess::ExitStatus)));
	connect(resetdocker_process , SIGNAL(readyReadStandardOutput()) , this ,
			SLOT(printOutput_reset()));

	//创建删除docker进程(删除用户时)
	deletedocker_process = new QProcess(this);
	connect(deletedocker_process , SIGNAL(started()) , this ,
			SLOT(deletedocker_process_started()));
	connect(deletedocker_process , SIGNAL(finished(int,QProcess::ExitStatus)) , this ,
			SLOT(deletedocker_process_finished(int,QProcess::ExitStatus)));
	connect(deletedocker_process , SIGNAL(readyReadStandardOutput()) , this ,
			SLOT(printOutput_delete()));

	//创建quit进程
	quit_process = new QProcess(this);
//	connect(quit_process , SIGNAL(started()) , this ,
//			SLOT(deletedocker_process_started()));
	connect(quit_process , SIGNAL(finished(int,QProcess::ExitStatus)) , this ,
			SLOT(quit_process_finished(int,QProcess::ExitStatus)));
//	connect(deletedocker_process , SIGNAL(readyReadStandardOutput()) , this ,
//			SLOT(printOutput_delete()));

	connect(upload, SIGNAL(triggered()), this, SLOT(upload_file()));
	connect(download, SIGNAL(triggered()), this, SLOT(download_file()));
	connect(exit , SIGNAL(triggered()), this, SLOT(quit()));
//	connect(newdocker , SIGNAL(triggered()), this, SLOT(new_docker()));
	connect(startdocker , SIGNAL(triggered()), this, SLOT(start_docker()));
	connect(resetdocker , SIGNAL(triggered()), this, SLOT(reset_docker()));
	connect(logout, SIGNAL(triggered(bool)), this, SLOT(log_out()));
	connect(uploadbutton , SIGNAL(clicked()), this, SLOT(upload_and_render()));
	connect(startdockerbutton , SIGNAL(clicked()), this, SLOT(start_docker()));
}

UserFunction::~UserFunction()
{
	delete ui;
}

// 选择文件
void UserFunction::upload_file()
{
	// 提示对话框
/*
	QMessageBox::information(this,tr("注意"),
						tr("请选择需要上传的文件！"),QMessageBox::Ok);
*/
	QFileDialog *file = new QFileDialog();
	QString filename = file->getOpenFileName(this , tr("选择文件") , "/home");
	qDebug() << "filename: " << filename;

	QString destname = servername;
	QString destipaddress = ipaddress;
	QString destfilepath = "/home/" + servername + "/" + username;
	QFile::copy(":/shell/shell/upload_file", "/tmp/upload_file");
	QFile::copy(":/shell/shell/upload_file.ep", "/tmp/upload_file.ep");
	QFile::copy(":/shell/shell/upload_file_spawn", "/tmp/upload_file_spawn");
	QString command = "sh /tmp/upload_file";
//	QString command = "sh :/shell/shell/upload_file";

	if(filename.length() != 0) {
		sourcefilepath = filename;
		command += " " + sourcefilepath;
		command += " " + destname;
		command += " " + destipaddress;
		command += " " + password;
		command += " " + destfilepath;
		qDebug() << command << endl;
		upload_process->start(command);
		return ;
	} else {
		return ;
	}
}

/* 上传并渲染 */
void UserFunction::upload_and_render() {
	// 提示对话框
/*
	QMessageBox::information(this,tr("注意"),
						tr("请选择需要上传的文件！"),QMessageBox::Ok);
*/
	QFileDialog *file = new QFileDialog();
	QString filename = file->getOpenFileName(this , tr("选择文件") , "/home");
	qDebug() << "filename: " << filename;

	QString destname = servername;
	QString destipaddress = ipaddress;
	QString destfilepath = "/home/" + servername + "/" + username;
	QFile::copy(":/shell/shell/upload_file", "/tmp/upload_file");
	QFile::copy(":/shell/shell/upload_file.ep", "/tmp/upload_file.ep");
	QFile::copy(":/shell/shell/upload_file_spawn", "/tmp/upload_file_spawn");
	QString command = "sh /tmp/upload_file";
//	QString command = "sh :/shell/shell/upload_file";

	if(filename.length() != 0) {
		sourcefilepath = filename;
		command += " " + sourcefilepath;
		command += " " + destname;
		command += " " + destipaddress;
		command += " " + password;
		command += " " + destfilepath;
		qDebug() << command << endl;
		upload_and_render_process->start(command);
	}
}

void UserFunction::download_file() {
	// 提示对话框
/*
	QMessageBox::information(this,tr("注意"),
						tr("请选择需要保存文件的路径！"),QMessageBox::Ok);
*/
	QFileDialog *file = new QFileDialog();
	QString filedictionary = file->getExistingDirectory(this , tr("选择保存路径") , "/home");
	qDebug() << "filedictionary: " << filedictionary;

	QString sourcename = servername;
	QString sourceipaddress = ipaddress;
	QString sourcefilepath = "/home/" + servername + "/" + username;
	QString destfilepath = filedictionary;
	QFile::copy(":/shell/shell/download_file", "/tmp/download_file");
	QFile::copy(":/shell/shell/download_file.ep", "/tmp/download_file.ep");
	QFile::copy(":/shell/shell/download_file_spawn", "/tmp/download_file_spawn");
	QString command = "sh /tmp/download_file";
//	QString command = "sh :/shell/shell/download_file";
	if(filedictionary != "") {
		command += " " + sourcename;
		command += " " + sourceipaddress;
		command += " " + sourcefilepath;
		command += " " + password;
		command += " " + destfilepath;
		download_process->start(command);
		qDebug() << command << endl;
	}
}
/*
void UserFunction::new_docker() {

	QString command = "sh :/shell/shell/new_docker";
	command += " " + servername;
	command += " " + password;
	command += " " + ipaddress;
	command += " " + username;
	command += " " + portnum;
	newdocker_process->start(command);
}
*/
void UserFunction::start_docker() {

	QFile::copy(":/shell/shell/start_docker", "/tmp/start_docker");
	QFile::copy(":/shell/shell/start_docker.ep", "/tmp/start_docker.ep");
	QFile::copy(":/shell/shell/change_ownership.ep", "/tmp/change_ownership.ep");
	QString command = "sh /tmp/start_docker";
//	QString command = "sh :/shell/shell/start_docker";
	command += " " + servername;
	command += " " + password;
	command += " " + ipaddress;
	command += " " + username;
	command += " " + portnum;
	startdocker_process->start(command);
	qDebug() << command << endl;
}

void UserFunction::reset_docker() {

	QString command = "sh :/shell/shell/reset_docker";
	command += " " + servername;
	command += " " + password;
	command += " " + ipaddress;
	command += " " + username;
	command += " " + portnum;
	resetdocker_process->start(command);
}

void UserFunction::upload_process_started() {
	//Todo
}

void UserFunction::upload_process_finished(int exitCode, QProcess::ExitStatus exitStatus) {
	cDialog = new contentDialog();
	if(exitStatus == QProcess::NormalExit) {
		QFile fp("/tmp/result.txt");
		if (!fp.open(QIODevice::ReadOnly | QIODevice::Text)) {
/*
			QMessageBox::information(this,tr("上传失败"),
								tr("无法获取信息！"),QMessageBox::Ok);
*/
			cDialog->setWindowTitle(tr("上传失败"));
			cDialog->setLabelText(tr("无法获取信息！"));
			cDialog->setButtonEnabled();
			cDialog->show();
			fp.close();
			return;
		}
		if(fp.size() == 0) {
/*
			QMessageBox::information(this,tr("上传成功"),
								tr("文件上传成功！"),QMessageBox::Ok);
*/
			cDialog->setWindowTitle(tr("上传成功"));
			cDialog->setLabelText(tr("文件上传成功！"));
			cDialog->setButtonEnabled();
			cDialog->show();
		}
		else {
			QTextStream in(&fp);
			QString result = "";
			while (!in.atEnd()) {
				result += in.readLine() + "\r";
			}
/*
			QMessageBox::information(this,tr("上传失败"),
								result,QMessageBox::Ok);
*/
			cDialog->setWindowTitle(tr("上传失败"));
			cDialog->setLabelText(result);
			cDialog->setButtonEnabled();
			cDialog->show();
		}
		fp.close();

	} else {
/*
		QMessageBox::information(this,tr("上传失败"),
							tr("操作异常结束，请重试！"),QMessageBox::Ok);
*/
		cDialog->setWindowTitle(tr("上传失败"));
		cDialog->setLabelText(tr("操作异常结束，请重试！"));
		cDialog->setButtonEnabled();
		cDialog->show();
	}
	QFile::remove("/tmp/upload_file");
	QFile::remove("/tmp/upload_file.ep");
	QFile::remove("/tmp/upload_file_spawn");
}

void UserFunction::upload_and_render_process_started() {
	//Todo
}

void UserFunction::upload_and_render_process_finished(int exitCode, QProcess::ExitStatus exitStatus) {
	cDialog = new contentDialog();
	if(exitStatus == QProcess::NormalExit) {
		QFile fp("/tmp/result.txt");
		if (!fp.open(QIODevice::ReadOnly | QIODevice::Text)) {
/*
			QMessageBox::information(this,tr("上传失败"),
											tr("无法获取信息！"),QMessageBox::Ok);
*/
			cDialog->setWindowTitle(tr("上传失败"));
			cDialog->setLabelText(tr("无法获取信息！"));
			cDialog->setButtonEnabled();
			cDialog->show();
			fp.close();
			return;
		}
		if(fp.size() == 0) {
/*
			QMessageBox::information(this,tr("上传成功"),
											tr("文件上传成功！"),QMessageBox::Ok);
*/
			cDialog->setWindowTitle(tr("上传成功"));
			cDialog->setLabelText(tr("文件上传成功！正在渲染…"));
			cDialog->setButtonDisabled();
			cDialog->show();
			QFile::copy(":/shell/shell/make_docker", "/tmp/make_docker");
			QFile::copy(":/shell/shell/make_docker.ep", "/tmp/make_docker.ep");
			QFile::copy(":/shell/shell/start_temp_docker.ep", "/tmp/start_temp_docker.ep");
			QFile::copy(":/shell/shell/delete_docker.ep", "/tmp/delete_docker.ep");
			QString command = "sh /tmp/make_docker";
			command += " " + servername;
			command += " " + password;
			command += " " + ipaddress;
			command += " " + username;
			command += " " + tempPortnum;
			command += " " + QString::fromStdString(getFilenameFromPath(sourcefilepath.toStdString()));
			qDebug() << command << endl;
			makedocker_process->start(command);
		} else {
			QTextStream in(&fp);
			QString result = "";
			while (!in.atEnd()) {
				result += in.readLine() + "\r";
			}
/*
			QMessageBox::information(this,tr("上传失败"),
								result,QMessageBox::Ok);
*/
			cDialog->setWindowTitle(tr("上传失败"));
			cDialog->setLabelText(result);
			cDialog->setButtonEnabled();
			cDialog->show();
		}
		fp.close();

	} else {
/*
		QMessageBox::information(this,tr("上传失败"),
							tr("操作异常结束，请重试！"),QMessageBox::Ok);
*/
		cDialog->setWindowTitle(tr("上传失败"));
		cDialog->setLabelText(tr("操作异常结束，请重试！"));
		cDialog->setButtonEnabled();
		cDialog->show();
	}
	QFile::remove("/tmp/upload_file");
	QFile::remove("/tmp/upload_file.ep");
	QFile::remove("/tmp/upload_file_spawn");
}

void UserFunction::download_process_started() {
	//Todo
}

void UserFunction::download_process_finished(int exitCode, QProcess::ExitStatus exitStatus) {
	cDialog = new contentDialog();
	if(exitStatus == QProcess::NormalExit) {
		QFile fp("/tmp/result.txt");
		if (!fp.open(QIODevice::ReadOnly | QIODevice::Text)) {
/*
			QMessageBox::information(this,tr("下载失败"),
								tr("无法获取信息！"),QMessageBox::Ok);
*/
			cDialog->setWindowTitle(tr("下载失败"));
			cDialog->setLabelText(tr("无法获取信息！"));
			cDialog->setButtonEnabled();
			cDialog->show();
			fp.close();
			return;
		}
		if(fp.size() == 0) {
/*
			QMessageBox::information(this,tr("下载成功"),
								tr("文件下载成功！"),QMessageBox::Ok);
*/
			cDialog->setWindowTitle(tr("下载成功"));
			cDialog->setLabelText(tr("文件下载成功！"));
			cDialog->setButtonEnabled();
			cDialog->show();
		}
		else {
			QTextStream in(&fp);
			QString result = "";
			while (!in.atEnd()) {
				result += in.readLine() + "\r";
			}
/*
			QMessageBox::information(this,tr("下载失败"),
								result,QMessageBox::Ok);
*/
			cDialog->setWindowTitle(tr("下载失败"));
			cDialog->setLabelText(result);
			cDialog->setButtonEnabled();
			cDialog->show();
		}
		fp.close();

	} else {
/*
		QMessageBox::information(this,tr("下载失败"),
							tr("操作异常结束，请重试！"),QMessageBox::Ok);
*/
		cDialog->setWindowTitle(tr("下载失败"));
		cDialog->setLabelText(tr("操作异常结束，请重试！"));
		cDialog->setButtonEnabled();
		cDialog->show();
	}
	QFile::remove("/tmp/download_file");
	QFile::remove("/tmp/download_file.ep");
	QFile::remove("/tmp/download_file_spawn");
}

/* new docker */
/*
void UserFunction::newdocker_process_started() {
	//Todo
	ui->outputDialog->append("Creating new docker...");
}

void UserFunction::newdocker_process_finished(int exitCode, QProcess::ExitStatus exitStatus) {
	if(exitStatus == QProcess::NormalExit) {
		ui->outputDialog->append("New docker created！");

		QString command = "sh :/shell/shell/stop_docker";
		command += " " + servername;
		command += " " + password;
		command += " " + ipaddress;
		command += " " + username;
		stopdocker_process->start(command);

	} else {
		ui->outputDialog->append("Failed to create new docker！");
	}
}

void UserFunction::printOutput_rander() {
	QString log = newdocker_process->readAllStandardOutput();
	//qDebug() << log << endl;
	//if(log.indexOf("lost connection") == -1) progressbar_flag = 0;
	ui->outputDialog->append(log);
	//滚动条滑块置底
	ui->outputDialog->moveCursor(QTextCursor::End);
}
*/
/* stop docker */
void UserFunction::stopdocker_process_started() {
	//Todo
	ui->outputDialog->append("stopping docker...");
}

void UserFunction::stopdocker_process_finished(int exitCode, QProcess::ExitStatus exitStatus) {
	if(exitStatus == QProcess::NormalExit) {
		ui->outputDialog->append("Stopped docker！");
	} else {
		ui->outputDialog->append("Failed to stop docker！");
	}
}

void UserFunction::printOutput_stop() {
	QString log = stopdocker_process->readAllStandardOutput();
	//qDebug() << log << endl;
	//if(log.indexOf("lost connection") == -1) progressbar_flag = 0;
	ui->outputDialog->append(log);
	//滚动条滑块置底
	ui->outputDialog->moveCursor(QTextCursor::End);
}

/* start docker */

void UserFunction::startdocker_process_started() {
	//Todo
	ui->outputDialog->append("startdocker process started！");
/*    QMessageBox * WrrMsg = new QMessageBox(QMessageBox::NoIcon, tr(""), tr("正在渲染！"), QMessageBox::Ok, 0);

	if(NULL!=WrrMsg->button(QMessageBox::Ok))
	{
		WrrMsg->button(QMessageBox::Ok)->setText("确定");
		WrrMsg->button(QMessageBox::Ok)->setDisabled(true);
	}
	QMessageBox::information(this,tr(""),
						tr("正在渲染！"),QMessageBox::Ok, 0);
*/
}

void UserFunction::startdocker_process_finished(int exitCode, QProcess::ExitStatus exitStatus) {
	if(exitStatus == QProcess::NormalExit) {
		ui->outputDialog->append("startdocker process finished！");
	} else {
		ui->outputDialog->append("startdocker process failed！");
	}
	QFile::remove("/tmp/start_docker");
	QFile::remove("/tmp/start_docker.ep");
	QFile::remove("/tmp/change_ownership.ep");
}

void UserFunction::printOutput_start() {
	QString log = startdocker_process->readAllStandardOutput();
	//qDebug() << log << endl;
	//if(log.indexOf("lost connection") == -1) progressbar_flag = 0;
	ui->outputDialog->append(log);
	//滚动条滑块置底
	ui->outputDialog->moveCursor(QTextCursor::End);
}

/* make docker */

void UserFunction::makedocker_process_started() {
	//Todo
	ui->outputDialog->append("makedocker process started！");
/*    QMessageBox * WrrMsg = new QMessageBox(QMessageBox::NoIcon, tr(""), tr("正在渲染！"), QMessageBox::Ok, 0);

	if(NULL!=WrrMsg->button(QMessageBox::Ok))
	{
		WrrMsg->button(QMessageBox::Ok)->setText("确定");
		WrrMsg->button(QMessageBox::Ok)->setDisabled(true);
	}
	QMessageBox::information(this,tr(""),
						tr("正在渲染！"),QMessageBox::Ok, 0);
*/
}

void UserFunction::makedocker_process_finished(int exitCode, QProcess::ExitStatus exitStatus) {
	if(exitStatus == QProcess::NormalExit) {
		ui->outputDialog->append("makedocker process finished！");
	} else {
		ui->outputDialog->append("makedocker process failed！");
	}
	cDialog->close();
	QFile::remove("/tmp/make_docker");
	QFile::remove("/tmp/make_docker.ep");
	QFile::remove("/tmp/start_temp_docker.ep");
	QFile::remove("/tmp/delete_docker.ep");
}

void UserFunction::printOutput_make() {
	QString log = makedocker_process->readAllStandardOutput();
	//qDebug() << log << endl;
	//if(log.indexOf("lost connection") == -1) progressbar_flag = 0;
	ui->outputDialog->append(log);
	//滚动条滑块置底
	ui->outputDialog->moveCursor(QTextCursor::End);
}

/* reset docker */

void UserFunction::resetdocker_process_started() {
	//Todo
	ui->outputDialog->append("resetting docker...");
}

void UserFunction::resetdocker_process_finished(int exitCode, QProcess::ExitStatus exitStatus) {
	if(exitStatus == QProcess::NormalExit) {
		ui->outputDialog->append("Resetted docker！");
	} else {
		ui->outputDialog->append("Failed to reset docker！");
	}
}

void UserFunction::printOutput_reset() {
	QString log = resetdocker_process->readAllStandardOutput();
	//qDebug() << log << endl;
	//if(log.indexOf("lost connection") == -1) progressbar_flag = 0;
	ui->outputDialog->append(log);
	//滚动条滑块置底
	ui->outputDialog->moveCursor(QTextCursor::End);
}

/* delete docker */

void UserFunction::deletedocker_process_started() {
	//Todo
	ui->outputDialog->append("deleting docker...");
}

void UserFunction::deletedocker_process_finished(int exitCode, QProcess::ExitStatus exitStatus) {
	if(exitStatus == QProcess::NormalExit) {
		ui->outputDialog->append("Deleted docker！");
	} else {
		ui->outputDialog->append("Failed to delete docker！");
	}
}

void UserFunction::printOutput_delete() {
	QString log = resetdocker_process->readAllStandardOutput();
	//qDebug() << log << endl;
	//if(log.indexOf("lost connection") == -1) progressbar_flag = 0;
	ui->outputDialog->append(log);
	//滚动条滑块置底
	ui->outputDialog->moveCursor(QTextCursor::End);
}

void UserFunction::closeEvent(QCloseEvent *event)
{
	quit();
}

void UserFunction::quit() {
	cDialog = new contentDialog();
	cDialog->setWindowTitle(tr("退出"));
	cDialog->setLabelText(tr("正在退出…"));
	cDialog->setButtonDisabled();
	cDialog->show();
	QFile::copy(":/shell/shell/stop_docker", "/tmp/stop_docker");
	QFile::copy(":/shell/shell/stop_docker.ep", "/tmp/stop_docker.ep");
	QString command = "sh /tmp/stop_docker";
//	QString command = "sh :/shell/shell/stop_docker";
	command += " " + servername;
	command += " " + password;
	command += " " + ipaddress;
	command += " " + username;
	qDebug() << command << endl;
	quit_process->start(command);
	SendThread * sendThread = new SendThread(username.toStdString());
//	connect(sendThread, SIGNAL(allowed(QString, QString, QString, QString, QString)), this, SLOT(send_process_successed(QString, QString, QString, QString, QString)), Qt::AutoConnection);
	sendThread->start();
	hide();
}

void UserFunction::quit_process_finished(int exitCode, QProcess::ExitStatus exitStatus) {
	if(exitStatus == QProcess::NormalExit) {
		qDebug() << "quit process finished!" << endl;
	} else {
		qDebug() << "quit process failed!" << endl;
	}
	QFile::remove("/tmp/stop_docker");
	QFile::remove("/tmp/stop_docker.ep");
	cDialog->setWindowTitle(tr("退出"));
	cDialog->setLabelText(tr("退出成功！"));
	cDialog->setButtonEnabled();
	cDialog->show();
}

void UserFunction::log_out()
{
	mainInterface * mInterface = new mainInterface();
	mInterface->setWindowTitle(QObject::tr("登录"));
	mInterface->show();
	quit();
}
