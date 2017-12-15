

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
	KMeans.writeFile("example.csv");

	system("pause");
	return 0;
}