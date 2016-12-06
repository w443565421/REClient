#include "getMachineInfo.h"
#include <QList>
#include <QStandardPaths>
#include <QtNetwork/QHostInfo>
#include <QtNetwork/QHostAddress>
#include <QtNetwork/QNetworkInterface>

// 获得ip地址
QString getIpAddress()
{
	QString localIPAddress = "";
	QList<QHostAddress> listAddress = QNetworkInterface::allAddresses();
	for(int j = 0; j < listAddress.size(); j++){
		if(!listAddress.at(j).isNull() &&
		   listAddress.at(j).protocol() ==  QAbstractSocket::IPv4Protocol
		   && listAddress.at(j) != QHostAddress::LocalHost){
			localIPAddress = listAddress.at(j).toString();
			return localIPAddress;
		}
	}
	return localIPAddress;
}

// 获得用户名
QString getUserName()
{
	QString userName = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
	userName = userName.section("/", -1, -1);
	return userName;
}

// 获得机器名字
QString getMachineName()
{
	QString localHostName = QHostInfo::localHostName();
	return localHostName;
}

// 获得MAC地址
QString getMACAdress()
{
   QList<QNetworkInterface>  NetList;	//网卡链表
   int NetCount = 0;		   //网卡个数
   int Neti = 0;
   QNetworkInterface thisNet;	  //所要使用的网卡
   NetList = QNetworkInterface::allInterfaces();//获取所有网卡信息
   NetCount = NetList.count();		 //统计网卡个数
   for(Neti = 0;Neti < NetCount; Neti++){   //遍历所有网卡
	   if(NetList[Neti].isValid()){	//判断该网卡是否是合法
		   thisNet = NetList[Neti];	//将该网卡置为当前网卡
		   break;
	   }
   }
   return ( thisNet.hardwareAddress() );   //获取该网卡的MAC
}
