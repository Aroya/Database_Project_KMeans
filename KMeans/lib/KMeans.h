#ifndef AROYA_KMEANS
#define AROYA_KMEANS

class aroyaKMeans {
public:
	aroyaKMeans();
	void setClusters(const int&clusters);
	void setData(const vector<vector<double>>&yourData);
	void cluster();
private:
	vector<vector<double>>data;
	vector<int>cluster;
	vector<vector<double>>centre;
	double **distance;
	int dataLength, dataDimension, clusters;
};


#endif