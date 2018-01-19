#ifndef Aroya_READER_HELPER
#define Aroya_READER_HELPER

#include<vector>
#include<fstream>
using namespace std;
#include"Reader.h"

class AroyaReaderHelper {
public:
	AroyaReaderHelper();
	//clear reader
	void clear();
	//insert table
	//if not input myTableName, will set it as same as tableName
	void insert(AroyaReader&reader, const char*tableName, const char*myTableName=nullptr);
	//insert by column position
	void insert(AroyaReader&reader, const int&col);
	//delete table
	bool erase(const char*tableName);
	
	//��һ��
	void normalization();
	//д������
	void writeFile(const char*fileName);

	//get
	int getRows();
	int getColumns();

	//��ȡ����table
	//Ĭ��0�����ȶ�ȡ
	//1Ϊ�����ȶ�ȡ
	vector<vector<double>> getData(int dataType=0);
	//for bpnn to load
	double** getDataPointer();

	//��¼table
	void saveTable(const char*fileName);
	//����Ϊ��¼��table˳��
	void transformTable(const char*fileName);
private:
	int findTable(const char*tableName);
	vector<string>table;
	vector<vector<double>>buffer;
	vector<double>empty;
};



#endif