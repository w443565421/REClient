#ifndef SENDTHREAD_H
#define SENDTHREAD_H
#include <QThread>
#include <string>
#include <vector>
#include "mainInterface.h"
#include "registerWindow.h"
#include "contentDialog.h"
#include "contentDialog_2.h"

using namespace::std;

class SendThread : public QThread
{
	Q_OBJECT
public:
	bool stop ;
	explicit SendThread(string, string, mainInterface *, contentDialog *, QObject *parent = 0);
	explicit SendThread(string, string, registerWindow *, contentDialog *, QObject *parent = 0);
	explicit SendThread(string, QObject *parent = 0);
	void run();

signals:
	void allowed(QString);
	void registered(QString);
	void send_failed();

private:
	string usernameStr;
	string passwordMD5;
	string sendStr;
	contentDialog * cDialog;
	mainInterface * mInterface;
	registerWindow * rWindow;
	vector<string> content;
};
#endif // MYTHREAD_H
