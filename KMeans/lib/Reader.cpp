#include"Reader.h"

AroyaReader::AroyaReader() {
	//nothing to do yet
}

void AroyaReader::read(const char*fileName) {
	ifstream fin;
	fin.open(fileName);
	if (!fin.is_open()) {
		cout << "AroyaReader:read() cannot open file!\n";
		system("pause");
	}
	char reading;
	string buffer;
	bool didntInit = true;
	vector<string>emptyVector;
	int nowPoint = 0;
	while (fin.good() && (reading = fin.get()) != -1) {
		//���ݽ��� ��������
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
		//�޷ָ��� ��¼����
		else {
			buffer.push_back(reading);
		}
	}
	fin.close();
	rows = data.size();
	columns = data[0].size();
}

string AroyaReader::getStringData(const int&rows, const int&columns) {
	return data[rows][columns];
}

double AroyaReader::getDoubleData(const int&rows, const int&columns) {
	internalSst.str("");
	internalSst.clear();
	internalSst << data[rows][columns];
	double temp;
	internalSst >> temp;
	return temp;
}

int AroyaReader::findTable(const char*tableName) {
	int tables = data[0].size();
	for (int i = 0; i < tables; i++) {
		if (data[0][i] == tableName)return i;
	}
	return -1;
}
int AroyaReader::getRows() { return rows; }
int AroyaReader::getColumns() { return columns; }