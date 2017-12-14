#include"KMeans.h"
#include<vector>
#include<cmath>
using namespace std;

aroyaKMeans::aroyaKMeans() {
	//nothing to do yet
}

void aroyaKMeans::setClusters(const int&clusters_) {
	clusters = clusters_;
	centre.clear();
	vector<double>empty;
	for (int i = 0; i < clusters; i++)centre.push_back(empty);
}
void aroyaKMeans::setData(const vector<vector<double>>&yourData) {
	data.clear();
	data = yourData;
	dataLength = data.size();
	dataDimension = data[0].size();
}

void aroyaKMeans::cluster() {
	int i, j;
	//设置初始聚类点
	for (i = 0; i < clusters; i++) {
		for (j = 0; j < dataDimension; j++) {
			centre[i][j] = data[i][j];
		}
	}
	//分配空间
	distance = new double*[clusters];
	for (i = 0; i < clusters; i++)distance[i] = new double[dataLength];
	//初始化空间
	for (i = 0; i < clusters; i++) {
		for (j = 0; j < dataLength; j++) {
			distance[i][j] = 0;
		}
	}

	//开始聚类

	//清除空间
	for (i = 0; i < clusters; i++)delete[]distance[i];
	delete[]distance;
}