#include"Reader.h"

#include<string>
#include<vector>
#include<fstream>
#include<iostream>
#include<sstream>

using namespace std;

aroyaReader::aroyaReader() {
	//nothing to do yet
}

void aroyaReader::read(const char*fileName) {
	ifstream fin;
	fin.open(fileName);
	if (!fin.is_open()) {
		cout << "aroyaReader:read() cannot open file!\n";
		system("pause");
	}
	char reading;
	string buffer;
	bool didntInit = true;
	vector<string>emptyVector;
	int nowPoint = 0;
	while (fin.good() && (reading = fin.get()) != -1) {
		//数据结束 处理数据
		if (reading == ','|| reading == '\n') {
			if (didntInit) {					//init this row
				data.push_back(emptyVector);
				didntInit = false;
			}
			data[nowPoint].push_back(buffer);	//put data to this row

			buffer.clear();						//clear buffer
			if (reading == '\n') {				//next row
				nowPoint++;	
				didntInit = true;
			}
		}
		//无分隔符 记录数据
		else {
			buffer.push_back(reading);
		}
	}
	fin.close();
}

string aroyaReader::getStringData(const char&rows, const char&columns) {
	return data[rows][columns];
}

double aroyaReader::getDoubleData(const char&rows, const char&columns) {
	internalSst.clear();
	internalSst << data[rows][columns];
	double temp;
	internalSst >> temp;
	return temp;
}

int aroyaReader::findTable(const char*tableName) {
	int tables = data[0].size();
	for (int i = 0; i < tables; i++) {
		if (data[0][i] == tableName)return i;
	}
	return -1;
}