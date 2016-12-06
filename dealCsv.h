#ifndef _DEALCSV_H_
#define _DEALCSV_H_

#include "utils.h"
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <string>
#include <vector>
#include <limits>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace::std;

vector<vector<string>> readCsv(string filePath);
string getCsvValue(string filePath, int row, int col);
bool setCsvValue(string filePath, int row, int col, string setValue);
bool appendInfoToCsv(string filePath, string info);
bool deleteInfoFromCsv(string filePath, string keyword);
bool isRecordExisting(string filePath, string keyword);
int getIntValue(string filePath, string keyword, int location);
string getStringValue(string filePath, string keyword, int location);
bool setStringValue(string filePath, string keyword, int location, string setValue);
bool initCsv(string filePath);
string initMasterSettingsPath();
string initClientSettingsPath();
string initUserInfoPath();
string initServerInfoPath();
string initTaskInfoPath();

#endif
