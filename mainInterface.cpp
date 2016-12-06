#include "md5.h"
#include "utils.h"
#include "dealCsv.h"
#include "sendString.h"
#include "sendThread.h"
#include "userFunction.h"
#include "contentDialog.h"
#include "mainInterface.h"
#include "registerWindow.h"
#include "ui_mainInterface.h"
#include <QDebug>
#include <QString>
#include <QProcess>
#include <QSplashScreen>
#include <QElapsedTimer>
#include <QDateTime>
#include <QPixmap>

mainInterface::mainInterface(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::mainInterface)
{
	ui->setupUi(this);
	setFixedSize(this->width(), this->height());
	a = 0;
}

mainInterface::~mainInterface()
{
	delete ui;
}

void mainInterface::on_pushButton_clicked()
{
	registerWindow * rWindow = new registerWindow(this);
	rWindow->setModal(true);
	rWindow->show();
}

void mainInterface::on_pushButton_2_clicked() {
	cDialog = new contentDialog();
	cDialog_2 = new contentDialog_2();
	cDialog->setModal(true);
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
	else {
		cDialog->setLabelText(QObject::tr("正在连接服务器……"));
		cDialog->setButtonDisabled();
		cDialog->show();
		SendThread * sendThread = new SendThread(ui->lineEdit->text().toStdString(),
											   MD5(ui->lineEdit_2->text().toStdString()).toString(),
											   this, cDialog);
		connect(sendThread, SIGNAL(allowed(QString)), this, SLOT(send_process_successed(QString)), Qt::AutoConnection);
		connect(sendThread, SIGNAL(send_failed()), this, SLOT(after_send_failed()));
		sendThread->start();
//        send_process = new QProcess(this);
//        connect(send_process, SIGNAL(started()), this, SLOT(send_process_started()));
//        send_process->start();

//    hide();

	}
}

void mainInterface::send_process_successed(QString content_from_send_thread)
{
#if 0
	QPixmap pixmap(":/res/res/logo2.png");
	QSplashScreen screen(pixmap);
	screen.show();
//    screen.showMessage("LOVE", Qt::AlignCenter, Qt::red);
#if 1
	int delayTime = 1;
	QElapsedTimer timer;
	timer.start();

	while(timer.elapsed() < (delayTime * 2000))//2000为需要延时的毫秒数
	{
		qApp->processEvents();
	}
#endif

#if 1
	QDateTime n=QDateTime::currentDateTime();
	QDateTime now;
	do{
		now=QDateTime::currentDateTime();
		qApp->processEvents();
	} while (n.secsTo(now)<=2);//2为需要延时的秒数
#endif

#endif
	vector<string> content = split(content_from_send_thread.toStdString(), ',');
	QString servername = QString::fromStdString(content[4]);
	QString password = QString::fromStdString(content[5]);
	QString ipaddress = QString::fromStdString(content[1]);
	QString username = ui->lineEdit->text();
	QString portnum = QString::fromStdString(content[2]);
	QString tempPortnum = QString::fromStdString(content[3]);
	cout << "ready to open userFunction" << endl;
	UserFunction * userFunction = new UserFunction(servername, password, ipaddress, username, portnum, tempPortnum);
	userFunction->show();
	cDialog->close();
	close();
}

void mainInterface::after_send_failed()
{
//	contentDialog_2 * cDialog_2 = new contentDialog_2();
	cDialog_2->setModal(true);
	cDialog_2->setLabelText(QObject::tr("服务器连接失败，请确定服务器已开启"));
	cDialog_2->setButtonEnabled();
	cDialog_2->show();
}
