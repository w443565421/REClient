#include "utils.h"
#include <QRegExp>
#include <sstream>
#include <iostream>

using namespace::std;

vector<string> split(string rawString, char spliter)
{
	vector<string> result;
	string tmp="";
	for(uint i = 0; i < rawString.length(); i ++)
	{
		if(rawString[i] == spliter){
			result.push_back(tmp);
			tmp = "";
		}
		else
			tmp += rawString[i];
	}
	result.push_back(tmp);
	return result;
}

string join(vector<string> vec, char joiner)
{
	string result = "";
	for(auto str:vec)
		result += str + joiner;
	return result.substr(0, result.length() - 1);
}

bool isValidUsername(QString username)
//判断用户名是否合法
{
	QString pattern = "[A-Za-z]+[_A-Za-z0-9]*";
	QRegExp usernameRegExp = QRegExp(pattern);
	return usernameRegExp.exactMatch(username);
}

bool isValidV4IP(string ip)
//判断IP是否为合法的IPV4地址
{
	struct in_addr addr;
	int result = inet_aton(ip.c_str(), & addr);
	if(result != 0) {
		vector<string> content = split(ip, '.');
		if(content.size() == 4) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

bool isANumber(string str)
//判断字符串是否为一个整数
{
	struct in_addr addr;
	int result = inet_aton(str.c_str(), & addr);
	if(result != 0) {
		vector<string> content = split(str, '.');
		if(content.size() == 1) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

int aton(string a)
//string转为int，若不是整数，返回NaN
{
	if(isANumber(a)) {
		stringstream ss;
		ss.str(a);
		int n;
		ss >> n;
		return n;
	}
	else {
		cout << "Not a number." << endl;
		typedef std::numeric_limits<double> Info;
		double const nan = Info::quiet_NaN();
		return nan;
	}
}

string ntoa(int n)
{
	stringstream ss;
	ss << n;
	string a = ss.str();
	return a;
}

string getFilenameFromPath(string filePath)
{
	vector<string> content = split(filePath, '/');
	return content[content.size() - 1];
}
