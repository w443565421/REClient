#ifndef USERFUNCTION_H
#define USERFUNCTION_H

#include <QMainWindow>
#include <QProcess>
#include <QCloseEvent>
#include "contentDialog.h"

namespace Ui {
class UserFunction;
}

class UserFunction : public QMainWindow
{
	Q_OBJECT

public:
	explicit UserFunction(QString serverName, QString passWord, QString ipAddress, QString userName, QString portNum, QString tempPortNum, QWidget *parent = 0);
	void closeEvent(QCloseEvent *event);
	~UserFunction();

private:
	Ui::UserFunction *ui;
	QProcess *upload_process;
	QProcess *upload_and_render_process;
	QProcess *download_process;
	QProcess *newdocker_process;
	QProcess *makedocker_process;
	QProcess *startdocker_process;
	QProcess *stopdocker_process;
	QProcess *resetdocker_process;
	QProcess *deletedocker_process;
	QProcess * quit_process;
	//
	QString servername;
	QString password;
	QString ipaddress;
	QString username;//登录用户名
	QString portnum;
	QString tempPortnum;
	QString sourcefilepath;

	contentDialog * cDialog;

private slots:
	//
	void upload_file();
	void upload_and_render();
	void download_file();
	void quit();
	void quit_process_finished(int exitCode, QProcess::ExitStatus exitStatus);
//	void new_docker();
	void start_docker();
	void reset_docker();
	void log_out();
	//void delete_docker();
	//
	void upload_process_started();
	void upload_process_finished(int , QProcess::ExitStatus);
	void upload_and_render_process_started();
	void upload_and_render_process_finished(int , QProcess::ExitStatus);
	void download_process_started();
	void download_process_finished(int , QProcess::ExitStatus);
//	void newdocker_process_started();
//	void newdocker_process_finished(int , QProcess::ExitStatus);
	void stopdocker_process_started();
	void stopdocker_process_finished(int , QProcess::ExitStatus);
	void startdocker_process_started();
	void startdocker_process_finished(int , QProcess::ExitStatus);
	void makedocker_process_started();
	void makedocker_process_finished(int , QProcess::ExitStatus);
	void resetdocker_process_started();
	void resetdocker_process_finished(int , QProcess::ExitStatus);
	void deletedocker_process_started();
	void deletedocker_process_finished(int , QProcess::ExitStatus);
	//
//	void printOutput_rander();
	void printOutput_stop();
	void printOutput_start();
	void printOutput_make();
	void printOutput_reset();
	void printOutput_delete();
};

#endif // USERFUNCTION_H
