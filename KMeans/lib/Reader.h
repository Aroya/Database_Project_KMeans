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
public:
	AroyaReader();
	void read(const char*fileName);
	//clear data
	void clear();
	string getStringData(const int&rows, const int&columns);
	double getDoubleData(const int&rows, const int&columns);
	int findTable(const char*tableName);
	int getRows();
	int getColumns();
	//�趨�е�table(��Ϊ��һ����table����)
	void setTableName(const char*origin, const char*new_);
	//ɾ��ָ����
	void deleteColumn(const int&col);

	//��ֵ����:ɾ����ֵ����ɾ���к���
	void deleteRow(const int&row);
	//ɾ���ض�����
	void deleteRows(const char*TableName, const char*DataType);
};

#endif