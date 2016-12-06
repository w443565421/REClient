#include "userFunction.h"
#include "sendString.h"
#include "sendThread.h"
#include "dealCsv.h"
#include <QFile>
#include <QDebug>
#include <QProcess>

using namespace::std;

SendThread::SendThread(string usernameStr, string passwordMD5, mainInterface * mInterface, contentDialog * cDialog, QObject *parent) :
	QThread(parent)
{
	this->usernameStr = usernameStr;
	this->passwordMD5 = passwordMD5;
	this->mInterface = mInterface;
	this->cDialog = cDialog;
	this->rWindow = NULL;
	stop = false;
	string settingsPath = initClientSettingsPath();
	sendStr = "LogIn," + usernameStr + "," + passwordMD5 + "," +
			getStringValue(settingsPath, "ThisIp", 1) + "," +
			getStringValue(settingsPath, "ThisPort", 1) + ",";
}

SendThread::SendThread(string usernameStr, string passwordMD5, registerWindow * rWindow, contentDialog * cDialog, QObject *parent) :
	QThread(parent)
{
	this->usernameStr = usernameStr;
	this->passwordMD5 = passwordMD5;
	this->rWindow = rWindow;
	this->cDialog = cDialog;
	this->mInterface = NULL;
	stop = false;
	string settingsPath = initClientSettingsPath();
	sendStr = "Register," + usernameStr + "," + passwordMD5 + "," +
			getStringValue(settingsPath, "ThisIp", 1) + "," +
			getStringValue(settingsPath, "ThisPort", 1) + ",";
}

SendThread::SendThread(string usernameStr, QObject *parent) :
	QThread(parent)
{
	this->usernameStr = usernameStr;
	this->passwordMD5 = passwordMD5;
	this->rWindow = NULL;
	this->cDialog = NULL;
	this->mInterface = NULL;
	stop = false;
	sendStr = "Exit," + usernameStr;
}

void SendThread::run()
{
	qDebug() << "ready to get resultStr" << endl;
	string resultStr = sendStringToMaster(sendStr);
	qDebug() << QString::fromStdString(resultStr) << endl;
	cout << resultStr << endl;
	content=split(resultStr, ',');
	if(resultStr == "false") {
		cDialog->close();
		emit send_failed();
	}
	else if(content[0] == "Allow" && content[1] != "false") {
		emit allowed(QString::fromStdString(join(content, ',')));
//      cout << "emited!" << endl;
//		mInterface->hide();
//		cDialog->hide();
//      UserFunction * userFunction = new UserFunction(servername, password, ipaddress, username, portnum, 0);
//      userFunction->show();
	}
	else if(content[0] == "Allow") {
		cDialog->setLabelText(QObject::tr("没有可用的服务器，请联系管理员"));
		cDialog->setButtonEnabled();
		cDialog->show();
	}
	else if(resultStr == "LogInUnsuccessfully") {
		cDialog->setLabelText(QObject::tr("用户名和密码不匹配！"));
		cDialog->setButtonEnabled();
		cDialog->show();
	}
	else if(content[0] == "New" && content[1] != "false") {
		cDialog->setLabelText(QObject::tr("正在初始化配置…"));
		cDialog->setButtonDisabled();
		cDialog->show();
		//注册成功后为用户创建docker
		emit registered(QString::fromStdString(join(content, ',')));
	}
	else if(content[0] == "New") {
		cDialog->setLabelText(QObject::tr("没有可用的服务器，请联系管理员"));
		cDialog->setButtonEnabled();
		cDialog->show();
	}
	else if(resultStr == "AddUserUnsuccessfully") {
		cDialog->setLabelText(QObject::tr("注册失败！"));
		cDialog->setButtonEnabled();
		cDialog->show();
	}
	else if(resultStr == "Exist") {
		cDialog->setLabelText(QObject::tr("用户名已经存在！"));
		cDialog->setButtonEnabled();
		cDialog->show();
	}
	else if(resultStr == "Exited") {
		//TODO
	}
}
