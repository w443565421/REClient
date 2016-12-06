#ifndef MODIFYDIALOGTHREAD_H
#define MODIFYDIALOGTHREAD_H
#include <QThread>
#include "registerWindow.h"
#include "userFunction.h"
#include "contentDialog.h"

using namespace::std;

class ModifyDialogThread : public QThread
{
	Q_OBJECT
public:
	explicit ModifyDialogThread(registerWindow *, contentDialog *, QObject *parent = 0);
	explicit ModifyDialogThread(UserFunction *, contentDialog *, QObject *parent = 0);
	void run();

private slots:
	void stopdocker_process_finished_slot();

private:
	contentDialog * cDialog;
	registerWindow * rWindow;
	UserFunction * uFunction;
};

#endif // MODIFYDIALOGTHREAD_H
