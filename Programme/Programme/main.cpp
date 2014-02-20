#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "extract_data.h"
#include "Network.h"
#include "EasyBMP.h" // external library using namespace std;

int main(){
	//data test0("\\Users\\Bouxtehouve\\Dropbox\\C++ Neural Network\\data");
	// direction path, with double \\;
	//cout << test0.output_bmp(1258)<< endl;
	std::vector<unsigned> archi;
	cout << "cc1" << endl;
	archi.push_back(2);
	cout << "cc2" << endl;
	archi.push_back(2);
	cout << "cc3" << endl;
	archi.push_back(1);
	cout << "cc4" << endl;
	double eta = 0.5;
	cout << "cc5" << endl;
	double alpha = 0.5;
	cout << "cc6" << endl;
	Network rdn(eta, alpha, TAN, archi);
	cout << "cc7" << endl;
	std::vector<double> input(2);
	cout << "cc8" << endl;
	input.push_back(3.5);
	cout << "cc9" << endl;
	input.push_back(2.9);
	cout << "cc10" << endl;
	std::vector<double> output(1);
	cout << "cc11" << endl;
	output.push_back(6.7);
	cout << "cc12" << endl;
	rdn.feedForwardNetwork(input);
	cout << "cc13" << endl;
	rdn.singleTraining(input, output);
	cout << "cc14" << endl;
}
