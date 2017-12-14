#ifndef	AROYA_READER
#define AROYA_READER

class aroyaReader {
private:
	vector<vector<string>>data;		//ȫ����string�ݴ�
	stringstream internalSst;	//ת��ʹ��
public:
	aroyaReader();
	void read(const char*fileName);
	string getStringData(const char&rows, const char&columns);
	double getDoubleData(const char&rows, const char&columns);
	int findTable(const char*tableName);

};

#endif