#ifndef	Aroya_READER
#define Aroya_READER
#include<string>
#include<vector>
#include<fstream>
#include<iostream>
#include<sstream>

using namespace std;

class AroyaReader {
private:
	vector<vector<string>>data;		//ȫ����string�ݴ�
	stringstream internalSst;		//ת��ʹ��
	int rows, columns;
public:
	AroyaReader();
	void read(const char*fileName);
	string getStringData(const int&rows, const int&columns);
	double getDoubleData(const int&rows, const int&columns);
	int findTable(const char*tableName);
	int getRows();
	int getColumns();
};

#endif