#ifndef Aroya_KMEANS
#define Aroya_KMEANS

#include<iostream>
#include<vector>
#include<cmath>
#include<fstream>
using namespace std;

//#define AROYA_DEBUG

class AroyaKMeans {
public:
	AroyaKMeans();
	void setClusters(const int&clusters);					//���þ������
	void setData(const vector<vector<double>>&yourData);	//��reader������Ϣ
	void run();												//���о���
	void setBord(const double&newBord);						//������������
	void writeFile(const char*fileName);					//�������д���ļ�

	//����:һ��Ϊһ������;��Ϊά��
	vector<vector<double>> getCentre();						//��ȡ����
	void writeCentre(const char*fileName);					//������Ϣд���ļ�
private:
	vector<vector<double>>data;		//data
	int*cluster;					//ָ��data���ڵ�centre
	vector<vector<double>>centre;	//����
	double **distance;				//data�����ĵľ���
	int rows, columns, clusters;
	double bord;					//Ĭ��5%���µı仯ʱ������
};


#endif