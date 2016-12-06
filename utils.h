#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>
#include <QString>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

using namespace::std;

vector<string> split(string rawString, char spliter);
string join(vector<string> vec, char joiner);
bool isValidUsername(QString);
bool isValidV4IP(string server_ip);
bool isANumber(string str);
string ntoa(int);
int aton(string);
string getFilenameFromPath(string filePath);

#endif // UTILS_H
