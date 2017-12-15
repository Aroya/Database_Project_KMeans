#ifndef AROYA_KMEANS
#define AROYA_KMEANS

class aroyaKMeans {
public:
	aroyaKMeans();
	void setClusters(const int&clusters);					//���þ������
	void setData(const vector<vector<double>>&yourData);	//��reader������Ϣ
	void run();												//���о���
	void setBord(const double&newBord);						//������������
	void writeFile(const char*fileName);										//�������д���ļ�
private:
	vector<vector<double>>data;		//data
	int*cluster;					//ָ��data���ڵ�centre
	vector<vector<double>>centre;	//����
	double **distance;				//data�����ĵľ���
	int dataLength, dataDimension, clusters;
	double bord;					//Ĭ��5%���µı仯ʱ������
};


#endif