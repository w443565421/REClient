//
// Created by wbl on 16-7-29.
//
#include "dealCsv.h"
#include "getMachineInfo.h"
#include <QDebug>

//const string csvfp = "/home/wbl/Desktop/1.csv";

vector<vector<string>> readCsv(string filePath)
//	read a csv file,
//	return vector<vector<string>> contains strings if the file if success;
//	return vector<vector<string>> contains nothing if failed.
{
	std::vector<vector<string>>  context;
	string line, field;
	ifstream in(filePath);
	if(in.is_open())
	{
		while(getline(in, line))
		{
			std::vector<string> rowContext = split(line, ',');
			context.push_back(rowContext);
		}
		in.close();
	}
	else
		cout << "open csv error." << endl;
	return context;
}

bool writeCsv(string filePath, vector<vector<string>> content)
//	save a vector<vector<string>> variable to the filePath(param);
//	return success?true:false;
{
	vector<vector<string>> old_content = readCsv(filePath);
	if(content == old_content) {
		return true;
	}
	ofstream out(filePath);
	if(out.is_open())
	{
		for(uint i = 0; i < content.size(); i ++) {
			out << join(content[i], ',') << '\n';
			out.flush();
		}
		out.close();
		return true;
	}
	cerr << "failed to write to " << filePath << endl;
	return false;
}


string getCsvValue(string filePath, int row, int col)
//	if row and col are valid index
//	return the string of the coordinate in the csv.

{
	vector<vector<string>> context = readCsv(filePath);
	if(row < context.size() && col < context[row].size()) {
		string result = context[row][col];
		return result;
	}
	else{
		cout << "get value from " << filePath << " failed.";
		return "";
	}
}


bool setCsvValue(string filePath, int row, int col, string setValue)
//	if row and col are valid index,
//	set the string at the coordinate to the setValue.
{
	vector<vector<string>> context = readCsv(filePath);
	if(row < context.size() && col < context[row].size()) {
		context[row][col] = setValue;
		return writeCsv(filePath, context);
	}
	else {
		cout << "failed to set value of " << filePath << "." << endl;
		cout << "out of index" << endl;
		return false;
	}
}


bool appendInfoToCsv(string filePath, string info)
//	add a row(means a record) to the end of the file.
{
	vector<vector<string>> old_content = readCsv(filePath);
	vector<string> a_server;
	a_server = split(info, ',');
	old_content.push_back(a_server);
	return writeCsv(filePath, old_content);
}


bool deleteInfoFromCsv(string filePath, string keyword)
//	delete one row of the file by the kye word "keyword."
{
	vector<vector<string>> old_content, content;
	//	old-content means the content of the file,
	//	delete one record and save the others in content.
	old_content = readCsv(filePath);
	for(auto serv:old_content) {
		if(serv[0] != keyword) {
			content.push_back(serv);
		}
	}
	return writeCsv(filePath, content);
}

int getIntValue(string filePath, string keyword, int location)
{
	std::stringstream ss;
	return aton(getStringValue(filePath, keyword, location));
}

string getStringValue(string filePath, string keyword, int location)
{
	vector<vector<string>> context = readCsv(filePath);
	for(uint i = 0; i < context.size(); i ++) {
		if(getCsvValue(filePath, i, 0) == keyword) {
			return getCsvValue(filePath, i, location);
		}
	}
	return "false";
}

bool setStringValue(string filePath, string keyword, int location, string setValue)
{
	vector<vector<string>> context = readCsv(filePath);
	for(uint i = 0; i < context.size(); i ++) {
		if(getCsvValue(filePath, i, 0) == keyword) {
			return setCsvValue(filePath, i, location, setValue);
		}
	}
	return false;
}

bool isRecordExisting(string filePath, string keyword)
{
	vector<vector<string>> context = readCsv(filePath);
	for(uint i = 0; i < context.size(); i ++) {
		if(context[i][0] == keyword) {
			return true;
		}
	}
	return false;
}

bool initCsv(string filePath)
{
	ofstream out(filePath);
	if(out.is_open())
	{
		out.close();
		return true;
	}
	else
		return false;
}

string initMasterSettingsPath()
{
	QDir * path = new QDir();
	QFile * file;
	//获得登录用户名
	string username = getUserName().toStdString();
	string settingsPath = "/home/" + username + "/.gmanager";
//	string userInfoPath = "/home/" + username + "/.gmanager";
	if(! path->exists(QString::fromStdString(settingsPath))) {
		if(! path->mkpath(QString::fromStdString(settingsPath))) {
			cout << "mkpath error!" << endl;
			return "false";
		}
		else {
			settingsPath += "/masterSettings.csv";
//			userInfoPath += "/userInfo.csv";
			file = new QFile(QString::fromStdString(settingsPath));
			if(! file->exists()) {
				if(! file->open(QIODevice::ReadWrite | QIODevice::Text)) {
					qDebug() << "Can't create the file!" << endl;
					return "false";
				}
				QTextStream stream(file);
				stream << "ThisPort,36688,\nMinPort,5900,\nMinTempPort,17300,\nPortRange,100,\nMaxCons,10," << endl;
				file->close();
			}
			return settingsPath;
		}
	}
	else {
		settingsPath += "/masterSettings.csv";
//		userInfoPath += "/userInfo.csv";
		file = new QFile(QString::fromStdString(settingsPath));
		if(! file->exists()) {
			if(! file->open(QIODevice::ReadWrite | QIODevice::Text)) {
				qDebug() << "Can't create the file!" << endl;
				return "false";
			}
			QTextStream stream(file);
			stream << "ThisPort,36688,\nMinPort,5900,\nMinTempPort,17300,\nPortRange,100,\nMaxCons,10," << endl;
			file->close();
		}
		return settingsPath;
	}

}

string initClientSettingsPath()
{
	QDir * path = new QDir();
	QFile * file;
	//获得登录用户名
	string username = getUserName().toStdString();
	string settingsPath = "/home/" + username + "/.gmanager";
//	string userInfoPath = "/home/" + username + "/.gmanager";
	if(! path->exists(QString::fromStdString(settingsPath))) {
		if(! path->mkpath(QString::fromStdString(settingsPath))) {
			cout << "mkpath error!" << endl;
			return "false";
		}
		else {
			settingsPath += "/clientSettings.csv";
//			userInfoPath += "/userInfo.csv";
			file = new QFile(QString::fromStdString(settingsPath));
			if(! file->exists()) {
				if(! file->open(QIODevice::ReadWrite | QIODevice::Text)) {
					qDebug() << "Can't create the file!" << endl;
					return "false";
				}
				QTextStream stream(file);
				stream << "MasterIp,192.168.1.107,\nMasterPort,36688,\nThisIp," << getIpAddress() << ",\nThisPort,1668," << endl;
				file->close();
			}
			else {
				setStringValue(settingsPath, "ThisIp", 1, getIpAddress().toStdString());
			}
			return settingsPath;
		}
	}
	else {
		settingsPath += "/clientSettings.csv";
//		userInfoPath += "/userInfo.csv";
		file = new QFile(QString::fromStdString(settingsPath));
		if(! file->exists()) {
			if(! file->open(QIODevice::ReadWrite | QIODevice::Text)) {
				qDebug() << "Can't create the file!" << endl;
				return "false";
			}
			QTextStream stream(file);
			stream << "MasterIp,192.168.1.107,\nMasterPort,36688,\nThisIp," << getIpAddress() << ",\nThisPort,1668," << endl;
			file->close();
		}
		else {
			setStringValue(settingsPath, "ThisIp", 1, getIpAddress().toStdString());
		}
		return settingsPath;
	}

}

string initUserInfoPath()
{
	QDir * path = new QDir();
	QFile * file;
	//获得登录用户名
	string username = getUserName().toStdString();
//	string settingsPath = "/home/" + username + "/.gmanager";
	string userInfoPath = "/home/" + username + "/.gmanager";
	if(! path->exists(QString::fromStdString(userInfoPath))) {
		if(! path->mkpath(QString::fromStdString(userInfoPath))) {
			cout << "mkpath error!" << endl;
			return "false";
		}
		else {
//			settingsPath += "/settings.csv";
			userInfoPath += "/userInfo.csv";
			file = new QFile(QString::fromStdString(userInfoPath));
			if(! file->exists()) {
				if(! file->open(QIODevice::ReadWrite | QIODevice::Text)) {
					qDebug() << "Can't create the file!" << endl;
					return "false";
				}
				file->close();
			}
			return userInfoPath;
		}
	}
	else {
//		settingsPath += "/settings.csv";
		userInfoPath += "/userInfo.csv";
		file = new QFile(QString::fromStdString(userInfoPath));
		if(! file->exists()) {
			if(! file->open(QIODevice::ReadWrite | QIODevice::Text)) {
				qDebug() << "Can't create the file!" << endl;
				return "false";
			}
			file->close();
		}
		return userInfoPath;
	}

}

string initServerInfoPath()
{
	QDir * path = new QDir();
	QFile * file;
	//获得登录用户名
	string username = getUserName().toStdString();
//	string settingsPath = "/home/" + username + "/.gmanager";
	string serverInfoPath = "/home/" + username + "/.gmanager";
	if(! path->exists(QString::fromStdString(serverInfoPath))) {
		if(! path->mkpath(QString::fromStdString(serverInfoPath))) {
			cout << "mkpath error!" << endl;
			return "false";
		}
		else {
//			settingsPath += "/settings.csv";
			serverInfoPath += "/serverInfo.csv";
			file = new QFile(QString::fromStdString(serverInfoPath));
			if(! file->exists()) {
				if(! file->open(QIODevice::ReadWrite | QIODevice::Text)) {
					qDebug() << "Can't create the file!" << endl;
					return "false";
				}
				file->close();
			}
			return serverInfoPath;
		}
	}
	else {
//		settingsPath += "/settings.csv";
		serverInfoPath += "/serverInfo.csv";
		file = new QFile(QString::fromStdString(serverInfoPath));
		if(! file->exists()) {
			if(! file->open(QIODevice::ReadWrite | QIODevice::Text)) {
				qDebug() << "Can't create the file!" << endl;
				return "false";
			}
			file->close();
		}
		return serverInfoPath;
	}

}

string initTaskInfoPath()
{
	QDir * path = new QDir();
	QFile * file;
	//获得登录用户名
	string username = getUserName().toStdString();
//	string settingsPath = "/home/" + username + "/.gmanager";
	string taskInfoPath = "/home/" + username + "/.gmanager";
	if(! path->exists(QString::fromStdString(taskInfoPath))) {
		if(! path->mkpath(QString::fromStdString(taskInfoPath))) {
			cout << "mkpath error!" << endl;
			return "false";
		}
		else {
//			settingsPath += "/settings.csv";
			taskInfoPath += "/taskInfo.csv";
			file = new QFile(QString::fromStdString(taskInfoPath));
			if(! file->exists()) {
				if(! file->open(QIODevice::ReadWrite | QIODevice::Text)) {
					qDebug() << "Can't create the file!" << endl;
					return "false";
				}
				file->close();
			}
			return taskInfoPath;
		}
	}
	else {
//		settingsPath += "/settings.csv";
		taskInfoPath += "/taskInfo.csv";
		file = new QFile(QString::fromStdString(taskInfoPath));
		if(! file->exists()) {
			if(! file->open(QIODevice::ReadWrite | QIODevice::Text)) {
				qDebug() << "Can't create the file!" << endl;
				return "false";
			}
			file->close();
		}
		return taskInfoPath;
	}

}

/*
int main()
{
	bool status = deleteInfoFromCsv(csvfp, "a1");
	if(status)
	{
		vector<vector<string>> context = readCsv(csvfp);
		for(auto row:context)
			for(auto field:row)
				cout<<field<<endl;
	}
	return 0;

}
*/
