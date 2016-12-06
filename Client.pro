
QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Client
TEMPLATE = app

RC_FILE = app.rc

SOURCES += main.cpp\
	mainInterface.cpp \
	md5.cpp \
	dealCsv.cpp \
	registerWindow.cpp \
	contentDialog.cpp \
	communication.cpp \
	sendString.cpp \
	userFunction.cpp \
	sendThread.cpp \
	cmysplashscreen.cpp \
	utils.cpp \
	getMachineInfo.cpp \
    modifyDialogThread.cpp \
    contentDialog_2.cpp \
    setIpDialog.cpp

HEADERS  += \
	mainInterface.h \
	md5.h \
	dealCsv.h \
	registerWindow.h \
	contentDialog.h \
	communication.h \
	sendString.h \
	userFunction.h \
	sendThread.h \
	cmysplashscreen.h \
	utils.h \
	getMachineInfo.h \
        modifyDialogThread.h \
        contentDialog_2.h \
        setIpDialog.h

FORMS    += \
	mainInterface.ui \
	registerWindow.ui \
	contentDialog.ui \
	communication.ui \
	userFunction.ui \
        contentDialog_2.ui \
        setIpDialog.ui

DISTFILES += \
        ../../../../.gmanager/clientSettings.csv

RESOURCES += \
        client.qrc
