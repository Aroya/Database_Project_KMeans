

#include"lib\Reader.h"
#include"lib\KMeansHelper.h"
#include"lib\KMeans.h"

using namespace std;

int main() {
	AroyaReader reader;
	reader.read("example\\test.csv");

	AroyaKMeansHelper KMeansHelper;
	KMeansHelper.insert(reader, "x");
	KMeansHelper.insert(reader, "y");

	AroyaKMeans KMeans;
	KMeans.setClusters(2);
	KMeans.setData(KMeansHelper.getData());
	KMeans.run();
	KMeans.writeFile("output.csv");
	KMeans.writeCentre("centre.csv");


	//AroyaReader reader;
	//reader.read(please input filename);

	//AroyaKMeansHelper KMeansHelper;
	//KMeansHelper.insert(reader, "start station latitude", "latitude");
	//KMeansHelper.insert(reader, "start station longitude", "longitude");
	//KMeansHelper.insert(reader, "end station latitude", "latitude");
	//KMeansHelper.insert(reader, "end station longitude", "longitude");

	//AroyaKMeans KMeans;
	//KMeans.setClusters(30);
	//KMeans.setData(KMeansHelper.getData());
	//KMeans.run();
	//KMeans.writeFile("output.csv");
	//KMeans.writeCentre("centre.csv");
	//system("pause");
	return 0;
}