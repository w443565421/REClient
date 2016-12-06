#ifndef REGISTERWINDOW_H
#define REGISTERWINDOW_H

#include <QDialog>
#include <QProcess>
#include <vector>
#include <string>
#include "contentDialog.h"
#include "contentDialog_2.h"
#include "setIpDialog.h"

using namespace::std;

namespace Ui {
	class registerWindow;
}

class registerWindow : public QDialog
{
	Q_OBJECT

public:
	explicit registerWindow(QWidget *parent = 0);
	~registerWindow();

signals:
	void newdocker_process_finished_signal();
	void stopdocker_process_finished_signal();

private slots:
//	void printOutput_p();
	void after_send_failed();

	void on_pushButton_clicked();
	void on_pushButton_2_clicked();

	void newdocker_process_started();
	void newdocker_process_finished(int , QProcess::ExitStatus);

	void stopdocker_process_started();
	void stopdocker_process_finished(int , QProcess::ExitStatus);

	void ready_to_newdocker(QString content_from_send_thread);
	void ready_to_stopdocker();

private:
	contentDialog * cDialog;
	contentDialog_2 * cDialog_2;
//	SetIpDialog * sDialog;
	vector<string> content;
	Ui::registerWindow *ui;
	QProcess * p;//TO BE DELETED
};

#endif // REGISTERWINDOW_H
