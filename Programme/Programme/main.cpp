#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "extract_data.h"
#include "Network.h"
#include "EasyBMP.h" // external library using namespace std; using namespace std;

int main(){
	gestion_data data0;
	cout << data0.get_path() << endl;
	cout << __FILE__ << endl;
	string path;
	path = __FILE__;
	size_t std = path.find_last_of('\\');
	printf("%zu",std);
	cout<<"PINGAS"<<endl;
	cout << path.size() << endl;
	//vector<unsigned> archi;
	//archi.push_back(784);
	//archi.push_back(30000);
	//archi.push_back(10);
	//double eta = 0.2;
	//double alpha = 0.5;
	//Network rdn(eta, alpha, TAN, archi);
	//gestion_data dta;
	//vector<vector<double> > tst = dta.images_data("train");
	//double x = dta.output_bmp(0);
	//cout<<"YES"<<x<<endl;
	//rdn.data_training();
	//cout << "cc7" << endl;
	//vector<double> input(2);
	//input.push_back(3.5);
	//cout << "cc9" << endl;
	//input.push_back(2.9);
	//cout << "cc10" << endl;
	//vector<double> output(1);
	//output.push_back(6.7);
	//cout << "cc12" << endl;
	//rdn.feedForwardNetwork(input);
	//cout << "cc13" << endl;
	//rdn.singleTraining(input, output);
	//cout << "cc14" << endl;
}
