#include"KMeans.h"

AroyaKMeans::AroyaKMeans() {
	//nothing to do yet
	bord = 0.05;
}

void AroyaKMeans::setClusters(const int&clusters_) {
	clusters = clusters_;
	centre.clear();
	vector<double>empty;
	for (int i = 0; i < clusters; i++)centre.push_back(empty);
}
void AroyaKMeans::setData(const vector<vector<double>>&yourData) {
	data.clear();
	data = yourData;
	rows = data.size();
	columns = data[0].size();
	cluster = new int[rows];
}

void AroyaKMeans::run() {
	int i, j, k;
	double min;
	int changed = rows;
	//设置初始聚类点
	for (i = 0; i < clusters; i++) {
		for (j = 0; j < columns; j++) {
			centre[i].push_back(data[i][j]);
		}
	}
	//分配空间
	distance = new double*[clusters];
	for (i = 0; i < clusters; i++)distance[i] = new double[rows];

	double *thisCluster = new double[clusters];

	//开始聚类
	//小于bord的点变化则收敛
	while (double(changed) / double(rows) < bord) {
		changed = 0;

		//初始化空间
		for (i = 0; i < clusters; i++) {
			for (j = 0; j < rows; j++) {
				distance[i][j] = 0;
			}
			thisCluster[i] = 0;
		}

		//先计算所有距离
		for (i = 0; i < clusters; i++) {
			for (j = 0; j < rows; j++) {
				for (k = 0; k < columns; k++) {
					distance[i][j] += pow(centre[i][k] - data[j][k], 2);
				}
			}
		}

		//清除聚类点
		for (i = 0; i < clusters; i++) {
			for (j = 0; j < columns; j++) {
				centre[i][j] = 0;
			}
		}

		//寻找最短路径 并记录
		for (i = 0; i < rows; i++) {
			cluster[i] = 0;
			min = distance[0][i];
			k = 0;
			for (j = 1; j < clusters; j++) {
				if (distance[j][i] < min) {
					min = distance[j][i];
					k = j;
				}
			}
			if (cluster[i] != k)changed++;
			cluster[i] = k;
			for (j = 0; j < columns; j++) {
				centre[k][j] += centre[i][j];
			}
			thisCluster[k]++;
		}

		//得到新质心
		for (i = 0; i < clusters; i++) {
			k = thisCluster[i];
			for (j = 0; j < columns; j++) {
				centre[i][j] /= k;
			}
		}
	}

	//清除空间
	for (i = 0; i < clusters; i++)delete[]distance[i];
	delete[]distance;
	delete[]thisCluster;
}
void AroyaKMeans::setBord(const double&t) {
	bord = t;
}

void AroyaKMeans::writeFile(const char*fileName) {
	ofstream fout;
	fout.open(fileName);
	for (int i = 0; i < rows; i++) {
		fout << cluster[i] << endl;
	}
	fout.close();
}