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
	//���ó�ʼ�����
	for (i = 0; i < clusters; i++) {
		for (j = 0; j < dataDimension; j++) {
			centre[i][j] = data[i][j];
		}
	}
	//����ռ�
	distance = new double*[clusters];
	for (i = 0; i < clusters; i++)distance[i] = new double[dataLength];
	//��ʼ���ռ�
	for (i = 0; i < clusters; i++) {
		for (j = 0; j < dataLength; j++) {
			distance[i][j] = 0;
		}
	}

	//��ʼ����

	//����ռ�
	for (i = 0; i < clusters; i++)delete[]distance[i];
	delete[]distance;
}