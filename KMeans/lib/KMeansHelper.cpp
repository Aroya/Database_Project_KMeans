#include"KMeansHelper.h"

AroyaKMeansHelper::AroyaKMeansHelper() {
	//nothing to do yet
}

//insert table
void AroyaKMeansHelper::insert(AroyaReader&reader, const char*tableName, const char*myTableName) {
	if (myTableName == nullptr)myTableName = tableName;
	int t = reader.findTable(tableName);	//find table index
	int length = reader.getRows();			//get data size
	int myPosition = findTable(myTableName);//find myTableName index

	if (myPosition < 0) {					//not found create new table
		myPosition = buffer.size();			//point to end of buffer
		buffer.push_back(empty);			//new buffer
		table.push_back(myTableName);		//new table
	}

	for (int i = 0; i < length; i++) {		//push to buffer
		buffer[myPosition].push_back(reader.getDoubleData(i, t));
	}
}
int AroyaKMeansHelper::findTable(const char*tableName) {
	int i, j;
	i = table.size();
	for (j = 0; j < i; j++) {
		if (table[j] == tableName)return j;
	}
	return -1;
}

vector<vector<double>> AroyaKMeansHelper::getData() {
	return buffer;
}